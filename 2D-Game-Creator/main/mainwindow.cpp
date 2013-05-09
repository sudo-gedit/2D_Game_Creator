//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "mainwindow.h"
#include "ui_mainwindow.h"

//Globale Variablen
int editor_main_tab;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("2D Game Creator[*]"));
    laden_sprache();
    ui->menuBar->setContextMenuPolicy (Qt::PreventContextMenu);
    ui->mainToolBar->setContextMenuPolicy (Qt::PreventContextMenu);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionEinstellungen_Settings_2_triggered()
{
    Option mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("Option / settings");
    mDialog.setModal(true);
            mDialog.exec();
}

void MainWindow::on_actionEinstellungen_Settings_triggered()
{
    Option mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("Option / settings");
    mDialog.setModal(true);
            mDialog.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    About mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("About");
    mDialog.setModal(true);
            mDialog.exec();
}

void MainWindow::on_actionHero_Editor_triggered()
{
    editor_main_tab = 0;
    Main_Editor *mDialog = new Main_Editor();
    mDialog->setWindowTitle("Editor");
        mDialog->show();
}

void MainWindow::on_actionGegner_Editor_triggered()
{
    editor_main_tab = 1;
    Main_Editor *mDialog = new Main_Editor();
    mDialog->setWindowTitle("Editor");
        mDialog->show();
}

void MainWindow::on_actionKlassen_Editor_triggered()
{
    editor_main_tab = 2;
    Main_Editor *mDialog = new Main_Editor();
    mDialog->setWindowTitle("Editor");
        mDialog->show();
}

void MainWindow::on_actionAusr_stungs_Editor_triggered()
{
    editor_main_tab = 3;
    Main_Editor *mDialog = new Main_Editor();
    mDialog->setWindowTitle("Editor");
        mDialog->show();
}

void MainWindow::on_actionFaehigkeiten_Editor_triggered()
{
    editor_main_tab = 4;
    Main_Editor *mDialog = new Main_Editor();
    mDialog->setWindowTitle("Editor");
        mDialog->show();
}

void MainWindow::on_actionGegenstand_Editor_triggered()
{
    editor_main_tab = 5;
    Main_Editor *mDialog = new Main_Editor();
    mDialog->setWindowTitle("Editor");
        mDialog->show();
}

void MainWindow::on_actionEffekt_Editor_triggered()
{
    editor_main_tab = 6;
    Main_Editor *mDialog = new Main_Editor();
    mDialog->setWindowTitle("Editor");
        mDialog->show();
}

void MainWindow::on_actionKampf_Editor_triggered()
{
    editor_main_tab = 7;
    Main_Editor *mDialog = new Main_Editor();
    mDialog->setWindowTitle("Editor");
        mDialog->show();
}

void MainWindow::on_actionEntwicklungsplanner_triggered()
{
    editor_main_tab = 8;
    Main_Editor *mDialog = new Main_Editor();
    mDialog->setWindowTitle("Editor");
        mDialog->show();
}

void MainWindow::laden_sprache()
//Funktion um eine Sprache zu laden aus der .ini und gleich zu benutzen
{
    QTranslator language;
    QString sprache;
    QString path_config_app = QApplication::applicationDirPath() + "/config.ini";

    QSettings *settings = new QSettings (path_config_app, QSettings::IniFormat, this);
    settings->beginGroup("config");
        sprache = settings->value("sprache").toString();
    settings->endGroup();

    if (sprache == "Deutsch/German" || NULL)
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

void MainWindow::on_actionKampfsimulation_triggered()
{
    Kampfsimulator mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("Kampf Vorbereitung");
    mDialog.setModal(true);
            mDialog.exec();
}
