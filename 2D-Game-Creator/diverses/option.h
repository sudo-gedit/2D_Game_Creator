#ifndef OPTION_H
#define OPTION_H

#include <QDialog>
#include <QtCore>

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

private:
    Ui::Option *ui;

    QTranslator language;

    void laden_sprache();
};

#endif // OPTION_H
