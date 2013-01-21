#ifndef KLASSEN_EDITOR_H
#define KLASSEN_EDITOR_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

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

    void laden_sprache();
};

#endif // KLASSEN_EDITOR_H
