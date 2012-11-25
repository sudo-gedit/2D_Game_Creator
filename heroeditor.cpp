//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Hero Editor version 0.01.2.1
//
//
//
// Letzte Aenderung 24.11.2012
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "heroeditor.h"
#include "ui_heroeditor.h"
#include "heroeditor_core.cpp"


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
    ui->lineEdit_Intelligenz->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
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

void HeroEditor::on_okay_clicked()

{
    speichern_char();
}

void HeroEditor::on_gesicht_clicked()

{
    objekt = "gesicht_";
    char_pic_speichern(objekt);
}

void HeroEditor::on_Koerper_clicked()

{
    objekt = "koerper_";
    char_pic_speichern(objekt);
}

void HeroEditor::on_pushButton_held_neu_clicked()

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
//
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
                qDebug() << qlistwidgetitem_convert;
                QString qlistwidgetitem_convert_qstring = qlistwidgetitem_convert.at(0);
                qDebug() << qlistwidgetitem_convert;
                QSettings *loeschen = new QSettings(path_char,QSettings::IniFormat);
                loeschen->remove (qlistwidgetitem_convert_qstring);
                delete item;
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
    QString Intelligenz = settings->value("Intelligenz").toString();

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
   // ui->lineEdit_name->setText(name);
    ui->lineEdit_Leben->setText(leben);
    ui->lineEdit_Mana->setText(mana);
    ui->lineEdit_Kraft->setText(kraft);
    ui->lineEdit_ausdauer->setText(ausdauer);
    ui->lineEdit_Intelligenz->setText(Intelligenz);

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
