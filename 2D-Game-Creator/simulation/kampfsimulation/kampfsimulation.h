#ifndef KAMPFSIMULATION_H
#define KAMPFSIMULATION_H

#include <QDialog>

namespace Ui {
class Kampfsimulation;
}

class Kampfsimulation : public QDialog
{
    Q_OBJECT
    
public:
    explicit Kampfsimulation(QWidget *parent = 0);
    ~Kampfsimulation();
    
private:
    Ui::Kampfsimulation *ui;
};

#endif // KAMPFSIMULATION_H
