//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//
// Letzte Aenderung 13.10.2012
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "about.h"
#include "ui_about.h"



About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{

    ui->setupUi(this);
}

About::~About()
{
    delete ui;
}
