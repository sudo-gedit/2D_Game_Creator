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
#include "about.h"
#include "heroeditor.h"
#include "entwicklungsplaner.h"


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
    HeroEditor mDialog;
    mDialog.setModal(true);
            mDialog.exec();
}


void MainWindow::on_actionEntwicklungsplanner_triggered()
{
    Entwicklungsplaner mDialog;
    mDialog.setModal(true);
            mDialog.exec();

}

