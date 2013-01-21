#ifndef OPTION_H
#define OPTION_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

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

    void on_pushButton_sprache_speichern_clicked();

    void lade_sprache_in_comboBox();

private:
    Ui::Option *ui;

    QTranslator language;

    void laden_sprache();
};

#endif // OPTION_H
