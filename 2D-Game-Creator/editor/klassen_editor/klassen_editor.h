#ifndef KLASSEN_EDITOR_H
#define KLASSEN_EDITOR_H

#include <QDialog>

namespace Ui {
class Klassen_Editor;
}

class Klassen_Editor : public QDialog
{
    Q_OBJECT
    
public:
    explicit Klassen_Editor(QWidget *parent = 0);
    ~Klassen_Editor();
    
private:
    Ui::Klassen_Editor *ui;
};

#endif // KLASSEN_EDITOR_H
