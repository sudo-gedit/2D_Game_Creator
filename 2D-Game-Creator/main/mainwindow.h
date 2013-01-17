#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include "2D-Game-Creator/about/about.h"
#include "2D-Game-Creator/diverses/option.h"
#include "2D-Game-Creator/editor/hero_editor/hero_editor.h"
#include "2D-Game-Creator/editor/entwicklungsplaner/entwicklungsplaner.h"
#include "2D-Game-Creator/editor/monster_editor/monster_editor.h"
#include "2D-Game-Creator/editor/faehigkeiten_editor/faehigkeiten_editor.h"
#include "2D-Game-Creator/editor/gegenstand_editor/gegenstand_editor.h"
#include "2D-Game-Creator/simulation/kampfsimulation/kampfsimulation.h"
#include "2D-Game-Creator/editor/effekt_editor/effekt_editor.h"


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

    void on_actionGegenstand_Editor_triggered();

    void on_actionFeahigkeiten_triggered();

    void on_actionKampfsimulation_triggered();

    void on_actionStatus_Editor_triggered();

    void on_actionEinstellungen_settings_triggered();

    void on_actionAusr_stungs_Editor_triggered();

    void on_actionKlassen_Editor_triggered();

private:
    Ui::MainWindow *ui;

    QTranslator language;
    QString path_config_app;

    void laden_sprache();

};

#endif // MAINWINDOW_H
