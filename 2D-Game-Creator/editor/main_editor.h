#ifndef MAIN_EDITOR_H
#define MAIN_EDITOR_H

#include <QTabWidget>
#include <QMessageBox>
#include <QGraphicsItem>
#include <QtCore>
#include <QFileDialog>
#include <QListWidget>
#include <QLineEdit>
#include <QGraphicsView>

#include "2D-Game-Creator/diverses/global.h"

namespace Ui {
class Main_Editor;
}

class Main_Editor : public QTabWidget
{
    Q_OBJECT
    
public:
    explicit Main_Editor(QWidget *parent = 0);
    ~Main_Editor();
    
private slots:
    void on_meh_neu_item_clicked();

    void on_meh_entfernen_item_clicked();

    void on_meh_checkBox_eis_clicked(bool checked);

    void on_meh_checkBox_feuer_clicked(bool checked);

    void on_meh_checkBox_wind_clicked(bool checked);

    void on_meh_checkBox_gift_clicked(bool checked);

    void on_meh_checkBox_betaeubt_clicked(bool checked);

    void on_meh_items_currentItemChanged();

    void on_meh_schliessen_clicked();

    void on_meh_lvl_box_valueChanged();

    void on_pushButton_clicked();

    void on_meh_gesicht_held_knopf_clicked();

    void on_meh_koerper_held_knopf_clicked();

    void on_meg_neu_item_clicked();

    void on_mee_neu_item_clicked();

    void on_mef_neu_item_clicked();

    void on_mek_neu_item_clicked();

    void on_mea_neu_item_clicked();

    void on_megeg_neu_item_clicked();

    void on_meani_neu_item_clicked();

    void on_meh_checkBox_wasser_clicked(bool checked);

    void on_meh_checkBox_finsterniss_clicked(bool checked);

    void on_meh_checkBox_licht_clicked(bool checked);

    void on_meg_entfernen_item_clicked();

    void on_meg_name_item_editingFinished();

    void on_mee_name_item_editingFinished();

    void on_meh_name_item_editingFinished();

    void on_mef_name_item_editingFinished();

    void on_mek_name_item_editingFinished();

    void on_mea_name_item_editingFinished();

    void on_megeg_name_item_editingFinished();

    void on_meani_name_item_editingFinished();

    void on_meg_items_currentItemChanged();

    void on_mee_items_currentItemChanged();

    void on_mef_items_currentItemChanged();

    void on_mek_items_currentItemChanged();

    void on_mea_items_currentItemChanged();

    void on_megeg_items_currentItemChanged();

    void on_meani_items_currentItemChanged();

    void on_meentwi_items_currentItemChanged();

    void on_mef_bild_clicked();

    void on_meg_gesicht_gegner_knopf_clicked();

    void on_meg_koerper_gegner_knopf_clicked();

private:
    Ui::Main_Editor *ui;

    // Funktionen
    void editor_tab_oeffnen();

    void items_laden(QString editor_name, QListWidget*item_liste);
    void item_neu(QString editor_name, QListWidget*neu_item_liste, QLineEdit*neu_item_name);
    void item_entfernen(QString editor_name, QListWidget*gewaehltes_item, QLineEdit*item_name);
    void lvl_speichern();
    void item_namen_aendern_finished(QString editor_name, QListWidget*gewaehltes_item, QLineEdit*item_name);
    void meh_spinbox_disable();
    void item_pic_save(QString editor_name, QGraphicsView*editor_bild, QLineEdit*item_name, QString objekt);
    void editor_name_pfad(QString editor_name);
    void zeichen_sperre();
    void items_currentItemChanged(QString editor_name, QListWidget*gewaehltes_item, QLineEdit*item_name, QGraphicsView*editor_bild);
    void item_werte_laden(QString editor_name, QLineEdit*item_name);
    void item_werte_speichern(QString editor_name, QListWidget*gewaehltes_item, QLineEdit*item_name);

    // Variablen
    QString path_item;
    QString name_item;

    bool feuer;
    bool wind;
    bool gift;
    bool betaeubt;
    bool eis;
    bool wasser;
    bool licht;
    bool finsterniss;
};

#endif // MAIN_EDITOR_H
