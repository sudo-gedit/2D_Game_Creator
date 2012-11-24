#ifndef HEROEDITOR_H
#define HEROEDITOR_H


#include <QtCore>
#include <QtGui>

namespace Ui {
class HeroEditor;
}

class HeroEditor : public QDialog
{
    Q_OBJECT
    
public:
    explicit HeroEditor(QWidget *parent = 0);
    ~HeroEditor();
    
private slots:

    void on_okay_clicked();

    void on_gesicht_clicked();

    void on_Koerper_clicked();

    void on_pushButton_held_neu_clicked();

    void on_pushButton_held_entfernen_clicked();

    void on_lineEdit_name_editingFinished();

    void on_listWidget_helden_currentItemChanged(QListWidgetItem *currentItem, QListWidgetItem *previous);

private:

    Ui::HeroEditor *ui;
    QString path_config;
    QString path_char;
    QString path_gesicht;
    QString path_koerper;
    QString path_gesicht_copy;
    QString path_app;
    int zaehler;


    void speichern_char();      // Spieler Werte Speiechern
    void laden_char();          // Spieler Werte Laden
    void gesicht_char_laden();  // Spieler Gesicht/Avatar Laden/Speichern
    void koerper_char_laden();  // Spieler Körper Laden/Speichern
    void qlist_namen_laden();   // Qlist alle namen einlesen

};

#endif // HEROEDITOR_H
