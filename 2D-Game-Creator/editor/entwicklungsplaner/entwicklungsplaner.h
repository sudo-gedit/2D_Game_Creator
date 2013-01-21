#ifndef ENTWICKLUNGSPLANER_H
#define ENTWICKLUNGSPLANER_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

namespace Ui {
class Entwicklungsplaner;
}

class Entwicklungsplaner : public QDialog
{
    Q_OBJECT
    
public:
    explicit Entwicklungsplaner(QWidget *parent = 0);
    ~Entwicklungsplaner();
    
private:
    Ui::Entwicklungsplaner *ui;
    void laden_sprache();
};

#endif // ENTWICKLUNGSPLANER_H
