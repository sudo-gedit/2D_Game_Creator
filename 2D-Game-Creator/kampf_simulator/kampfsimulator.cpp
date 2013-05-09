#include "kampfsimulator.h"
#include "ui_kampfsimulator.h"

Kampfsimulator::Kampfsimulator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kampfsimulator)
{
    ui->setupUi(this);
}

Kampfsimulator::~Kampfsimulator()
{
    delete ui;
}

void Kampfsimulator::werte_leeren()
{
    ui->ks_h_liste_kampf->clear();
    ui->ks_g_liste_kampf->clear();
}

void Kampfsimulator::ks_g_items_laden()
{
}

void Kampfsimulator::ks_h_items_laden()
{
}


void Kampfsimulator::on_ks_h_benutzen_clicked()
{
    QString lvl_s = QString::number(ui->ks_h_lvl->value());
    //int lvl_i = ui->ks_h_lvl->value();


    ks_h_auswahl_liste = ui->ks_h_liste->currentItem()->text();
    ui->ks_h_liste_kampf->addItem(ks_h_auswahl_liste + " " + lvl_s);
}

void Kampfsimulator::on_ks_g_benutzen_clicked()
{
    ks_g_auswahl_liste = ui->ks_g_liste->currentItem()->text();
    ui->ks_g_liste_kampf->addItem(ks_g_auswahl_liste);
}

void Kampfsimulator::on_ks_clear_all_clicked()
{
    werte_leeren();
}

void Kampfsimulator::on_ks_kampf_start_clicked()
{
    Kampfsimulator_simulation mDialog;
    mDialog.setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint );
    mDialog.setWindowTitle("Kampf Vorbereitung");
    mDialog.setModal(true);
            mDialog.exec();
}
