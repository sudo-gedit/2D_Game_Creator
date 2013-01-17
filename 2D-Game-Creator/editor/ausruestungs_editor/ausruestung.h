#ifndef AUSRUESTUNG_H
#define AUSRUESTUNG_H

#include <QDialog>

namespace Ui {
class Ausruestung;
}

class Ausruestung : public QDialog
{
    Q_OBJECT
    
public:
    explicit Ausruestung(QWidget *parent = 0);
    ~Ausruestung();
    
private:
    Ui::Ausruestung *ui;
};

#endif // AUSRUESTUNG_H
