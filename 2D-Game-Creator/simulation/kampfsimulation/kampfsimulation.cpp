#include "kampfsimulation.h"
#include "ui_kampfsimulation.h"

Kampfsimulation::Kampfsimulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kampfsimulation)
{
    ui->setupUi(this);
}

Kampfsimulation::~Kampfsimulation()
{
    delete ui;
}
