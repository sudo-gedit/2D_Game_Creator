#include "hero_editor.h"
#include "ui_hero_editor.h"

void Hero_Editor::speichern_char()
// Namen von dem gewählten Charakter speichern in die .ini
{
    //Lineedit Speichern
    QSettings *settings = new QSettings(path_charaktaere + "chars.ini",QSettings::IniFormat);
    settings->beginGroup(ui->lineEdit_name->text());
    settings->setValue("name",  ui->lineEdit_name->text());
    settings->setValue("gesicht_", "/game/res/gesicht_" + ui->lineEdit_name->text() + ".jpg");
    settings->setValue("koerper_", "/game/res/koerper_" + ui->lineEdit_name->text() + ".jpg");

    settings->endGroup();

    ui->listWidget_helden->sortItems(Qt::AscendingOrder);
}

void Hero_Editor::char_pic_speichern(QString objekt)
// Speichern und Kopieren des Bildes in die .ini und den res Ordner
{
    QString format = ".jpg"; //Workaround
    QString name_held = ui->listWidget_helden->currentItem()->text();


    //// verbessern (if?)
    QDir mdir;
    QString mpath = QApplication::applicationDirPath() + "/game/res/";
    mdir.mkpath(mpath);

    //Auswahl Bild für Gesicht und Auto Entfernung des alten Bildes
    QString path_objekt_open = QFileDialog::getOpenFileName(this, tr("Avatar Bild waehlen"), "", tr("Images  (*.png *.xpm *.jpg)"));
    QFile::remove(path_res + objekt + name_held + format);
    QFile::copy ( path_objekt_open, path_res + objekt + name_held + format);

    //Darstellung in GraphicsView
    QImage image( path_res + objekt + name_held + format );
    image = image.scaled(this->ui->graphicsView_gesicht->width()-10,ui->graphicsView_gesicht->height()-10);
    QGraphicsScene *objekt_qgs = new QGraphicsScene();
    objekt_qgs->addPixmap(QPixmap::fromImage(image));

    if (objekt == "gesicht_")

    {
        ui->graphicsView_gesicht->setScene(objekt_qgs);
    }

    else

    {
        ui->graphicsView_koerper->setScene(objekt_qgs);
    }

    QSettings *objekt_qsettings_speichern_pic = new QSettings(path_charaktaere + "chars.ini",QSettings::IniFormat);
        objekt_qsettings_speichern_pic->beginGroup(name_held);
        objekt_qsettings_speichern_pic->setValue(objekt, "/game/res/" + objekt + name_held + format);
        objekt_qsettings_speichern_pic->endGroup();
}

void Hero_Editor::qlist_namen_laden()
// Helden (alle) werden aus der ini in qlistWidget_helden geladen
{
    QFile file(path_charaktaere + "chars.ini");

      if( !file.exists() )
      {

      }
      else
        {
        QSettings settings (path_charaktaere + "chars.ini", QSettings::IniFormat);
        QStringList group = settings.childGroups();
        for(int child = 0; child != group.size(); ++child)
        {
            QString childVersion = group.at(child);
            ui->listWidget_helden->addItem(childVersion);
            }
        ui->listWidget_helden->item(0)->setSelected(true);
        }
}

void Hero_Editor::on_lineEdit_name_editingFinished()
// Bearbeitung des Namens vom gewählten Helden mit Prüfung ob bereits existiert
{
    if    (ui->listWidget_helden->currentItem() == 0) {

            QMessageBox::critical (this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);

           }
    else
    {
        QSettings pruefen_vorhanden (path_charaktaere + "chars.ini", QSettings::IniFormat);
        QStringList group = pruefen_vorhanden.childGroups();

        // Alle Werte werden sicherhalthalber auf 0 gesetzt
        ist_n_gleich = 0;
        child_name = 0;

        for(child_name = 0; child_name != group.size(); ++child_name)
       {
            QString childVersion = group.at(child_name);

            if(childVersion == ui->lineEdit_name->text())
            {
                // wenn eine Übereinstimmung gefunden wurde wird "ist_n_gleich" nichts hinzugefügt
            }
            else
            {
                ist_n_gleich++;
            }
       }

        if (child_name == ist_n_gleich)
        {
        // variablen sind zu lang!!!
            QListWidgetItem *item = ui->listWidget_helden->currentItem();
            QStringList qlistwidgetitem_convert;
            qlistwidgetitem_convert << item->text();
            QString qlistwidgetitem_convert_qstring = qlistwidgetitem_convert.at(0);

            QString name_vorher = ui->listWidget_helden->currentItem()->text();
            QString name_widget = ui->lineEdit_name->text();
            ui->listWidget_helden->currentItem()->setText(name_widget);


            QSettings *settings = new QSettings(path_charaktaere + "chars.ini",QSettings::IniFormat);
            settings->remove(qlistwidgetitem_convert_qstring);

            QFile file_ini (path_charaktaere + "lvl_" + name_vorher + ".ini");
            file_ini.rename(path_charaktaere + "lvl_" + name_vorher + ".ini", path_charaktaere + "lvl_" + name_widget + ".ini");


            QString format = ".jpg"; //Workaround

            QFile file_gesicht(path_res + "gesicht_" + name_vorher + format);
            file_gesicht.rename(path_res + "gesicht_" + name_vorher + format, path_res + "gesicht_" + name_widget + format);

            QFile file_koerper(path_res + "koerper_" + name_vorher + format);
            file_koerper.rename(path_res + "koerper_" + name_vorher + format, path_res + "koerper_" + name_widget + format);

            speichern_char();
        }
        else
        {
            QMessageBox::critical (this, "Achtung", "Der Name \"" + ui->lineEdit_name->text() + "\" wird bereits benutzt.", QMessageBox::Ok);
        }
        // Alle Werte werden wieder zurückgesetzt für den nächsten Durchlauf
            ist_n_gleich = 0;
            child_name = 0;
    }
}

void Hero_Editor::on_listWidget_helden_currentItemChanged()
// Werte von dem gewählten Charakter laden (Bilder, Werte, Tabelle)
{
    path_res_ = QApplication::applicationDirPath() + "";

    QString helden_name = ui->listWidget_helden->currentItem()->text();
    ui->lineEdit_name->setText(helden_name);


    //Laden der Settings aus der .ini
    QSettings *settings = new QSettings (path_charaktaere + "chars.ini", QSettings::IniFormat, this);

    settings->beginGroup(helden_name);

    QString gesicht_ = settings->value("gesicht_").toString();
    QString koerper_ = settings->value("koerper_").toString();

    settings->endGroup();

    QFile gesicht_file( path_res_ + gesicht_ );
    QFile koerper_file( path_res_ + koerper_ );

    if (!gesicht_file.exists())
    {
        QList<QGraphicsItem*> item = ui->graphicsView_gesicht->items();
        qDeleteAll(item);
    }
    else
    {
        QImage image_gesicht(path_res_ + gesicht_);
        image_gesicht = image_gesicht.scaled(this->ui->graphicsView_gesicht->width()-10,this->ui->graphicsView_gesicht->height()-10);
        QGraphicsScene *gesicht = new QGraphicsScene();
        gesicht->addPixmap(QPixmap::fromImage(image_gesicht));
        ui->graphicsView_gesicht->setScene(gesicht);
    }

    if (!koerper_file.exists())
    {
        QList<QGraphicsItem*> item = ui->graphicsView_koerper->items();
        qDeleteAll(item);
    }
    else
    {
        QImage image_koerper(path_res_ + koerper_);
        image_koerper = image_koerper.scaled(this->ui->graphicsView_gesicht->width()-10,this->ui->graphicsView_gesicht->height()-10);
        QGraphicsScene *koerper = new QGraphicsScene();
        koerper->addPixmap(QPixmap::fromImage(image_koerper));
        ui->graphicsView_koerper->setScene(koerper);
    }
    lvl_laden();
    loeschen_table_gesamt();
    laden_table_gesamt();
}

void Hero_Editor::lvl_speichern()
// Werte von dem gewählten Charakter speichern (Werte)
{
        if    (ui->listWidget_helden->currentItem() == 0)
            // Sollte kein Held gewählt sein, werden alle Parameter zurück gesetzt.
        {
        QMessageBox::critical(this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);

        ui->checkBox_betaeubt->setCheckState(Qt::Unchecked);
        ui->checkBox_eis->setCheckState(Qt::Unchecked);
        ui->checkBox_feuer->setCheckState(Qt::Unchecked);
        ui->checkBox_gift->setCheckState(Qt::Unchecked);
        ui->checkBox_wind->setCheckState(Qt::Unchecked);

        ui->lineEdit_ausdauer->clear();
        ui->lineEdit_ep->clear();
        ui->lineEdit_glueck->clear();
        ui->lineEdit_intelligenz->clear();
        ui->lineEdit_Kraft->clear();
        ui->lineEdit_Leben->clear();
        ui->lineEdit_Mana->clear();
        ui->lineEdit_name->clear();
        ui->lineEdit_verteidigung->clear();

        ui->spinBox_betaeubt->clear();
        ui->spinBox_eis->clear();
        ui->spinBox_feuer->clear();
        ui->spinBox_gift->clear();
        ui->spinBox_wind->clear();
        }
        else
        {
        QString held_name = ui->listWidget_helden->currentItem()->text();
        int spinbox_lvl_aktuell = ui->spinBox_lvl->value();
        QString lvl_aktuell_stri = QString::number(spinbox_lvl_aktuell);

        path_char_lvl = QApplication::applicationDirPath() + "/game/charaktaere/lvl_"+ held_name +".ini";


        QSettings *settings = new QSettings(path_char_lvl,QSettings::IniFormat);
        settings->beginGroup(lvl_aktuell_stri);

        //Werte speichern
        settings->setValue("leben", ui->lineEdit_Leben->text());
        settings->setValue("mana",  ui->lineEdit_Mana->text());
        settings->setValue("kraft", ui->lineEdit_Kraft->text());
        settings->setValue("ausdauer", ui->lineEdit_ausdauer->text());
        settings->setValue("intelligenz", ui->lineEdit_intelligenz->text());
        settings->setValue("verteidigung", ui->lineEdit_verteidigung->text());
        settings->setValue("glueck", ui->lineEdit_glueck->text());
        settings->setValue("ep", ui->lineEdit_ep->text());

        //Checkbox speichern
        settings->setValue("feuer", ui->checkBox_feuer->checkState());
        settings->setValue("eis",   ui->checkBox_eis->checkState());
        settings->setValue("betaeubt", ui->checkBox_betaeubt->checkState());
        settings->setValue("gift",  ui->checkBox_gift->checkState());
        settings->setValue("wind", ui->checkBox_wind->checkState());

        //Spinbox speichern
        settings->setValue("feuer_pro", ui->spinBox_feuer->value());
        settings->setValue("eis_pro", ui->spinBox_eis->value());
        settings->setValue("betaeubt_pro", ui->spinBox_betaeubt->value());
        settings->setValue("gift_pro", ui->spinBox_gift->value());
        settings->setValue("wind_pro", ui->spinBox_wind->value());
        settings->endGroup();
        }
}

void Hero_Editor::lvl_laden()
// Werte von dem gewählten Charakter laden (Werte)
{
    QString held_name = ui->lineEdit_name->text();
    int spinbox_lvl_aktuell = ui->spinBox_lvl->value();
    QString lvl_aktuell_stri = QString::number(spinbox_lvl_aktuell);

    path_char_lvl = QApplication::applicationDirPath() + "/game/charaktaere/lvl_"+ held_name +".ini";

    //Laden der Settings (Werten/Einstellungen) aus der .ini
    QSettings *settings = new QSettings (path_char_lvl, QSettings::IniFormat, this);
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

    int feuer_pro = settings->value("feuer_pro").toInt();
    int eis_pro = settings->value("eis_pro").toInt();
    int betaeubt_pro = settings->value("betaeubt_pro").toInt();
    int gift_pro = settings->value("gift_pro").toInt();
    int wind_pro = settings->value("wind_pro").toInt();

    settings->endGroup();


    //Sttings in die GUI laden (lineEdit)
    ui->lineEdit_Leben->setText(leben);
    ui->lineEdit_Mana->setText(mana);
    ui->lineEdit_Kraft->setText(kraft);
    ui->lineEdit_ausdauer->setText(ausdauer);
    ui->lineEdit_intelligenz->setText(intelligenz);
    ui->lineEdit_verteidigung->setText(verteidigung);
    ui->lineEdit_glueck->setText(glueck);
    ui->lineEdit_ep->setText(ep);

    //Sttings in die GUI laden (checkBox)
    ui->checkBox_feuer->setChecked(feuer);
    ui->checkBox_wind->setChecked(wind);
    ui->checkBox_gift->setChecked(gift);
    ui->checkBox_betaeubt->setChecked(betaeubt);
    ui->checkBox_eis->setChecked(eis);

    //Sttings in die GUI laden (spinBox)
    ui->spinBox_feuer->setValue(feuer_pro);
    ui->spinBox_eis->setValue(eis_pro);
    ui->spinBox_betaeubt->setValue(betaeubt_pro);
    ui->spinBox_gift->setValue(gift_pro);
    ui->spinBox_wind->setValue(wind_pro);

    spinbox_disable();
}

void Hero_Editor::laden_sprache()
// Funktion um eine Sprache zu laden aus der .ini und gleich zu benutzen
{
    QTranslator language;
    QString sprache;
    QString path_config_app = QApplication::applicationDirPath() + "/config.ini";

    QSettings *settings = new QSettings (path_config_app, QSettings::IniFormat, this);
    settings->beginGroup("config");
        sprache = settings->value("sprache").toString();
    settings->endGroup();

    if (sprache == "Deutsch/German")
    {
        language.load("german_DE");
        qApp->installTranslator(&language);
        ui->retranslateUi(this);
    }

    if (sprache == "Englisch/English")
    {
        language.load("english_UK");
        qApp->installTranslator(&language);
        ui->retranslateUi(this);
    }

    if (sprache == "Russisch/Russia")
    {
        language.load("russia_RUS");
        qApp->installTranslator(&language);
        ui->retranslateUi(this);
    }

    if (sprache == "Franzoesisch/French")
    {
        language.load("french_FRA");
        qApp->installTranslator(&language);
        ui->retranslateUi(this);
    }
}

void Hero_Editor::on_pushButton_lvl_up_editor_clicked()
// Aufklappen des LVL-Editors und ...
{

    if (lvl_up_editor_bool == true)
    {
        setFixedSize(890, 685);
        lvl_up_editor_bool = false;
        ui->pushButton_lvl_up_editor->setText("LVL-UP Editor");
    }
    else
     {
        if (ui->listWidget_helden->currentItem() == NULL) // Prüfen ob überhaupt werte vorliegen (bzw. die .ini)
        {
            // wenn keine vorliegen wir auch nichts gemacht
        }
        else
        {
             if (this->plots.find("ep") != this->plots.end())
             {
                 loeschen_table_gesamt();
                 laden_table_gesamt();
             }

             if (this->plots.find("ep") != this->plots.end())
             {
                 loeschen_table_gesamt();
                 laden_table_gesamt();
             }
        }
        setFixedSize(1250, 685);
        lvl_up_editor_bool = true;
        ui->pushButton_lvl_up_editor->setText("Verbergen");
     }

}

void Hero_Editor::on_pushButton_held_entfernen_clicked()
// Funktion um den gewählten Helden zu löschen (mit Prüfmechanismus)
{
    // Prüfen wie viele Helden noch existieren
    int count = ui->listWidget_helden->count();

    if (count == 1)
    {
        QMessageBox::critical(this, "Achtung", "Du versuchst den letzten Helden zu loeschen, das ist nicht moeglich.", QMessageBox::Ok);
        return;
    }
    // Prüfen ob überhaupt ein Held gewählt wurde
    if    (ui->listWidget_helden->currentItem() == NULL)
        {
    QMessageBox::critical(this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);
        }
    else
    {
        // Entwickler wird gefragt ob er wirklich löschen will
        int status;
        status = QMessageBox::question(this, "Info", "Soll der Held \"" + ui->lineEdit_name->text() + "\" wirklich geloescht werden?" , QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

        if (status == QMessageBox::Yes)
        {
            QListWidgetItem *item = ui->listWidget_helden->currentItem();
            QStringList qlistwidgetitem_convert;
            qlistwidgetitem_convert << item->text();
            QString qlistwidgetitem_convert_qstring = qlistwidgetitem_convert.at(0);

            delete item;

            QSettings *settings = new QSettings(path_charaktaere + "chars.ini",QSettings::IniFormat);
            settings->remove (qlistwidgetitem_convert_qstring);

            QFile::remove(path_charaktaere + "lvl_" + qlistwidgetitem_convert_qstring + ".ini");

            QString format = ".jpg"; //Workaround
            QFile::remove(path_res + "gesicht_" + qlistwidgetitem_convert_qstring + format);
            QFile::remove(path_res + "koerper_" + qlistwidgetitem_convert_qstring + format);
        }
        else
        {
            // Nein gewählt wird oder abgebrochen wird, passiert nichts
        }
        ui->listWidget_helden->sortItems(Qt::AscendingOrder);
    }
}

void Hero_Editor::on_gesicht_clicked()
// Funktion um das Gesicht des Helden zu Speichern
{
if    (ui->listWidget_helden->currentItem() == 0)
    {
    QMessageBox::critical (this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);
    }
        else
            {
            objekt = "gesicht_";
            char_pic_speichern(objekt);
            }
}

void Hero_Editor::on_Koerper_clicked()
// Funktion um das Körper des Helden zu Speichern
{
if    (ui->listWidget_helden->currentItem() == 0)
    {
    QMessageBox::critical(this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);
    }
        else
        {
        objekt = "koerper_";
        char_pic_speichern(objekt);
        }
}

void Hero_Editor::on_pushButton_held_neu_clicked()
// Funktion um einen neuen Helden zu erstellen
{
    name_held_qlist = "Neuer_Held";

    for (int i = 1; i <= 100; ++i)
    {
        QList<QListWidgetItem*> items = ui->listWidget_helden->findItems(name_held_qlist + QString::number(i), 0);

        if (items.empty())
        {
            // Die Erstellung des Helden

            ui->listWidget_helden->addItem(name_held_qlist + QString::number(i));
            ui->lineEdit_name->setText(name_held_qlist + QString::number(i));

            QSettings *settings = new QSettings(path_charaktaere + "chars.ini",QSettings::IniFormat);
                settings->beginGroup(name_held_qlist + QString::number(i));
                settings->setValue("name",  ui->lineEdit_name->text());
                settings->endGroup();

            QString held_name = ui->lineEdit_name->text();

            QFile file(path_charaktaere + "lvl_" + held_name + ".ini" );
                file.open(QIODevice::WriteOnly | QIODevice::Text);
            file.close();
            return;
        }
        ui->listWidget_helden->sortItems(Qt::AscendingOrder);
    }
}


QCustomPlot *Hero_Editor::getPlot(std::string name)
// Wertetabelle (lvl)
{
    return plots[name];
}

void Hero_Editor::addPlot(std::string name, int x, int y, int width, int height)
// Wertetabelle
{
    plots[name] = new QCustomPlot(this);
    getPlot(name)->setGeometry(x, y, width, height);
    getPlot(name)->addGraph();
}

void Hero_Editor::addPlotPoint(std::string name, double x, double y)
// Wertetabelle
{
    plotPoints[name]["x"].push_back(x);
    plotPoints[name]["y"].push_back(y);
}

void Hero_Editor::paintPlot(std::string name)
// Wertetabelle
{
    getPlot(name)->graph(0)->setData(plotPoints[name]["x"], plotPoints[name]["y"]);
    getPlot(name)->replot();
}

void Hero_Editor::laden_tabele(std::string name, int x, int y, int width, int height)
// Funktion um alle Werte der Werterabe zu Übergeben
{
    if    (ui->listWidget_helden->currentItem() == 0)
    {

    }
    else
    {
    addPlot(name, x, y, width, height);

    for (int i=0; i<100; i++)
        {
        QString lvl = QString::number(i);

        QString held_name = ui->listWidget_helden->currentItem()->text();
        path_char_lvl = QApplication::applicationDirPath() + "/game/charaktaere/lvl_"+ held_name +".ini";

        QSettings *settings = new QSettings (path_char_lvl, QSettings::IniFormat, this);
        settings->beginGroup(lvl);
        QString name_qstring(name.c_str());

        int wert = settings->value(name_qstring).toInt();
        settings->endGroup();

        addPlotPoint(name, i, wert);
    }
    getPlot(name)->xAxis->setRange(0, 100);
    getPlot(name)->yAxis->setRange(0, 100);
    paintPlot(name);
    getPlot(name)->show();
    }
}

void Hero_Editor::laden_table_gesamt()
// Funktion um alle Werte zu laden
{
    if    (ui->listWidget_helden->currentItem() == 0)
    {

    }
    else
    {
       laden_tabele("ep", 1066, 479, 150, 150);
       laden_tabele("leben", 910, 10, 150, 150);
       laden_tabele("mana", 1066 , 10, 150, 150);
       laden_tabele("kraft", 910 , 166, 150, 150);
       laden_tabele("ausdauer", 1066 , 167, 150, 150);
       laden_tabele("intelligenz", 910 , 323, 150, 150);
       laden_tabele("verteidigung", 1066 , 323, 150, 150);
       laden_tabele("glueck", 910, 479, 150, 150);
    }
}

void Hero_Editor::loeschen_table_gesamt()
// Funktion um alle Werte aus der Wertetabelle zu löschen
{
    if    (ui->listWidget_helden->currentItem() == 0)
    {

    }
    else
    {
        if (this->plots.find("ep") != this->plots.end())
        {
            plotPoints.clear();
            getPlot("ep")->graph(0)->clearData();
            plotPoints.clear();
        }

        if (this->plots.find("leben") != this->plots.end())
        {
            plotPoints.clear();
            getPlot("leben")->graph(0)->clearData();
            plotPoints.clear();
        }

        if (this->plots.find("mana") != this->plots.end())
        {
            plotPoints.clear();
            getPlot("mana")->graph(0)->clearData();
            plotPoints.clear();
        }

        if (this->plots.find("kraft") != this->plots.end())
        {
            plotPoints.clear();
            getPlot("kraft")->graph(0)->clearData();
            plotPoints.clear();
        }

        if (this->plots.find("ausdauer") != this->plots.end())
        {
            plotPoints.clear();
            getPlot("ausdauer")->graph(0)->clearData();
            plotPoints.clear();
        }

        if (this->plots.find("intelligenz") != this->plots.end())
        {
            plotPoints.clear();
            getPlot("intelligenz")->graph(0)->clearData();
            plotPoints.clear();
        }

        if (this->plots.find("verteidigung") != this->plots.end())
        {
            plotPoints.clear();
            getPlot("verteidigung")->graph(0)->clearData();
            plotPoints.clear();
        }

        if (this->plots.find("glueck") != this->plots.end())
        {
            plotPoints.clear();
            getPlot("glueck")->graph(0)->clearData();
            plotPoints.clear();
        }
    }
}

////////////////////////////////////////////
// Ausschalten/Einschalten von den Spinboxen
void Hero_Editor::on_checkBox_eis_clicked(bool checked)
{
    if (checked == true)
    {
        ui->spinBox_eis->setDisabled(false);
    }
    else
    {
        ui->spinBox_eis->setDisabled(true);
    }
}

void Hero_Editor::on_checkBox_feuer_clicked(bool checked)
{
    if (checked == true)
    {
        ui->spinBox_feuer->setDisabled(false);
    }
    else
    {
        ui->spinBox_feuer->setDisabled(true);
    }
}

void Hero_Editor::on_checkBox_wind_clicked(bool checked)
{
    if (checked == true)
    {
        ui->spinBox_wind->setDisabled(false);
    }
    else
    {
        ui->spinBox_wind->setDisabled(true);
    }
}

void Hero_Editor::on_checkBox_gift_clicked(bool checked)
{
    if (checked == true)
    {
        ui->spinBox_gift->setDisabled(false);
    }
    else
    {
        ui->spinBox_gift->setDisabled(true);
    }
}

void Hero_Editor::on_checkBox_betaeubt_clicked(bool checked)
{
    if (checked == true)
    {
        ui->spinBox_betaeubt->setDisabled(false);
    }
    else
    {
        ui->spinBox_betaeubt->setDisabled(true);
    }
}
////////////////////////////////////////////

void Hero_Editor::spinbox_disable()
// SpinBox Ausschalten wenn diese nicht gewählt wurde (Gesamtfunktion)
{
    if (eis == false)
    {
        ui->spinBox_eis->setDisabled(true);
    }
    else
    {
        ui->spinBox_eis->setDisabled(false);
    }

    if (feuer == false)
    {
        ui->spinBox_feuer->setDisabled(true);
    }
    else
    {
        ui->spinBox_feuer->setDisabled(false);
    }

    if (wind == false)
    {
        ui->spinBox_wind->setDisabled(true);
    }
    else
    {
        ui->spinBox_wind->setDisabled(false);
    }

    if (gift == false)
    {
        ui->spinBox_gift->setDisabled(true);
    }
    else
    {
        ui->spinBox_gift->setDisabled(false);
    }

    if (betaeubt == false)
    {
        ui->spinBox_betaeubt->setDisabled(true);
    }
    else
    {
        ui->spinBox_betaeubt->setDisabled(false);
    }
}
