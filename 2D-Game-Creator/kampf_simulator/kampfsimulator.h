#ifndef KAMPFSIMULATOR_H
#define KAMPFSIMULATOR_H
#include "2D-Game-Creator/kampf_simulator/kampfsimulator_simulation.h"

#include <QDialog>

namespace Ui {
class Kampfsimulator;
}

class Kampfsimulator : public QDialog
{
    Q_OBJECT

public:
    explicit Kampfsimulator(QWidget *parent = 0);
    ~Kampfsimulator();


    /*  Erklaerung ks_h_...
     *
     *  ->  ks = Kampfsimulator
     *  ->  _h = Held(en)
     *  ->  _g = Gegner
     *  ->  _... = Item/Variable
     */



        QString ks_h_auswahl_liste;
        QString ks_g_auswahl_liste;

private slots:
    void on_ks_h_benutzen_clicked();

    void on_ks_g_benutzen_clicked();

    void on_ks_clear_all_clicked();
    
    void on_ks_kampf_start_clicked();

private:
    Ui::Kampfsimulator *ui;

    void werte_leeren();

    void ks_g_items_laden();
    void ks_h_items_laden();
};

#endif // KAMPFSIMULATOR_H
