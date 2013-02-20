#ifndef HERO_EDITOR_H
#define HERO_EDITOR_H


#include <QtCore>
#include <QtGui>
#include "2D-Game-Creator/diverses/ext_lib/qcustomplot.h"
#include <map>


namespace Ui {
class Hero_Editor;
}

class Hero_Editor : public QDialog
{
    Q_OBJECT
    
public:
    explicit Hero_Editor(QWidget *parent = 0);
    ~Hero_Editor();


    
private slots:

    void on_gesicht_clicked();

    void on_Koerper_clicked();

    void on_pushButton_held_neu_clicked();

    void on_pushButton_held_entfernen_clicked();

    void on_lineEdit_name_editingFinished();

    void on_listWidget_helden_currentItemChanged();

    void on_pushButton_lvl_up_editor_clicked();

    void on_pushButton_schliessen_clicked();

    void on_spinBox_lvl_valueChanged();

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    //Start-Workaround für das speichern der Werte (LVL Editor)
    //////////////////////////////////////////////////////////////////////////////////////////////////////

    void on_lineEdit_ep_editingFinished();

    void on_lineEdit_Leben_editingFinished();

    void on_lineEdit_Mana_editingFinished();

    void on_lineEdit_Kraft_editingFinished();

    void on_lineEdit_ausdauer_editingFinished();

    void on_lineEdit_intelligenz_editingFinished();

    void on_lineEdit_verteidigung_editingFinished();

    void on_lineEdit_glueck_editingFinished();

    //////////////////////////////////////////////////////////////////////////////////////////////////////
    //Ende-Workaround für das speichern der Werte (LVL Editor)
    //////////////////////////////////////////////////////////////////////////////////////////////////////

    void on_spinBox_eis_editingFinished();

    void on_spinBox_feuer_editingFinished();

    void on_spinBox_wind_editingFinished();

    void on_spinBox_gift_editingFinished();

    void on_spinBox_betaeubt_editingFinished();

    void on_checkBox_betaeubt_clicked();

    void on_checkBox_gift_clicked();

    void on_checkBox_wind_clicked();

    void on_checkBox_feuer_clicked();

    void on_checkBox_eis_clicked();

    void on_checkBox_eis_clicked(bool checked);

    void on_checkBox_feuer_clicked(bool checked);

    void on_checkBox_wind_clicked(bool checked);

    void on_checkBox_gift_clicked(bool checked);

    void on_checkBox_betaeubt_clicked(bool checked);

    // Funktionen der Wertetabelle
    void addPlot(std::string name, int x, int y, int width, int height);
    void addPlotPoint(std::string name, double x, double y);
    void paintPlot(std::string name);
    void loeschen_table_gesamt();
    void laden_table_gesamt();
    void laden_tabele(std::string name, int x, int y, int width, int height);

    // Allgemeine Funktionen
    void laden_sprache();
    void speichern_char();      // Spieler Werte Speiechern
    void char_pic_speichern(QString objekt);  // Spieler Gesicht/Avatar Laden/Speichern
    void qlist_namen_laden();   // Qlist alle namen einlesen
    void lvl_speichern();       // lvl informationen werden gesperichert
    void lvl_laden();           // lvl informationen werden geladen
    void spinbox_disable();     // Deaktiviert die Spinboxen

private:
    Ui::Hero_Editor *ui;

    // Funktionen der Wertetabelle
    std::map<std::string, QCustomPlot *> plots;
    std::map<std::string, std::map<std::string, QVector<double> > > plotPoints;
    QCustomPlot *getPlot(std::string name);

    // QString Werte
    QString path_config;
    QString path_char;
    QString path_res;
    QString path_res_;
    QString path_koerper;
    QString objekt;
    QString path_koerper_;
    QString path_char_lvl;
    QString path_charaktaere;

    QString name_held_qlist;

    // Int Werte
    int ist_n_gleich;
    int child_name;

    //bool Werte
    bool lvl_up_editor_bool;
    bool feuer;
    bool wind;
    bool gift;
    bool betaeubt;
    bool eis;
};

#endif // HERO_EDITOR_H
