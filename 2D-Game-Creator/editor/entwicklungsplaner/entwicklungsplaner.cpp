//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Entwicklungsplaner version 0.00.0.1
//
//
//
// Letzte Aenderung 03.01.2013
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "entwicklungsplaner.h"
#include "ui_entwicklungsplaner.h"

Entwicklungsplaner::Entwicklungsplaner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Entwicklungsplaner)
{
    ui->setupUi(this);
}

Entwicklungsplaner::~Entwicklungsplaner()
{
    delete ui;
}
