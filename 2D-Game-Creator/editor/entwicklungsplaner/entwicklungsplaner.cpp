//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//
// Letzte Aenderung 13.10.2012
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
