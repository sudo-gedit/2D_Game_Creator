#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QDebug>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
     explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void on_actionAbout_triggered();

    void on_actionHero_Editor_triggered();

    void on_actionEntwicklungsplanner_triggered();

    void on_actionMonster_Editor_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
