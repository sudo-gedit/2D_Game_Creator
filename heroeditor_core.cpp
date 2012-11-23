//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Hero Editor version 0.01.2.1
//
//
//
// Letzte Aenderung 23.11.2012
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

void HeroEditor::gesicht_char_laden()

{
    //// verbessern
    QDir mdir;
    QString mpath = QApplication::applicationDirPath() + "/res/";
    mdir.mkpath(mpath);

    //Auswahl Bild für Gesicht und Autoentfernung des alten Bildes
    QString path_gesicht_open = QFileDialog::getOpenFileName(this, tr("Avatar Bild waehlen"), "", tr("Images  (*.png *.xpm *.jpg)"));
    QFile::remove(path_gesicht);
    QFile::copy ( path_gesicht_open, path_gesicht);
    //Darstellung in GraphicsView
    QImage image( path_gesicht );
    QGraphicsScene *gesicht = new QGraphicsScene();
    gesicht->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView_gesicht->setScene(gesicht);

}

void HeroEditor::koerper_char_laden()

{
    QDir mdir;
    QString mpath = QApplication::applicationDirPath() + "/res/";
    mdir.mkpath(mpath);

    //Auswahl Bild für K und Auto entfernung des alten Bildes
    QString path_koerper_open = QFileDialog::getOpenFileName(this, tr("Avatar Bild wählen"), "", tr("Images  (*.png *.xpm *.jpg)"));
    QFile::remove(path_koerper);
    QFile::copy ( path_koerper_open, path_koerper);
    //Darstellung in GraphicsView
    QImage image( path_koerper);
    QGraphicsScene *koerper = new QGraphicsScene();
    koerper->addPixmap(QPixmap::fromImage(image));
    ui->graphicsView_koerper->setScene(koerper);

}


void HeroEditor::qlist_namen_laden()

{
    QSettings settings (path_char, QSettings::IniFormat);
    QStringList group = settings.childGroups();
    for(int child = 0; child != group.size(); ++child)

    {
            QString childVersion = group.at(child);
            settings.endGroup();
            ui->listWidget_helden->addItem(childVersion);
    }


}
