//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Hero Editor version 0.01.5.0
//
//
//
// Letzte Aenderung 03.01.2013
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include "hero_editor.h"
#include "hero_editor_void.cpp"


Hero_Editor::Hero_Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hero_Editor)

{
    //Male Fenster
    ui->setupUi(this);
    setWindowTitle(tr("Hero Editor[*]"));
    setFixedSize(890, 685);

    // Umgebungs Variabelen
    path_charaktaere = QApplication::applicationDirPath() + "/game/charaktaere/";
    path_res = QApplication::applicationDirPath() + "/game/res/";

    // LineEdit Buchstaben Sperre
    ui->lineEdit_name->setValidator(new QRegExpValidator( QRegExp("[0-9, A-Z, a-z]+"), this ));
    ui->lineEdit_Mana->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_ausdauer->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_intelligenz->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_Kraft->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_Leben->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_verteidigung->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_ep->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_glueck->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));

    // Funktionen die geladen werden
    qlist_namen_laden();

    ////////////////
    //Platzhalter (Optik) für die Graphic View
    ////////////////
    QGraphicsScene *scene = new QGraphicsScene();
    scene->addText("Leben");
    scene->setBackgroundBrush(QColor(233, 0, 0));
    ui->graphicsView_lvl_leben->setScene(scene);

    QGraphicsScene *scene_1 = new QGraphicsScene();
    scene_1->addText("Mana");
    scene_1->setBackgroundBrush(QColor(0, 0, 255));
    ui->graphicsView_lvl_mana->setScene(scene_1);

    QGraphicsScene *scene_2 = new QGraphicsScene();
    scene_2->addText("LVL");
    scene_2->setBackgroundBrush(QColor(0, 205, 205));
    ui->graphicsView_lvl->setScene(scene_2);

    QGraphicsScene *scene_3 = new QGraphicsScene();
    scene_3->addText("Glueck");
    scene_3->setBackgroundBrush(QColor(0, 205, 0));
    ui->graphicsView_lvl_glueck->setScene(scene_3);

    QGraphicsScene *scene_4 = new QGraphicsScene();
    scene_4->addText("Verteidigung");
    scene_4->setBackgroundBrush(QColor(189, 183, 107));
    ui->graphicsView_lvl_verteidigung->setScene(scene_4);

    QGraphicsScene *scene_5 = new QGraphicsScene();
    scene_5->addText("Intelligenz");
    scene_5->setBackgroundBrush(QColor(255, 255, 0));
    ui->graphicsView_lvl_intelligenz->setScene(scene_5);

    QGraphicsScene *scene_6 = new QGraphicsScene();
    scene_6->addText("Ausdauer");
    scene_6->setBackgroundBrush(QColor(105, 105, 105));
    ui->graphicsView_lvl_ausdauer->setScene(scene_6);

    QGraphicsScene *scene_7 = new QGraphicsScene();
    scene_7->addText("Kraft");
    scene_7->setBackgroundBrush(QColor(0, 205, 205));
    ui->graphicsView_lvl_kraft->setScene(scene_7);
    ////////////////

}

Hero_Editor::~Hero_Editor()

{
    delete ui;
}

void Hero_Editor::on_okay_clicked()
//Funktion um vom gewaellten Helden zu alle Werte zu Speichern (Button)
{
    speichern_char();
}

void Hero_Editor::on_gesicht_clicked()
//Funktion um das Gesicht des Helden zu Speichern (laden)
{
if    (ui->listWidget_helden->currentItem() == 0)
    {
    QMessageBox::critical(this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);
    }
        else
            {
            objekt = "gesicht_";
            char_pic_speichern(objekt);
            }
}

void Hero_Editor::on_Koerper_clicked()
//Funktion um das Koerper des Helden zu Speichern (laden)
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
//Funktion um einen neuen Helden zu erstellen
{
    int count = ui->listWidget_helden->count();

    //Die erstellung des Helden
    count = count + 1;
    QString count_str;

    count_str.append(QString("%1").arg(count));
    ui->listWidget_helden->addItem("Neuer_Held" + count_str);
    ui->lineEdit_name->setText("Neuer_Held" + count_str);

    QSettings *settings = new QSettings(path_charaktaere + "chars.ini",QSettings::IniFormat);
        settings->beginGroup("Neuer_Held" + count_str);
        settings->setValue("name",  ui->lineEdit_name->text());
        settings->endGroup();
}

void Hero_Editor::on_pushButton_held_entfernen_clicked()
//Funktion um den gewaellten Helden zu loeschen (mit Pruefmechanismus)
{
    int count = ui->listWidget_helden->count();

    if (count == 1)
    {
        QMessageBox::critical(this, "Achtung", "Du versuchst den letzten Helden zu loeschen, das ist nicht moeglich.", QMessageBox::Ok);
    }

        else
        {

            if    (ui->listWidget_helden->currentItem() == 0) {

            QMessageBox::critical(this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);

        }
            else
            {
                        QListWidgetItem *item = ui->listWidget_helden->currentItem();
                        QStringList qlistwidgetitem_convert;
                        qlistwidgetitem_convert << item->text();
                        QString qlistwidgetitem_convert_qstring = qlistwidgetitem_convert.at(0);

                        //Workaround
                        delete item;
                        //Workaround

                        QSettings *settings = new QSettings(path_charaktaere + "chars.ini",QSettings::IniFormat);
                        settings->remove (qlistwidgetitem_convert_qstring);

                        QFile::remove(path_charaktaere + "lvl_" + qlistwidgetitem_convert_qstring + ".ini");
        }
    }
}

void Hero_Editor::on_pushButton_lvl_up_editor_clicked()
{

    if (lvl_up_editor_bool == true)
    {
        setFixedSize(890, 685);
        lvl_up_editor_bool = false;
        ui->pushButton_lvl_up_editor->setText("LVL-UP Editor");
    }
    else
     {
        setFixedSize(1250, 685);
        lvl_up_editor_bool = true;
        ui->pushButton_lvl_up_editor->setText("Verbergen");
     }

}


void Hero_Editor::on_pushButton_schliessen_clicked()
{
     close();
}


void Hero_Editor::on_spinBox_lvl_valueChanged()
{
    lvl_laden();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//Start-Speichern der Werte (LVL Editor)
//////////////////////////////////////////////////////////////////////////////////////////////////////

void Hero_Editor::on_lineEdit_ep_editingFinished()
{
   lvl_speichern();
}

void Hero_Editor::on_lineEdit_Leben_editingFinished()
{
    lvl_speichern();
}

void Hero_Editor::on_lineEdit_Mana_editingFinished()
{
    lvl_speichern();
}

void Hero_Editor::on_lineEdit_Kraft_editingFinished()
{
    lvl_speichern();
}

void Hero_Editor::on_lineEdit_ausdauer_editingFinished()
{
    lvl_speichern();
}

void Hero_Editor::on_lineEdit_intelligenz_editingFinished()
{
    lvl_speichern();
}

void Hero_Editor::on_lineEdit_verteidigung_editingFinished()
{
    lvl_speichern();
}

void Hero_Editor::on_lineEdit_glueck_editingFinished()
{
    lvl_speichern();
}

void Hero_Editor::on_spinBox_eis_editingFinished()
{
    lvl_speichern();
}

void Hero_Editor::on_spinBox_feuer_editingFinished()
{
    lvl_speichern();
}

void Hero_Editor::on_spinBox_wind_editingFinished()
{
    lvl_speichern();
}

void Hero_Editor::on_spinBox_gift_editingFinished()
{
    lvl_speichern();
}

void Hero_Editor::on_spinBox_betaeubt_editingFinished()
{
    lvl_speichern();
}

void Hero_Editor::on_checkBox_betaeubt_clicked()
{
    lvl_speichern();
}

void Hero_Editor::on_checkBox_gift_clicked()
{
    lvl_speichern();
}

void Hero_Editor::on_checkBox_wind_clicked()
{
    lvl_speichern();
}

void Hero_Editor::on_checkBox_feuer_clicked()
{
    lvl_speichern();
}

void Hero_Editor::on_checkBox_eis_clicked()
{
    lvl_speichern();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//ENDE-Speichern der Werte (LVL Editor)
//////////////////////////////////////////////////////////////////////////////////////////////////////

void Hero_Editor::on_pushButton_4_clicked()
{
    qlist_namen_laden();
}
