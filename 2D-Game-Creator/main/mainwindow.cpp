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
#include "2D-Game-Creator/about/about.h"
#include "2D-Game-Creator/editor/hero_editor/hero_editor.h"
#include "2D-Game-Creator/editor/entwicklungsplaner/entwicklungsplaner.h"
#include "2D-Game-Creator/editor/monster_editor/monster_editor.h"


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
    mDialog.setModal(true);
            mDialog.exec();
}

void MainWindow::on_actionHero_Editor_triggered()
{
    Hero_Editor mDialog;
    mDialog.setModal(true);
            mDialog.exec();
}


void MainWindow::on_actionEntwicklungsplanner_triggered()
{
    Entwicklungsplaner mDialog;
    mDialog.setModal(true);
            mDialog.exec();

}

void MainWindow::on_actionMonster_Editor_triggered()
{
    Monster_Editor mDialog;
    mDialog.setModal(true);
            mDialog.exec();

}

