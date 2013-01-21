#ifndef GEGENSTAND_EDITOR_H
#define GEGENSTAND_EDITOR_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

namespace Ui {
class Gegenstand_Editor;
}

class Gegenstand_Editor : public QDialog
{
    Q_OBJECT
    
public:
    explicit Gegenstand_Editor(QWidget *parent = 0);
    ~Gegenstand_Editor();
    
private:
    Ui::Gegenstand_Editor *ui;

    void laden_sprache();

};

#endif // GEGENSTAND_EDITOR_H
