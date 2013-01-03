#ifndef MONSTER_EDITOR_H
#define MONSTER_EDITOR_H


#include <QtCore>
#include <QtGui>

namespace Ui {
class Monster_Editor;
}

class Monster_Editor : public QDialog
{
    Q_OBJECT
    
public:
    explicit Monster_Editor(QWidget *parent = 0);
    ~Monster_Editor();
    
private slots:

    void on_okay_clicked();

    void on_gesicht_clicked();

    void on_Koerper_clicked();

    void on_pushButton_monster_neu_clicked();

    void on_pushButton_monster_entfernen_clicked();

    void on_lineEdit_name_editingFinished();

    void on_listWidget_monster_currentItemChanged();

    void on_pushButton_schliessen_clicked();

private:

    Ui::Monster_Editor *ui;

    // QString Werte
    QString path_config;
    QString path_char;
    QString path_res;
    QString path_koerper;
    QString objekt;
    QString path_koerper_;
    QString path_res_;

    // Int Werte
    int zaehler;

    //bool Werte
    bool lvl_up_editor_bool;

    // Funktionen
    void speichern_char();                    // Spieler Werte Speiechern
    void laden_char();                        // Spieler Werte Laden
    void char_pic_speichern(QString objekt);  // Spieler Gesicht/Avatar Laden/Speichern
    void qlist_namen_laden();                 // Qlist alle namen einlesen

};

#endif // Monster_EDITOR_H
