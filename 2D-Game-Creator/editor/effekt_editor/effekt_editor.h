#ifndef EFFEKT_EDITOR_H
#define EFFEKT_EDITOR_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

namespace Ui {
class Effekt_Editor;
}

class Effekt_Editor : public QDialog
{
    Q_OBJECT
    
public:
    explicit Effekt_Editor(QWidget *parent = 0);
    ~Effekt_Editor();
    
private:
    Ui::Effekt_Editor *ui;

    void laden_sprache();
};

#endif // EFFEKT_EDITOR_H
