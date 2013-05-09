#ifndef KAMPFSIMULATOR_SIMULATION_H
#define KAMPFSIMULATOR_SIMULATION_H

#include <QDialog>

namespace Ui {
class Kampfsimulator_simulation;
}

class Kampfsimulator_simulation : public QDialog
{
    Q_OBJECT
    
public:
    explicit Kampfsimulator_simulation(QWidget *parent = 0);
    ~Kampfsimulator_simulation();
    
private:
    Ui::Kampfsimulator_simulation *ui;

    struct kaempfer
    {
        QString name;
        int lvl;
        int leben;
        int mana;
        int kraft;
        int ausdauer;
        int intelligenz;
        int verteidigung;
        int glueck;
        int eis;
        int feuer;
        int wind;
        int gift;
        int betaeubung;
        bool b_eis;
        bool b_feuer;
        bool b_wind;
        bool b_gift;
        bool b_betaeubung;
        QString gesicht;
    };
};

#endif // KAMPFSIMULATOR_SIMULATION_H
