#include "monster_editor.h"
#include "ui_monster_editor.h"


void Monster_Editor::speichern_char()
// Werte von dem gewaellten Charakter speichern
{
    //Lineedit Speiern
    QSettings *settings = new QSettings(path_char,QSettings::IniFormat);
    settings->beginGroup(ui->lineEdit_name->text());

    settings->setValue("name",  ui->lineEdit_name->text());
    settings->setValue("leben", ui->lineEdit_Leben->text());
    settings->setValue("mana",  ui->lineEdit_Mana->text());
    settings->setValue("kraft", ui->lineEdit_Kraft->text());
    settings->setValue("ausdauer", ui->lineEdit_ausdauer->text());
    settings->setValue("intelligenz", ui->lineEdit_intelligenz->text());
    settings->setValue("verteidigung", ui->lineEdit_verteidigung->text());
    settings->setValue("glueck", ui->lineEdit_glueck->text());

    //Checkbox Speichern
    settings->setValue("feuer", ui->checkBox_feuer->checkState());
    settings->setValue("eis",   ui->checkBox_eis->checkState());
    settings->setValue("betaeubt", ui->checkBox_betaeubt->checkState());
    settings->setValue("gift",  ui->checkBox_gift->checkState());
    settings->setValue("wind", ui->checkBox_wind->checkState());

    //Spinbox Speichern

    settings->setValue("feuer_pro", ui->spinBox_feuer->value());
    settings->setValue("eis_pro", ui->spinBox_eis->value());
    settings->setValue("betaeubt_pro", ui->spinBox_betaeubt->value());
    settings->setValue("gift_pro", ui->spinBox_gift->value());
    settings->setValue("wind_pro", ui->spinBox_wind->value());


    settings->endGroup();

}

void Monster_Editor::char_pic_speichern(QString objekt)
// Speichern der Bild adresse in die ini
{
    QString format = ".jpg"; //Workaround
    QString name_held = ui->listWidget_monster->currentItem()->text();


    //// verbessern (if?)
    QDir mdir;
    QString mpath = QApplication::applicationDirPath() + "/game/res/";
    mdir.mkpath(mpath);

    //Auswahl Bild für Gesicht und Auto Entfernung des alten Bildes
    QString path_objekt_open = QFileDialog::getOpenFileName(this, tr("Avatar Bild waehlen"), "", tr("Images  (*.png *.xpm *.jpg)"));
    QFile::remove(path_res + objekt + name_held + format);
    QFile::copy ( path_objekt_open, path_res + objekt + name_held + format);

    //Darstellung in GraphicsView
    QImage image( path_res + objekt + name_held + format );
    image = image.scaled(this->ui->graphicsView_gesicht->width()-10,ui->graphicsView_gesicht->height()-10);
    QGraphicsScene *objekt_qgs = new QGraphicsScene();
    objekt_qgs->addPixmap(QPixmap::fromImage(image));

    if (objekt == "gesicht_")

    {
        ui->graphicsView_gesicht->setScene(objekt_qgs);
    }

    else

    {
        ui->graphicsView_koerper->setScene(objekt_qgs);
    }

    QSettings *objekt_qsettings_speichern_pic = new QSettings(path_char,QSettings::IniFormat);
        objekt_qsettings_speichern_pic->beginGroup(name_held);
        objekt_qsettings_speichern_pic->setValue(objekt, "/game/res/" + objekt + name_held + format);
        objekt_qsettings_speichern_pic->endGroup();

}

void Monster_Editor::qlist_namen_laden()
// Helden werden aus der ini in qlistWidget_helden geladen
{
    QSettings settings (path_char, QSettings::IniFormat);
    QStringList group = settings.childGroups();
    for(int child = 0; child != group.size(); ++child)

    {
            QString childVersion = group.at(child);
            ui->listWidget_monster->addItem(childVersion);
    }

}

void Monster_Editor::on_lineEdit_name_editingFinished()
// Bearbeitung des gewählten Helden's
{
    if    (ui->listWidget_monster->currentItem() == 0) {

            QMessageBox::critical(this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);

           }
    else

    {
     //variablen sind zu lang!!!
    QListWidgetItem *item = ui->listWidget_monster->currentItem();
    QStringList qlistwidgetitem_convert;
    qlistwidgetitem_convert << item->text();
    QString qlistwidgetitem_convert_qstring = qlistwidgetitem_convert.at(0);

    QString name_vorher = ui->listWidget_monster->currentItem()->text();
    QString name_widget = ui->lineEdit_name->text();
    ui->listWidget_monster->currentItem()->setText(name_widget);


    QSettings *settings = new QSettings(path_char,QSettings::IniFormat);
    settings->remove(qlistwidgetitem_convert_qstring);

    speichern_char();

    }
}

void Monster_Editor::on_listWidget_monster_currentItemChanged()
// Werte von dem gewaellten Charakter laden
{
    //Bevor die neue werte geladen werden, werden die alten gespeichert.
    speichern_char();

    QString helden_name = ui->listWidget_monster->currentItem()->text();
    ui->lineEdit_name->setText(helden_name);


    //Laden der Settings aus der .ini
    QSettings *settings = new QSettings (path_char, QSettings::IniFormat, this);

    settings->beginGroup(helden_name);
    QString leben = settings->value("leben").toString();
    QString mana = settings->value("mana").toString();
    QString kraft = settings->value("kraft").toString();
    QString ausdauer = settings->value("ausdauer").toString();
    QString intelligenz = settings->value("intelligenz").toString();
    QString verteidigung = settings->value("verteidigung").toString();
    QString glueck = settings->value("glueck").toString();

    QString gesicht_ = settings->value("gesicht_").toString();
    QString koerper_ = settings->value("koerper_").toString();


    bool feuer =settings->value("feuer").toBool();
    bool wind = settings->value("wind").toBool();
    bool gift = settings->value("gift").toBool();
    bool betaeubt = settings->value("betaeubt").toBool();
    bool eis = settings->value("eis").toBool();

    int feuer_pro = settings->value("feuer_pro").toInt();
    int eis_pro = settings->value("eis_pro").toInt();
    int betaeubt_pro = settings->value("betaeubt_pro").toInt();
    int gift_pro = settings->value("gift_pro").toInt();
    int wind_pro = settings->value("wind_pro").toInt();


    settings->endGroup();


    //Sttings in die GUI laden (lineedit)
    ui->lineEdit_Leben->setText(leben);
    ui->lineEdit_Mana->setText(mana);
    ui->lineEdit_Kraft->setText(kraft);
    ui->lineEdit_ausdauer->setText(ausdauer);
    ui->lineEdit_intelligenz->setText(intelligenz);
    ui->lineEdit_verteidigung->setText(verteidigung);
    ui->lineEdit_glueck->setText(glueck);

    //Sttings in die GUI laden (checkbox)
    ui->checkBox_feuer->setChecked(feuer);
    ui->checkBox_wind->setChecked(wind);
    ui->checkBox_gift->setChecked(gift);
    ui->checkBox_betaeubt->setChecked(betaeubt);
    ui->checkBox_eis->setChecked(eis);

    ui->spinBox_feuer->setValue(feuer_pro);
    ui->spinBox_eis->setValue(eis_pro);
    ui->spinBox_betaeubt->setValue(betaeubt_pro);
    ui->spinBox_gift->setValue(gift_pro);
    ui->spinBox_wind->setValue(wind_pro);


    path_res_ = QApplication::applicationDirPath() + "";

    QImage image_gesicht(path_res_ + gesicht_);
    image_gesicht = image_gesicht.scaled(this->ui->graphicsView_gesicht->width()-10,this->ui->graphicsView_gesicht->height()-10);
    QGraphicsScene *gesicht = new QGraphicsScene();
    gesicht->addPixmap(QPixmap::fromImage(image_gesicht));
    ui->graphicsView_gesicht->setScene(gesicht);


    QImage image_koerper(path_res_ + koerper_);
    image_koerper = image_koerper.scaled(this->ui->graphicsView_gesicht->width()-10,this->ui->graphicsView_gesicht->height()-10);
    QGraphicsScene *koerper = new QGraphicsScene();
    koerper->addPixmap(QPixmap::fromImage(image_koerper));
    ui->graphicsView_koerper->setScene(koerper);

}
