//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//
// Letzte aenderung 19.11.2012
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "2D-Game-Creator/editor/effekt_editor/effekt_editor.h"
#include "2D-Game-Creator/editor/entwicklungsplaner/entwicklungsplaner.h"
#include "2D-Game-Creator/editor/faehigkeiten_editor/faehigkeiten_editor.h"
#include "2D-Game-Creator/editor/gegenstand_editor/gegenstand_editor.h"
#include "2D-Game-Creator/editor/hero_editor/hero_editor.h"
#include "2D-Game-Creator/editor/monster_editor/monster_editor.h"
#include "2D-Game-Creator/editor/klassen_editor/klassen_editor.h"
#include "2D-Game-Creator/editor/ausruestungs_editor/ausruestung.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("2D Game Creator[*]"));
}

MainWindow::~MainWindow()
{
    delete ui;
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
    Hero_Editor mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("Hero Editor");
    mDialog.setModal(true);
            mDialog.exec();
}


void MainWindow::on_actionEntwicklungsplanner_triggered()
{
    Entwicklungsplaner mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("Entwicklungsplaner");
    mDialog.setModal(true);
            mDialog.exec();

}

void MainWindow::on_actionMonster_Editor_triggered()
{
    Monster_Editor mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("Monster Editor");
    mDialog.setModal(true);
            mDialog.exec();

}

void MainWindow::on_actionGegenstand_Editor_triggered()
{
    Gegenstand_Editor mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("Gegenstand Editor");
    mDialog.setModal(true);
            mDialog.exec();
}

void MainWindow::on_actionFeahigkeiten_triggered()
{
    Faehigkeiten_Editor mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("Faehigkeiten Editor");
    mDialog.setModal(true);
            mDialog.exec();
}

void MainWindow::on_actionKampfsimulation_triggered()
{
    Kampfsimulation mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("Kampfsimulation");
    mDialog.setModal(true);
            mDialog.exec();
}

void MainWindow::on_actionStatus_Editor_triggered()
{
    Effekt_Editor mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("Effekt Editor");
    mDialog.setModal(true);
            mDialog.exec();
}

void MainWindow::on_actionEinstellungen_settings_triggered()
{
    Option mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("Option / settings");
    mDialog.setModal(true);
            mDialog.exec();
}


void MainWindow::on_actionAusr_stungs_Editor_triggered()
{
    Ausruestung mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("Ausruestung Editor");
    mDialog.setModal(true);
            mDialog.exec();
}

void MainWindow::on_actionKlassen_Editor_triggered()
{
    Klassen_Editor mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("Klassen Editor");
    mDialog.setModal(true);
            mDialog.exec();
}
