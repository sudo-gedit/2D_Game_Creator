#ifndef OPTION_H
#define OPTION_H

#include <QDialog>

namespace Ui {
class Option;
}

class Option : public QDialog
{
    Q_OBJECT
    
public:
    explicit Option(QWidget *parent = 0);
    ~Option();
    
private slots:

private:
    Ui::Option *ui;
};

#endif // OPTION_H
