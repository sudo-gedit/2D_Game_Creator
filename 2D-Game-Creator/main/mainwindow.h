#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

#include "2D-Game-Creator/editor/main_editor.h"
#include "2D-Game-Creator/diverses/option.h"
#include "2D-Game-Creator/diverses/about.h"
#include "2D-Game-Creator/kampf_simulator/kampfsimulator.h"

#include "2D-Game-Creator/diverses/global.h"

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
    void on_actionEinstellungen_Settings_2_triggered();

    void on_actionEinstellungen_Settings_triggered();

    void on_actionAbout_triggered();

    void on_actionHero_Editor_triggered();

    void on_actionGegenstand_Editor_triggered();

    void on_actionKlassen_Editor_triggered();

    void on_actionAusr_stungs_Editor_triggered();

    void on_actionFaehigkeiten_Editor_triggered();

    void on_actionEffekt_Editor_triggered();

    void on_actionGegner_Editor_triggered();

    void on_actionKampf_Editor_triggered();

    void on_actionEntwicklungsplanner_triggered();

    void on_actionKampfsimulation_triggered();

private:
    Ui::MainWindow *ui;
    void laden_sprache();
};

#endif // MAINWINDOW_H
