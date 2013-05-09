/*
 *Hier werden alle UI Funktionen ausgelagert!
 *
 *Das soll die Übersicht verbessern. in der Main_Editor.cpp finden sich die dazu gehörigen
 *Funktionen.
 *
 */

#include "main_editor.h"
#include "ui_main_editor.h"



  //-------currentItemChanged---------//
 //--------Auswahl eines Item--------//
//----------------------------------//

void Main_Editor::on_meh_items_currentItemChanged()
// Werte von dem gewählten Item laden (Bilder, Werte)
{
    items_currentItemChanged("Held", ui->meh_items, ui->meh_name_item, NULL);
}

void Main_Editor::on_meg_items_currentItemChanged()
{
    items_currentItemChanged("Gegner", ui->meg_items, ui->meg_name_item, NULL);
}

void Main_Editor::on_mee_items_currentItemChanged()
{
    items_currentItemChanged("Effekt", ui->mee_items, ui->mee_name_item, NULL);
}

void Main_Editor::on_mef_items_currentItemChanged()
{
    items_currentItemChanged("Faehigkeit", ui->mef_items, ui->mef_name_item, ui->mef_bild_icons);
}

void Main_Editor::on_mek_items_currentItemChanged()
{
    items_currentItemChanged("Klasse", ui->mek_items, ui->mek_name_item, NULL);
}

void Main_Editor::on_mea_items_currentItemChanged()
{
    items_currentItemChanged("Ausruestung", ui->mea_items, ui->mea_name_item, NULL);
}

void Main_Editor::on_megeg_items_currentItemChanged()
{
    items_currentItemChanged("Gegenstand", ui->megeg_items, ui->megeg_name_item, NULL);
}

void Main_Editor::on_meani_items_currentItemChanged()
{
    items_currentItemChanged("Animation", ui->meani_items, ui->meani_name_item, NULL);
}

void Main_Editor::on_meentwi_items_currentItemChanged()
{
    //items_currentItemChanged()
}


  //------------neues Item--------------//
 //--Erstellen eines neuen Items-----//
//----------------------------------//

void Main_Editor::on_meh_neu_item_clicked()
{
    item_neu("Held",ui->meh_items, ui->meh_name_item);
}

void Main_Editor::on_meg_neu_item_clicked()
{
    item_neu("Gegner",ui->meg_items, ui->meg_name_item);
}

void Main_Editor::on_mee_neu_item_clicked()
{
    item_neu("Effekt",ui->mee_items, ui->mee_name_item);
}

void Main_Editor::on_mef_neu_item_clicked()
{
    item_neu("Faehigkeit",ui->mef_items, ui->mef_name_item);
}

void Main_Editor::on_mek_neu_item_clicked()
{
    item_neu("Klasse",ui->mek_items, ui->mek_name_item);
}

void Main_Editor::on_mea_neu_item_clicked()
{
    item_neu("Ausruestung",ui->mea_items, ui->mea_name_item);
}

void Main_Editor::on_megeg_neu_item_clicked()
{
    item_neu("Gegenstand",ui->megeg_items, ui->megeg_name_item);
}

void Main_Editor::on_meani_neu_item_clicked()
{
    item_neu("Animation",ui->meani_items, ui->meani_name_item);
}

  //------Bild/icon speichern---------//
 //------------Anfang----------------//
//----------------------------------//

void Main_Editor::on_mef_bild_clicked()
{
    if (ui->mef_items->currentItem() == 0)
    {
        QMessageBox::critical (this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);
    }
    else
    {
        item_pic_save("Faehigkeit",ui->mef_bild_icons ,ui->mef_name_item, NULL);
    }
}

void Main_Editor::on_meh_koerper_held_knopf_clicked()
// Funktion(Aufruf) um den Körper des Helden zu speichern
{
    if (ui->meh_items->currentItem() == 0)
    {
        QMessageBox::critical (this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);
    }
    else
    {
        item_pic_save("Held",ui->meh_koerper_held_bild ,ui->meh_name_item,"_koerper");
    }
}

void Main_Editor::on_meh_gesicht_held_knopf_clicked()
// Funktion(Aufruf) um das Gesicht des Helden zu speichern
{
    if (ui->meh_items->currentItem() == 0)
    {
        QMessageBox::critical (this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);
    }
    else
    {
        item_pic_save("Held",ui->meh_gesicht_held_bild ,ui->meh_name_item, "_gesicht");
    }
}

void Main_Editor::on_meg_gesicht_gegner_knopf_clicked()
{
    if (ui->meg_items->currentItem() == 0)
    {
        QMessageBox::critical (this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);
    }
    else
    {
        item_pic_save("Gegner",ui->meg_gesicht_gegner_bild ,ui->meg_name_item, "_gesicht");
    }
}

void Main_Editor::on_meg_koerper_gegner_knopf_clicked()
{
    if (ui->meg_items->currentItem() == 0)
    {
        QMessageBox::critical (this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);
    }
    else
    {
        item_pic_save("Gegner",ui->meg_koerper_gegner_bild ,ui->meg_name_item, "_koerper");
    }
}

// Ende - Bild/Icon speichern


  //----------Werte speichern---------//
 //------------Anfang----------------//
//----------------------------------//

void Main_Editor::on_pushButton_clicked()
{
    item_werte_speichern("Held", ui->meh_items, ui->meh_name_item);
}

  //---------Werte laden--------------//
 //------------Anfang----------------//
//----------------------------------//

void Main_Editor::on_meh_lvl_box_valueChanged()
{
    item_werte_laden("Held", ui->meh_name_item);
}

  //---------Item umbenennen-----------//
 //------------Anfang----------------//
//----------------------------------//

void Main_Editor::on_meh_name_item_editingFinished()
{
    item_namen_aendern_finished("Held", ui->meh_items, ui->meh_name_item);
}

void Main_Editor::on_meg_name_item_editingFinished()
{
    item_namen_aendern_finished("Gegner", ui->meg_items, ui->meg_name_item);
}

void Main_Editor::on_mee_name_item_editingFinished()
{
    item_namen_aendern_finished("Effekt", ui->mee_items, ui->mee_name_item);
}

void Main_Editor::on_mef_name_item_editingFinished()
{
        item_namen_aendern_finished("Faehigkeit", ui->mef_items, ui->mef_name_item);
}

void Main_Editor::on_mek_name_item_editingFinished()
{
        item_namen_aendern_finished("Klasse", ui->mek_items, ui->mek_name_item);
}

void Main_Editor::on_mea_name_item_editingFinished()
{
        item_namen_aendern_finished("Ausruestung", ui->mea_items, ui->mea_name_item);
}

void Main_Editor::on_megeg_name_item_editingFinished()
{
        item_namen_aendern_finished("Gegenstand", ui->megeg_items, ui->megeg_name_item);
}

void Main_Editor::on_meani_name_item_editingFinished()
{
        item_namen_aendern_finished("Animation", ui->meani_items, ui->meani_name_item);
}
// Ende - Item umbennen


  //---------Item entfernen-----------//
 //------------Anfang----------------//
//----------------------------------//

void Main_Editor::on_meh_entfernen_item_clicked()
{
    item_entfernen("Held", ui->meh_items, ui->meh_name_item);
}

void Main_Editor::on_meg_entfernen_item_clicked()
{
    item_entfernen("Gegner", ui->meg_items, ui->meg_name_item);
}
// Ende - Items entfernen


  //----------------------------------//
 //-----------Alles andere-----------//
//----------------------------------//

void Main_Editor::editor_name_pfad(QString editor_name)
// Übergibt den richtigen Editor-Namen
{
  if (editor_name == "Held")
      {
      name_item = "Neuer_" + editor_name;
      }
  else if (editor_name == "Gegner")
      {
      name_item = "Neuer_" + editor_name;
      }
  else if (editor_name == "Effekt")
      {
      name_item = "Neuer_" + editor_name;
      }
  else if (editor_name == "Faehigkeit")
      {
      name_item = "Neue_" + editor_name;
      }
  else if (editor_name == "Klasse")
      {
      name_item = "Neue_" + editor_name;
      }
  else if (editor_name == "Ausruestung")
      {
      name_item = "Neue_" + editor_name;
      }
  else if (editor_name == "Gegenständ")
      {
      name_item = "Neuer_" + editor_name;
      }
  else if (editor_name == "Animation")
      {
      name_item = "Neue_" + editor_name;
  }
}

void Main_Editor::on_meh_checkBox_eis_clicked(bool checked)
{
    if (checked == true)
    {
        ui->meh_sp_eis_wert->setDisabled(false);
    }
    else
    {
        ui->meh_sp_eis_wert->setDisabled(true);
    }
}

void Main_Editor::on_meh_checkBox_feuer_clicked(bool checked)
{
    if (checked == true)
    {
        ui->meh_sp_feuer_wert->setDisabled(false);
    }
    else
    {
        ui->meh_sp_feuer_wert->setDisabled(true);
    }
}

void Main_Editor::on_meh_checkBox_wind_clicked(bool checked)
{
    if (checked == true)
    {
        ui->meh_sp_wind_wert->setDisabled(false);
    }
    else
    {
        ui->meh_sp_wind_wert->setDisabled(true);
    }
}

void Main_Editor::on_meh_checkBox_gift_clicked(bool checked)
{
    if (checked == true)
    {
        ui->meh_sp_gift_wert->setDisabled(false);
    }
    else
    {
        ui->meh_sp_gift_wert->setDisabled(true);
    }
}

void Main_Editor::on_meh_checkBox_betaeubt_clicked(bool checked)
{
    if (checked == true)
    {
        ui->meh_sp_betaeubt_wert->setDisabled(false);
    }
    else
    {
        ui->meh_sp_betaeubt_wert->setDisabled(true);
    }
}

void Main_Editor::on_meh_checkBox_wasser_clicked(bool checked)
{
    if (checked == true)
    {
        ui->meh_sp_wasser_wert->setDisabled(false);
    }
    else
    {
        ui->meh_sp_wasser_wert->setDisabled(true);
    }
}

void Main_Editor::on_meh_checkBox_finsterniss_clicked(bool checked)
{
    if (checked == true)
    {
        ui->meh_sp_finsterniss_wert->setDisabled(false);
    }
    else
    {
        ui->meh_sp_finsterniss_wert->setDisabled(true);
    }
}

void Main_Editor::on_meh_checkBox_licht_clicked(bool checked)
{
    if (checked == true)
    {
        ui->meh_sp_licht_wert->setDisabled(false);
    }
    else
    {
        ui->meh_sp_licht_wert->setDisabled(true);
    }
}

void Main_Editor::zeichen_sperre()
{
    // LineEdit Buchstaben/Zeichen_Sperre
    ui->meg_name_item->setValidator(new QRegExpValidator( QRegExp("[0-9, A-Z, a-z]+"), this ));
    ui->meh_name_item->setValidator(new QRegExpValidator( QRegExp("[0-9, A-Z, a-z]+"), this ));
    ui->meh_lvl_mana_wert->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->meh_lvl_ausdauer_wert->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->meh_lvl_intelligenz_wert->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->meh_lvl_kraft_wert->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->meh_lvl_leben_wert->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->meh_lvl_verteidigung_wert->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->meh_lvl_ep_wert->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->meh_lvl_glueck_wert->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
}

void Main_Editor::meh_spinbox_disable()
// SpinBox ausschalten, wenn diese nicht gewählt wurde (Gesamtfunktion)
{
    if (eis == false)
    {
        ui->meh_sp_eis_wert->setDisabled(true);
    }
    else
    {
        ui->meh_sp_eis_wert->setDisabled(false);
    }

    if (feuer == false)
    {
        ui->meh_sp_feuer_wert->setDisabled(true);
    }
    else
    {
        ui->meh_sp_feuer_wert->setDisabled(false);
    }

    if (wind == false)
    {
        ui->meh_sp_wind_wert->setDisabled(true);
    }
    else
    {
        ui->meh_sp_wind_wert->setDisabled(false);
    }

    if (gift == false)
    {
        ui->meh_sp_gift_wert->setDisabled(true);
    }
    else
    {
        ui->meh_sp_gift_wert->setDisabled(false);
    }

    if (betaeubt == false)
    {
        ui->meh_sp_betaeubt_wert->setDisabled(true);
    }
    else
    {
        ui->meh_sp_betaeubt_wert->setDisabled(false);
    }

    if (licht == false)
    {
        ui->meh_sp_licht_wert->setDisabled(true);
    }
    else
    {
        ui->meh_sp_licht_wert->setDisabled(false);
    }

    if (finsterniss == false)
    {
        ui->meh_sp_finsterniss_wert->setDisabled(true);
    }
    else
    {
        ui->meh_sp_finsterniss_wert->setDisabled(false);
    }

    if (wasser == false)
    {
        ui->meh_sp_wasser_wert->setDisabled(true);
    }
    else
    {
        ui->meh_sp_wasser_wert->setDisabled(false);
    }
}

void Main_Editor::editor_tab_oeffnen()
//Den gewünschten Tab öffnen
{
    if (     editor_main_tab == 0)
    {
        //Hero Editor
        setCurrentIndex(0);
    }
    else if (editor_main_tab == 1)
    {
        //Gegner Editor
        setCurrentIndex(1);
    }
    else if (editor_main_tab == 2)
    {
        //Klassen Editor
        setCurrentIndex(4);
    }
    else if (editor_main_tab == 3)
    {
        //Ausrüstung
        setCurrentIndex(5);
    }
    else if (editor_main_tab == 4)
    {
        //Fähigkeiten Editor
        setCurrentIndex(2);
    }
    else if (editor_main_tab == 5)
    {
        //Gegenstand Editor
        setCurrentIndex(6);
    }
    else if (editor_main_tab == 6)
    {
        //Effekt Editor
        setCurrentIndex(3);
    }
    else if (editor_main_tab == 7)
    {
        //Animation
        setCurrentIndex(7);
    }
    else if (editor_main_tab == 8)
    {
        //Entwicklungsplaner
        setCurrentIndex(7);
    }

items_laden("Held", ui->meh_items);
items_laden("Gegner", ui->meg_items);
items_laden("Effekt", ui->mee_items);
items_laden("Faehigkeit" , ui->mef_items);
items_laden("Klasse" , ui->mek_items);
items_laden("Ausruestung", ui->mea_items);
items_laden("Gegenstand", ui->megeg_items);
items_laden("Animation", ui->meani_items);
items_laden("Entwicklungsplaner", ui->meentwi_items);
}

void Main_Editor::on_meh_schliessen_clicked()
{
    close();
}
