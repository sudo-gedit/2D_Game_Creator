#include "kampfsimulator_simulation.h"
#include "ui_kampfsimulator_simulation.h"

Kampfsimulator_simulation::Kampfsimulator_simulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kampfsimulator_simulation)
{
    ui->setupUi(this);
}

Kampfsimulator_simulation::~Kampfsimulator_simulation()
{
    delete ui;
}
