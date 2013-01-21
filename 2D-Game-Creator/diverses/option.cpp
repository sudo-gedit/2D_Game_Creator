//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//
// Letzte aenderung 20.01.2013
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "option.h"
#include "ui_option.h"


Option::Option(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Option)
{
    ui->setupUi(this);
    laden_sprache();
    lade_sprache_in_comboBox();
}

Option::~Option()
{
    delete ui;
}

// Eingestellte Sprache in die comboBox laden
// noch nicht fertig muss noch fertig gestellt werden
void Option::lade_sprache_in_comboBox()
{
    QString sprache;
    QString path_config_app = QApplication::applicationDirPath() + "/config.ini";

    QSettings *settings = new QSettings (path_config_app, QSettings::IniFormat, this);
    settings->beginGroup("config");
        sprache = settings->value("sprache").toString();
    settings->endGroup();

    if (sprache == "Deutsch/German")
    {
       // int wert = 1;
       // ui->comboBox_sprache->    //("Deutsch/German");
    }

    if (sprache == "Englisch/English")
    {
       // ui->comboBox_sprache->setItemText("Englisch/English");
    }

    if (sprache == "Russisch/Russia")
    {
        //ui->comboBox_sprache->setItemText("Russisch/Russia");
    }

    if (sprache == "Franzoesisch/French")
    {
        //ui->comboBox_sprache->setItemText("Franzoesisch/French");
    }

}

//Funktion um eine Sprache zu laden aus der .ini und gleich zu benutzen
void Option::laden_sprache()
{
    QString sprache;
    QString path_config_app = QApplication::applicationDirPath() + "/config.ini";

    QSettings *settings = new QSettings (path_config_app, QSettings::IniFormat, this);
    settings->beginGroup("config");
        sprache = settings->value("sprache").toString();
    settings->endGroup();

    if (sprache == "Deutsch/German")
    {
        language.load("german_DE");
        qApp->installTranslator(&language);
        ui->retranslateUi(this);
    }

    if (sprache == "Englisch/English")
    {
        language.load("english_UK");
        qApp->installTranslator(&language);
        ui->retranslateUi(this);
    }

    if (sprache == "Russisch/Russia")
    {
        language.load("russia_RUS");
        qApp->installTranslator(&language);
        ui->retranslateUi(this);
    }

    if (sprache == "Franzoesisch/French")
    {
        language.load("french_FRA");
        qApp->installTranslator(&language);
        ui->retranslateUi(this);
    }
}
// Eingestellte Sprache Speichern
void Option::on_pushButton_sprache_speichern_clicked()
{
    QString  path_config_app = QApplication::applicationDirPath() + "/config.ini";

    QSettings *settings = new QSettings(path_config_app,QSettings::IniFormat);
    settings->beginGroup("config");
        settings->setValue("sprache", ui->comboBox_sprache->currentText());
    settings->endGroup();

    laden_sprache();
    lade_sprache_in_comboBox();

    QMessageBox::critical(this, "Achtung", "Es ist notwendig die Anwendung \n neuzustarten.", QMessageBox::Ok);
}

