#ifndef FAEHIGKEITEN_EDITOR_H
#define FAEHIGKEITEN_EDITOR_H

#include <QDialog>

namespace Ui {
class Faehigkeiten_Editor;
}

class Faehigkeiten_Editor : public QDialog
{
    Q_OBJECT
    
public:
    explicit Faehigkeiten_Editor(QWidget *parent = 0);
    ~Faehigkeiten_Editor();
    
private:
    Ui::Faehigkeiten_Editor *ui;
};

#endif // FAEHIGKEITEN_EDITOR_H
