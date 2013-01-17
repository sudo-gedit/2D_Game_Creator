#ifndef HERO_EDITOR_H
#define HERO_EDITOR_H


#include <QtCore>
#include <QtGui>

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

private:

    Ui::Hero_Editor *ui;

    // QString Werte
    QString path_config;
    QString path_char;
    QString path_res;
    QString path_koerper;
    QString objekt;
    QString path_koerper_;
    QString path_res_;
    QString path_char_lvl;
    QString path_charaktaere;

    // Int Werte
    int zaehler;

    //bool Werte
    bool lvl_up_editor_bool;

    // Funktionen
    void speichern_char();      // Spieler Werte Speiechern
    void laden_char();          // Spieler Werte Laden
    void char_pic_speichern(QString objekt);  // Spieler Gesicht/Avatar Laden/Speichern
    void qlist_namen_laden();   // Qlist alle namen einlesen
    void lvl_speichern();       // lvl informationen werden gesperichert
    void lvl_laden();           // lvl informationen werden geladen

};

#endif // HERO_EDITOR_H
