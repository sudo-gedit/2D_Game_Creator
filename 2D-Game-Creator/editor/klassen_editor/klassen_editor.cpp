#include "klassen_editor.h"
#include "ui_klassen_editor.h"

Klassen_Editor::Klassen_Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Klassen_Editor)
{
    ui->setupUi(this);
    laden_sprache();
}

Klassen_Editor::~Klassen_Editor()
{
    delete ui;
}

//Funktion um eine Sprache zu laden aus der .ini und gleich zu benutzen
void Klassen_Editor::laden_sprache()
{
    QTranslator language;
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
