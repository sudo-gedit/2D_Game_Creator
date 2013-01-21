#ifndef AUSRUESTUNG_H
#define AUSRUESTUNG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

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
    void laden_sprache();
};

#endif // AUSRUESTUNG_H
