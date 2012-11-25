//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Hero Editor version 0.01.2.1
//
//
//
// Letzte Aenderung 24.11.2012
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "heroeditor.h"
#include "ui_heroeditor.h"


void HeroEditor::speichern_char() // Werte von dem gewaellten Charakter speichern

{
    //Lineedit Speiern
    QSettings *settings = new QSettings(path_char,QSettings::IniFormat);
    settings->beginGroup(ui->lineEdit_name->text());

    settings->setValue("name",  ui->lineEdit_name->text());
    settings->setValue("leben", ui->lineEdit_Leben->text());
    settings->setValue("mana",  ui->lineEdit_Mana->text());
    settings->setValue("kraft", ui->lineEdit_Kraft->text());
    settings->setValue("ausdauer", ui->lineEdit_ausdauer->text());
    settings->setValue("Intelligenz", ui->lineEdit_Intelligenz->text());

    //Checkbox Speichern
    settings->setValue("feuer", ui->checkBox_feuer->checkState());
    settings->setValue("eis",   ui->checkBox_eis->checkState());
    settings->setValue("betaeubt", ui->checkBox_betaeubt->checkState());
    settings->setValue("gift",  ui->checkBox_gift->checkState());
    settings->setValue("wind", ui->checkBox_wind->checkState());

    //Spinbox Speichern

    settings->setValue("feuer_pro", ui->spinBox_feuer->value());
    settings->setValue("eis_pro", ui->spinBox_eis->value());
    settings->setValue("betaeubt_pro", ui->spinBox_betaeubt->value());
    settings->setValue("gift_pro", ui->spinBox_gift->value());
    settings->setValue("wind_pro", ui->spinBox_wind->value());


    settings->endGroup();

}

void HeroEditor::char_pic_speichern(QString objekt)

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

    QSettings *objekt_qsettings_speichern_pic = new QSettings(path_char,QSettings::IniFormat);
        objekt_qsettings_speichern_pic->beginGroup(name_held);
        objekt_qsettings_speichern_pic->setValue(objekt, "/game/res/" + objekt + name_held + format);
        objekt_qsettings_speichern_pic->endGroup();

}



void HeroEditor::qlist_namen_laden()
// Helden werden aus der ini in qlistWidget_helden geladen
{
    QSettings settings (path_char, QSettings::IniFormat);
    QStringList group = settings.childGroups();
    for(int child = 0; child != group.size(); ++child)

    {
            QString childVersion = group.at(child);
            ui->listWidget_helden->addItem(childVersion);
    }

}
