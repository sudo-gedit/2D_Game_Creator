/*
 *
 *Main Editor für:
 *
 *meh -> Held(en)
 *meg -> Gegner
 *mee -> Effekte
 *mef -> Fähigkeiten
 *mek -> Klassen
 *mea -> Ausrüstung
 *megeg -> Gegenstände
 *meani -> Animation
 *meetwi-> Entwicklungsplaner
 *
 *Die UI Evente finden sich alle in der ui_funktionen.cpp.
 *Die Auslageung soll die Übersicht verbessern.
 */

#include "main_editor.h"
#include "ui_main_editor.h"
#include "2D-Game-Creator/diverses/global.h"

Main_Editor::Main_Editor(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::Main_Editor)
{
    ui->setupUi(this);
    //setFixedSize(); Steht noch offen, da die UI nicht ganz fertig ist


    // Umgebungsvariablen
    path_item = QApplication::applicationDirPath();


    // Funktionen, die direkt aufgerufen werden
    editor_tab_oeffnen();
    zeichen_sperre();
}

Main_Editor::~Main_Editor()
{
    delete ui;
}


   //----------------------------------//
  //----------Globale Funktionen------//
 //----------------------------------//

void Main_Editor::item_neu(QString editor_name, QListWidget*neu_item_liste, QLineEdit*neu_item_name)
// Funktion um einen neues item zu erstellen
{
    editor_name_pfad(editor_name);

for (int i = 1; i <= 100; ++i)
    {
     QList<QListWidgetItem*> items = neu_item_liste->findItems(name_item + QString::number(i), 0);

         if (items.empty())
         {
         neu_item_liste->addItem(name_item + QString::number(i));
         neu_item_name->setText(name_item + QString::number(i));

         QSettings *settings = new QSettings(path_item + "/game/" +editor_name+ "/" +editor_name+ ".ini",QSettings::IniFormat);
         settings->beginGroup(name_item + QString::number(i));
         settings->setValue("name",  ui->meh_name_item->text());
         settings->endGroup();

         QString held_name = ui->meh_name_item->text();

         QFile file(path_item + "game/Held/lvl_"+ held_name +".ini" );
         file.open(QIODevice::WriteOnly | QIODevice::Text);
            file.close();
        return;
        }
    neu_item_liste->sortItems(Qt::AscendingOrder);
    }
}

void Main_Editor::items_laden(QString editor_name, QListWidget*item_liste)
// Items (alle) werden aus der ini geladen
{
item_liste->clear();

    QFile file(path_item + "/game/" +editor_name+ "/" +editor_name+ ".ini");
    if( !file.exists())
        {
        }
    else
        {
        QSettings settings (path_item + "/game/" +editor_name+ "/" +editor_name+ ".ini", QSettings::IniFormat);
        QStringList group = settings.childGroups();
        for(int child = 0; child != group.size(); ++child)
        {
            QString childVersion = group.at(child);
            item_liste->addItem(childVersion);
        }
          item_liste->item(0)->setSelected(true);
        }
}

void Main_Editor::item_entfernen(QString editor_name, QListWidget*gewaehltes_item, QLineEdit*item_name)
// Funktion um das gewählte Item zu löschen (mit Prüfmechanismus)
{
    // Prüfen wie viele Items noch existieren
    int count = gewaehltes_item->count();

    if (count == 1)
    {
        QMessageBox::critical(this, "Achtung", "Du versuchst den letzten Helden zu loeschen, das ist nicht moeglich!", QMessageBox::Ok);
        return;
    }
    // Prüfen, ob überhaupt ein Held gewählt wurde
    if    (gewaehltes_item->currentItem() == NULL)
    {
        QMessageBox::critical(this, "Achtung", "Es wurde kein Held gewaehlt!", QMessageBox::Ok);
    }
    else
    {
        // Entwickler wird gefragt, ob er wirklich löschen will
        int status;
        status = QMessageBox::question(this, "Info", "Soll der Held \"" + item_name->text() + "\" wirklich geloescht werden?" , QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if (status == QMessageBox::Yes)
        {
            QListWidgetItem *item = gewaehltes_item->currentItem();
            QStringList qlistwidgetitem_convert;
            qlistwidgetitem_convert << item->text();
            QString qlistwidgetitem_convert_qstring = qlistwidgetitem_convert.at(0);

            delete item;

            QSettings *settings = new QSettings(path_item + "/game/" +editor_name+ "/" +editor_name+".ini",QSettings::IniFormat);
            settings->remove (qlistwidgetitem_convert_qstring);

            if (editor_name == "Held")
                {
                    QFile::remove(path_item + "lvl_" + qlistwidgetitem_convert_qstring + ".ini");

                    //QString format = ".gif"; //Workaround wir noch umgesetzt
                    QFile::remove(path_item + "/game/" +editor_name+ "/" + qlistwidgetitem_convert_qstring + "_gesicht.gif");
                    QFile::remove(path_item + "/game/" +editor_name+ "/" + qlistwidgetitem_convert_qstring + "_koerper.gif");
                }
        }
        else
        {
            // Wird "Nein" gewählt oder abgebrochen, passiert nichts
        }
        gewaehltes_item->sortItems(Qt::AscendingOrder);
    }
}

void Main_Editor::items_currentItemChanged(QString editor_name, QListWidget*gewaehltes_item, QLineEdit*item_name, QGraphicsView *editor_bild)
// Werte von dem gewählten Item laden (Bilder, Werte)
{

QString name_gewaelht_item = gewaehltes_item->currentItem()->text();
item_name->setText(name_gewaelht_item);

if (editor_name == "Held" || editor_name == "Gegener")
    {
        if (editor_name == "Held")
            {
                QFile gesicht_file( path_item + "/game/" +editor_name+ "/" +item_name->text()+"_gesicht" + ".gif");
                QFile koerper_file( path_item + "/game/" + editor_name+ "/"+item_name->text()+"_koerper" + ".gif");

                if (!gesicht_file.exists())
                    {
                        QList<QGraphicsItem*> item = ui->meh_gesicht_held_bild->items();
                        qDeleteAll(item);
                    }
                else
                    {
                        QImage image_gesicht(path_item + "/game/" +editor_name+ "/" +item_name->text()+"_gesicht" + ".gif");
                        image_gesicht = image_gesicht.scaled(this->ui->meh_gesicht_held_bild->width()-10,this->ui->meh_gesicht_held_bild->height()-10);
                        QGraphicsScene *gesicht = new QGraphicsScene();
                        gesicht->addPixmap(QPixmap::fromImage(image_gesicht));
                        ui->meh_gesicht_held_bild->setScene(gesicht);
                    }

                if (!koerper_file.exists())
                    {
                    QList<QGraphicsItem*> item = ui->meh_koerper_held_bild->items();
                    qDeleteAll(item);
                    }
                else
                    {
                    QImage image_koerper(path_item + "/game/" + editor_name+ "/"+item_name->text()+"_koerper" + ".gif");
                    image_koerper = image_koerper.scaled(this->ui->meh_koerper_held_bild->width()-10,this->ui->meh_koerper_held_bild->height()-10);
                    QGraphicsScene *koerper = new QGraphicsScene();
                    koerper->addPixmap(QPixmap::fromImage(image_koerper));
                    ui->meh_koerper_held_bild->setScene(koerper);
                    }
            }

        if (editor_name == "Gegner")
            {
            QFile gesicht_file( path_item + "/game/" +editor_name+ "/" +item_name->text()+"_gesicht" + ".gif");
            QFile koerper_file( path_item + "/game/" + editor_name+ "/"+item_name->text()+"_koerper" + ".gif");

            if (!gesicht_file.exists())
                {
                    QList<QGraphicsItem*> item = ui->meg_gesicht_gegner_bild->items();
                    qDeleteAll(item);
                }
            else
                {
                    QImage image_gesicht(path_item + "/game/" +editor_name+ "/" +item_name->text()+"_gesicht" + ".gif");
                    image_gesicht = image_gesicht.scaled(this->ui->meg_gesicht_gegner_bild->width()-10,this->ui->meg_gesicht_gegner_bild->height()-10);
                    QGraphicsScene *gesicht = new QGraphicsScene();
                    gesicht->addPixmap(QPixmap::fromImage(image_gesicht));
                    ui->meg_gesicht_gegner_bild->setScene(gesicht);
                }

            if (!koerper_file.exists())
                {
                QList<QGraphicsItem*> item = ui->meg_koerper_gegner_bild->items();
                qDeleteAll(item);
                }
            else
                {
                QImage image_koerper(path_item + "/game/" + editor_name+ "/"+item_name->text()+"_koerper" + ".gif");
                image_koerper = image_koerper.scaled(this->ui->meg_koerper_gegner_bild->width()-10,this->ui->meg_koerper_gegner_bild->height()-10);
                QGraphicsScene *koerper = new QGraphicsScene();
                koerper->addPixmap(QPixmap::fromImage(image_koerper));
                ui->meg_koerper_gegner_bild->setScene(koerper);
                }
        }
}


if (editor_name == "Faehigkeit" || editor_name == "Platzhalter" )
    {
        QFile gesicht_file( path_item + "/game/" +editor_name+ "/" +item_name->text() + ".gif");

        if (!gesicht_file.exists())
            {
                QList<QGraphicsItem*> item = editor_bild->items();
                qDeleteAll(item);
            }
        else
            {
                QImage image_gesicht(path_item + "/game/" + editor_name+ "/"+item_name->text()+".gif");
                image_gesicht = image_gesicht.scaled(editor_bild->width(),editor_bild->height());
                QGraphicsScene *gesicht = new QGraphicsScene();
                gesicht->addPixmap(QPixmap::fromImage(image_gesicht));
                editor_bild->setScene(gesicht);
            }
    }
item_werte_laden("Held",ui->meh_name_item);
}

void Main_Editor::item_werte_laden(QString editor_name, QLineEdit *item_name)
// Werte von dem gewählten item laden (Werte)
{
    if (editor_name == "Held")
        {
            QString name_widget = item_name->text();
            int spinbox_lvl_aktuell = ui->meh_lvl_box->value();
            QString lvl_aktuell_stri = QString::number(spinbox_lvl_aktuell);


            //Laden der Settings (Werten/Einstellungen) aus der .ini
            QSettings *settings = new QSettings (path_item+ "/game/Held"+ "/lvl_" + name_widget + ".ini", QSettings::IniFormat, this);
            settings->beginGroup(lvl_aktuell_stri);

            QString leben = settings->value("leben").toString();
            QString mana = settings->value("mana").toString();
            QString kraft = settings->value("kraft").toString();
            QString ausdauer = settings->value("ausdauer").toString();
            QString intelligenz = settings->value("intelligenz").toString();
            QString verteidigung = settings->value("verteidigung").toString();
            QString glueck = settings->value("glueck").toString();
            QString ep = settings->value("ep").toString();

            QString gesicht_ = settings->value("gesicht_").toString();
            QString koerper_ = settings->value("koerper_").toString();


            feuer =settings->value("feuer").toBool();
            wind = settings->value("wind").toBool();
            gift = settings->value("gift").toBool();
            betaeubt = settings->value("betaeubt").toBool();
            eis = settings->value("eis").toBool();
            wasser = settings->value("wasser").toBool();
            finsterniss = settings->value("finsterniss").toBool();
            licht = settings->value("licht").toBool();

            int feuer_pro = settings->value("feuer_pro").toInt();
            int eis_pro = settings->value("eis_pro").toInt();
            int betaeubt_pro = settings->value("betaeubt_pro").toInt();
            int gift_pro = settings->value("gift_pro").toInt();
            int wind_pro = settings->value("wind_pro").toInt();
            int wasser_pro = settings->value("wasser_pro").toInt();
            int finsterniss_pro = settings->value("finsterniss_pro").toInt();
            int licht_pro = settings->value("licht").toInt();
            settings->endGroup();

            //Settings in die GUI laden (lineEdit)
            ui->meh_lvl_leben_wert->setText(leben);
            ui->meh_lvl_mana_wert->setText(mana);
            ui->meh_lvl_kraft_wert->setText(kraft);
            ui->meh_lvl_ausdauer_wert->setText(ausdauer);
            ui->meh_lvl_intelligenz_wert->setText(intelligenz);
            ui->meh_lvl_verteidigung_wert->setText(verteidigung);
            ui->meh_lvl_glueck_wert->setText(glueck);
            ui->meh_lvl_ep_wert->setText(ep);

            //Sttings in die GUI laden (checkBox)
            ui->meh_checkBox_feuer->setChecked(feuer);
            ui->meh_checkBox_wind->setChecked(wind);
            ui->meh_checkBox_gift->setChecked(gift);
            ui->meh_checkBox_betaeubt->setChecked(betaeubt);
            ui->meh_checkBox_eis->setChecked(eis);
            ui->meh_checkBox_finsterniss->setChecked(finsterniss);
            ui->meh_checkBox_wasser->setChecked(wasser);
            ui->meh_checkBox_licht->setChecked(licht);

            //Settings in die GUI laden (spinBox)
            ui->meh_sp_feuer_wert->setValue(feuer_pro);
            ui->meh_sp_eis_wert->setValue(eis_pro);
            ui->meh_sp_betaeubt_wert->setValue(betaeubt_pro);
            ui->meh_sp_gift_wert->setValue(gift_pro);
            ui->meh_sp_wind_wert->setValue(wind_pro);
            ui->meh_sp_wasser_wert->setValue(wasser_pro);
            ui->meh_sp_licht_wert->setValue(licht_pro);
            ui->meh_sp_finsterniss_wert->setValue(finsterniss_pro);

            meh_spinbox_disable();
        }
    if (editor_name == "Gegner")
    {
        QString gegner_name = item_name->text();
        QString path_gegner = path_item + "/game/" +editor_name+ "/" +editor_name+ ".ini";

        //Laden der Settings (Werten/Einstellungen) aus der .ini
        QSettings *settings = new QSettings (path_gegner, QSettings::IniFormat, this);
        settings->beginGroup("Platzhalter");

        settings->endGroup();



//

    }

    if (editor_name == "Effekt")
    {

    }

    if (editor_name == "Faehigkeit")
    {

    }

    if (editor_name == "Klasse")
    {

    }

    if (editor_name == "Ausruestung")
    {

    }

    if (editor_name == "Gegenstand")
    {

    }

    if (editor_name == "Animation")
    {

    }

    if (editor_name == "Platzhalter")
    {

    }
}

void Main_Editor::item_werte_speichern(QString editor_name, QListWidget *gewaehltes_item, QLineEdit *item_name)
// Werte von dem gewählten Item speichern (Werte)
{
    if (editor_name == "Held")
    {
        if    (ui->meh_items->currentItem() == 0)
// Sollte kein Item gewählt sein, werden alle Parameter zurückgesetzt.
        {
        QMessageBox::critical(this, "Achtung", "Es wurde nichts ausgewaehlt.", QMessageBox::Ok);

        ui->meh_checkBox_betaeubt->setCheckState(Qt::Unchecked);
        ui->meh_checkBox_eis->setCheckState(Qt::Unchecked);
        ui->meh_checkBox_feuer->setCheckState(Qt::Unchecked);
        ui->meh_checkBox_gift->setCheckState(Qt::Unchecked);
        ui->meh_checkBox_wind->setCheckState(Qt::Unchecked);
        ui->meh_checkBox_wasser->setCheckState(Qt::Unchecked);
        ui->meh_checkBox_licht->setCheckState(Qt::Unchecked);
        ui->meh_checkBox_finsterniss->setCheckState(Qt::Unchecked);

        ui->meh_lvl_ausdauer_wert->clear();
        ui->meh_lvl_ep_wert->clear();
        ui->meh_lvl_glueck_wert->clear();
        ui->meh_lvl_intelligenz_wert->clear();
        ui->meh_lvl_kraft_wert->clear();
        ui->meh_lvl_leben_wert->clear();
        ui->meh_lvl_mana_wert->clear();
        ui->meh_lvl_verteidigung_wert->clear();
        ui->meh_name_item->clear();

        ui->meh_sp_betaeubt_wert->clear();
        ui->meh_sp_eis_wert->clear();
        ui->meh_sp_feuer_wert->clear();
        ui->meh_sp_gift_wert->clear();
        ui->meh_sp_wind_wert->clear();
        }
        else
        {
// Hier werden die Werte geladen, wenn ein Item gewählt wurde
        QString name_widget = ui->meh_items->currentItem()->text();
        int spinbox_lvl_aktuell = ui->meh_lvl_box->value();
        QString lvl_aktuell_stri = QString::number(spinbox_lvl_aktuell);

        QSettings *settings = new QSettings(path_item+ "/game/Held"+ "/lvl_" + name_widget + ".ini", QSettings::IniFormat);
        settings->beginGroup(lvl_aktuell_stri);

        //Werte speichern
        settings->setValue("leben", ui->meh_lvl_leben_wert->text());
        settings->setValue("mana",  ui->meh_lvl_mana_wert->text());
        settings->setValue("kraft", ui->meh_lvl_kraft_wert->text());
        settings->setValue("ausdauer", ui->meh_lvl_ausdauer_wert->text());
        settings->setValue("intelligenz", ui->meh_lvl_intelligenz_wert->text());
        settings->setValue("verteidigung", ui->meh_lvl_verteidigung_wert->text());
        settings->setValue("glueck", ui->meh_lvl_glueck_wert->text());
        settings->setValue("ep", ui->meh_lvl_ep_wert->text());

        //Checkbox speichern
        settings->setValue("feuer", ui->meh_checkBox_feuer->checkState());
        settings->setValue("eis",   ui->meh_checkBox_eis->checkState());
        settings->setValue("betaeubt", ui->meh_checkBox_betaeubt->checkState());
        settings->setValue("gift",  ui->meh_checkBox_gift->checkState());
        settings->setValue("wind", ui->meh_checkBox_wind->checkState());
        settings->setValue("wasser", ui->meh_checkBox_wasser->checkState());
        settings->setValue("licht", ui->meh_checkBox_licht->checkState());
        settings->setValue("finsterniss", ui->meh_checkBox_finsterniss->checkState());

        //Spinbox speichern
        settings->setValue("feuer_pro", ui->meh_sp_feuer_wert->value());
        settings->setValue("eis_pro", ui->meh_sp_eis_wert->value());
        settings->setValue("betaeubt_pro", ui->meh_sp_betaeubt_wert->value());
        settings->setValue("gift_pro", ui->meh_sp_gift_wert->value());
        settings->setValue("wind_pro", ui->meh_sp_wind_wert->value());
        settings->setValue("wasser_pro", ui->meh_sp_wasser_wert->value());
        settings->setValue("licht_pro", ui->meh_sp_licht_wert->value());
        settings->setValue("finsterniss_pro", ui->meh_sp_finsterniss_wert->value());

        settings->endGroup();
        }
    }
}

void Main_Editor::item_namen_aendern_finished(QString editor_name, QListWidget *gewaehltes_item, QLineEdit *item_name)
// Bearbeitung (rename) des Namens vom gewählten Item mit Prüfung, ob es bereits existiert
{

    if (gewaehltes_item->currentItem() == NULL)
        {
            QMessageBox::critical (this, "Achtung", "Es wurde nichts ausgewaehlt.", QMessageBox::Ok);
        }
    else
        {
            QSettings pruefen_vorhanden (path_item + "/game/" +editor_name+ "/" +editor_name+ ".ini", QSettings::IniFormat);
            QStringList group = pruefen_vorhanden.childGroups();

            // Alle Werte werden sicherhalthalber auf 0 gesetzt
            int ist_n_gleich = 0;
            int child_name = 0;

            for(child_name = 0; child_name != group.size(); ++child_name)
                {
                    QString childVersion = group.at(child_name);

                    if(childVersion == item_name->text())
                        {
                            // wenn eine Übereinstimmung gefunden wurde, wird "ist_n_gleich" nichts hinzugefügt
                        }
                    else
                        {
                            ist_n_gleich++;
                        }
                }

            if (child_name == ist_n_gleich)
                {
                    // Variablen sind zu lang!!! //////////////////////////////////////////////////////
                    QListWidgetItem *item = gewaehltes_item->currentItem();
                    QStringList qlistwidgetitem_convert;
                    qlistwidgetitem_convert << item->text();
                    QString qlistwidgetitem_convert_qstring = qlistwidgetitem_convert.at(0);

                    QString name_vorher = gewaehltes_item->currentItem()->text();
                    QString name_widget = item_name->text();
                    gewaehltes_item->currentItem()->setText(name_widget);


                    QSettings *settings = new QSettings(path_item + "/game/" +editor_name+ "/" +editor_name+ ".ini",QSettings::IniFormat);
                    settings->remove(qlistwidgetitem_convert_qstring);

                    if (editor_name == "Held")
                    {
                        QFile::rename(path_item+ "/game/" +editor_name+ "/lvl_" + name_vorher + ".ini", path_item+ "/game/" +editor_name+ "/lvl_" + name_widget + ".ini");

                        qDebug() << path_item+ "/game/" +editor_name+ "/lvl_" + name_widget + ".ini";
                        qDebug() << path_item+ "/game/" +editor_name+ "/lvl_" + name_widget + ".ini";

                    //QString format = ".jpg"; //Workaround - MUSS VERBESSERT WERDEN

                        QFile::rename(path_item + "/game/" +editor_name+ "/" + name_vorher +"_gesicht.gif", path_item + "/game/" +editor_name+ "/" +item_name->text()+"_gesicht.gif");
                        QFile::rename(path_item + "/game/" +editor_name+ "/" + name_vorher +"_koerper.gif", path_item + "/game/" +editor_name+ "/" +item_name->text()+"_koerper.gif");
                   }

                    gewaehltes_item->sortItems(Qt::AscendingOrder);

                }
            else
                {
                    QMessageBox::critical (this, "Achtung", "Der Name \"" + ui->meh_name_item->text() + "\" wird bereits benutzt.", QMessageBox::Ok);
                }
            // Alle Werte werden wieder zurückgesetzt für den nächsten Durchlauf
            ist_n_gleich = 0;
            child_name = 0;
        }
}

void Main_Editor::item_pic_save(QString editor_name, QGraphicsView *editor_bild, QLineEdit*item_name, QString objekt)
// Speichern und Kopieren des Bildes in die .ini und den res Ordner(Funktion für jedes Objekt)
{
    if (editor_name == "Held" || "Gegner")
    {
        if (editor_name == "Held")
        {
        QString path_objekt_open = QFileDialog::getOpenFileName(this, tr("Avatar Bild waehlen"), "", tr("Images  (*.gif)"));
        QFile::remove(path_item + "/game/" +editor_name+ "/" +item_name->text()+ objekt+".gif");
        QFile::copy  (path_objekt_open, path_item + "/game/" +editor_name+ "/" +item_name->text()+ objekt+".gif");

        //Darstellung in GraphicsView
        QImage image(path_item + "/game/" +editor_name+ "/" +item_name->text()+ objekt+".gif");
        image = image.scaled( editor_bild->width()-10,ui->meh_gesicht_held_bild->height()-10);
        QGraphicsScene *objekt_qgs = new QGraphicsScene();
        objekt_qgs->addPixmap(QPixmap::fromImage(image));

            editor_bild->setScene(objekt_qgs);
        return;
        }

        if (editor_name == "Gegner")
        {
            QString path_objekt_open = QFileDialog::getOpenFileName(this, tr("Avatar Bild waehlen"), "", tr("Images  (*.gif)"));
            QFile::remove(path_item + "/game/" +editor_name+ "/" +item_name->text()+ objekt+".gif");
            QFile::copy  (path_objekt_open, path_item + "/game/" +editor_name+ "/" +item_name->text()+ objekt+".gif");

            //Darstellung in GraphicsView
            QImage image(path_item + "/game/" +editor_name+ "/" +item_name->text()+ objekt+".gif");
            image = image.scaled( editor_bild->width()-10,ui->meg_gesicht_gegner_bild->height()-10);
            QGraphicsScene *objekt_qgs = new QGraphicsScene();
            objekt_qgs->addPixmap(QPixmap::fromImage(image));

                editor_bild->setScene(objekt_qgs);
        return;
        }
    }

    if (editor_name == "Faehigkeit" || editor_name == "test")
    {
        QString path_objekt_open = QFileDialog::getOpenFileName(this, tr("Avatar Bild waehlen"), "", tr("Images  (*.gif)"));
        QFile::remove(path_item + "/game/" +editor_name+ "/" +item_name->text()+ objekt+".gif");
        QFile::copy  (path_objekt_open, path_item + "/game/" +editor_name+ "/" +item_name->text()+".gif");

        //Darstellung in GraphicsView
        QImage image(path_item + "/game/" +editor_name+ "/" +item_name->text()+".gif");
        image = image.scaled( editor_bild->width()-10,ui->meh_gesicht_held_bild->height()-10);
        QGraphicsScene *objekt_qgs = new QGraphicsScene();
        objekt_qgs->addPixmap(QPixmap::fromImage(image));

            editor_bild->setScene(objekt_qgs);
        return;
    }
}


  //----------------ENDE---------------//
 //----------Globale Funktionen------//
//----------------ENDE-------------//
