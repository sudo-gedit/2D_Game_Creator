#ifndef ENTWICKLUNGSPLANER_H
#define ENTWICKLUNGSPLANER_H

#include <QDialog>

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
};

#endif // ENTWICKLUNGSPLANER_H
