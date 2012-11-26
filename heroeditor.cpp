//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Hero Editor version 0.01.2.1
//
//
//
// Letzte Aenderung 26.11.2012
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "heroeditor.h"
#include "ui_heroeditor.h"


HeroEditor::HeroEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HeroEditor)

{
    ui->setupUi(this);
    setWindowTitle(tr("Hero Editor[*]"));


    // Umgebungs variabelen
    path_config = QApplication::applicationDirPath() + "/game/config.ini";
    path_char = QApplication::applicationDirPath() + "/game/chars.ini";
    path_res = QApplication::applicationDirPath() + "/game/res/";

    // LineEdit Buchstaben Sperre
    ui->lineEdit_name->setValidator(new QRegExpValidator( QRegExp("[0-9, A-Z, a-z]+"), this ));
    ui->lineEdit_Mana->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_ausdauer->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_intelligenz->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_Kraft->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_Leben->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_verteidigung->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));

    // Funktionen die Geladen werden
    qlist_namen_laden();

}

HeroEditor::~HeroEditor()

{
    delete ui;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////
//Funktionen Start
//////////////////////////////////////////////////////////////////////////////////////////////////////
void HeroEditor::speichern_char()
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

void HeroEditor::char_pic_speichern(QString objekt)
// Speichern der Bild adresse in die ini
{
    QString format = ".jpg"; //Workaround
    QString name_held = ui->listWidget_helden->currentItem()->text();


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

void HeroEditor::qlist_namen_laden()
// Helden werden aus der ini in qlistWidget_helden geladen
{
    QSettings settings (path_char, QSettings::IniFormat);
    QStringList group = settings.childGroups();
    for(int child = 0; child != group.size(); ++child)

    {
            QString childVersion = group.at(child);
            ui->listWidget_helden->addItem(childVersion);
    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//Funktionen Ende
//////////////////////////////////////////////////////////////////////////////////////////////////////

void HeroEditor::on_okay_clicked()
//Funktion um vom gewaellten Helden zu alle Werte zu Speichern (Button)
{
    speichern_char();
}

void HeroEditor::on_gesicht_clicked()
//Funktion um das Gesicht des Helden zu Speichern (laden)
{
    objekt = "gesicht_";
    char_pic_speichern(objekt);
}

void HeroEditor::on_Koerper_clicked()
//Funktion um das Koerper des Helden zu Speichern (laden)
{
    objekt = "koerper_";
    char_pic_speichern(objekt);
}

void HeroEditor::on_pushButton_held_neu_clicked()
//Funktion um einen neuen Helden zu erstellen
{
    //Letzter Zaehler wird geladen, damit bei der Erstellung des nächsten Helden die richtige Nummerierung erstellt werden kann.
    QSettings *zaehler_laden = new QSettings (path_config, QSettings::IniFormat, this);
        zaehler_laden->beginGroup("heroeditor");
        zaehler = zaehler_laden->value("zaehler").toInt();
        zaehler_laden->endGroup();

    //Die erstellung des Helden
    zaehler = zaehler + 1;
    QString zaehler_str;

    zaehler_str.append(QString("%1").arg(zaehler));
    ui->listWidget_helden->addItem("Neuer_Held" + zaehler_str);
    ui->lineEdit_name->setText("Neuer_Held" + zaehler_str);

    QSettings *settings = new QSettings(path_char,QSettings::IniFormat);
        settings->beginGroup("Neuer_Held" + zaehler_str);
        settings->setValue("name",  ui->lineEdit_name->text());
        settings->endGroup();

    //Letzter Zaehler wird gesichert, damit bei der Erstellung des nächsten Helden die richtige Nummerierung erstellt werden kann.
    QSettings *zaehler = new QSettings(path_config,QSettings::IniFormat);
        zaehler->beginGroup("heroeditor");
        zaehler->setValue("zaehler", zaehler_str);
        zaehler->endGroup();


}

void HeroEditor::on_pushButton_held_entfernen_clicked()
//Funktion um den gewaellten Helden zu loeschen (mit Pruefmechanismus)
{
    int count = ui->listWidget_helden->count();

    if (count == 1)
    {
        QMessageBox::critical(this, "Achtung", "Du versuchst den letzten Helden zu loeschen, das ist nicht moeglich.", QMessageBox::Ok);
    }

        else
        {

            if    (ui->listWidget_helden->currentItem() == 0) {

            QMessageBox::critical(this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);

        }
            else
            {
                        QListWidgetItem *item = ui->listWidget_helden->currentItem();
                        QStringList qlistwidgetitem_convert;
                        qlistwidgetitem_convert << item->text();
                        QString qlistwidgetitem_convert_qstring = qlistwidgetitem_convert.at(0);
                        qDebug() << qlistwidgetitem_convert_qstring;

                        //Workaround
                        delete item;
                        //Workaround

                        QSettings *settings = new QSettings(path_char,QSettings::IniFormat);
                        settings->remove (qlistwidgetitem_convert_qstring);

        }
    }
}

void HeroEditor::on_lineEdit_name_editingFinished()
// Bearbeitung des gewählten Helden's
{
    if    (ui->listWidget_helden->currentItem() == 0) {

            QMessageBox::critical(this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);

           }
    else

    {
     //variablen sind zu lang!!!
    QListWidgetItem *item = ui->listWidget_helden->currentItem();
    QStringList qlistwidgetitem_convert;
    qlistwidgetitem_convert << item->text();
    QString qlistwidgetitem_convert_qstring = qlistwidgetitem_convert.at(0);

    QString name_vorher = ui->listWidget_helden->currentItem()->text();
    QString name_widget = ui->lineEdit_name->text();
    ui->listWidget_helden->currentItem()->setText(name_widget);


    QSettings *settings = new QSettings(path_char,QSettings::IniFormat);
    settings->remove(qlistwidgetitem_convert_qstring);

    speichern_char();

    }
}

void HeroEditor::on_listWidget_helden_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
// Werte von dem gewaellten Charakter laden
{
    //Bevor die neue werte geladen werden, werden die alten gespeichert.
    speichern_char();

    QString helden_name = ui->listWidget_helden->currentItem()->text();
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
