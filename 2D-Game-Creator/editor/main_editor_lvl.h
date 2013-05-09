#ifndef MAIN_EDITOR_LVL_H
#define MAIN_EDITOR_LVL_H

#include <QDialog>

namespace Ui {
class Main_Editor_LVL;
}

class Main_Editor_LVL : public QDialog
{
    Q_OBJECT
    
public:
    explicit Main_Editor_LVL(QWidget *parent = 0);
    ~Main_Editor_LVL();
    
private:
    Ui::Main_Editor_LVL *ui;
};

#endif // MAIN_EDITOR_LVL_H
