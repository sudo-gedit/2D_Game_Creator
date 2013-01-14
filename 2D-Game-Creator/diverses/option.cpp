#include "option.h"
#include "ui_option.h"

Option::Option(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Option)
{
    ui->setupUi(this);
    laden_sprache();
}

Option::~Option()
{
    delete ui;
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

void Option::on_pushButton_sprache_speichern_clicked()
{
    QString  path_config_app = QApplication::applicationDirPath() + "/config.ini";

    QSettings *settings = new QSettings(path_config_app,QSettings::IniFormat);
    settings->beginGroup("config");
        settings->setValue("sprache", ui->comboBox_sprache->currentText());
    settings->endGroup();

    laden_sprache();
}
