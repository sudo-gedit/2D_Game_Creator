#include "ausruestung.h"
#include "ui_ausruestung.h"

Ausruestung::Ausruestung(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ausruestung)
{
    ui->setupUi(this);
}

Ausruestung::~Ausruestung()
{
    delete ui;
}
