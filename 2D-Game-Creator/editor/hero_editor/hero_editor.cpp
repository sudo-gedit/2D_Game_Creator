//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Hero Editor version 0.01.5.0
//
//
//
// Letzte Aenderung 21.01.2013
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include "hero_editor.h"
#include "hero_editor_void.cpp"
#include <QVector>


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
    laden_sprache();
    lvl_laden();

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
   loeschen_table_gesamt();
   laden_tabele("ep", 1066, 479, 150, 150);
}

void Hero_Editor::on_lineEdit_Leben_editingFinished()
{
    lvl_speichern();
    loeschen_table_gesamt();
    laden_tabele("leben", 910, 10, 150, 150);
}

void Hero_Editor::on_lineEdit_Mana_editingFinished()
{
    lvl_speichern();
    loeschen_table_gesamt();
    laden_tabele("mana", 1066 , 10, 150, 150);
}

void Hero_Editor::on_lineEdit_Kraft_editingFinished()
{
    lvl_speichern();
    loeschen_table_gesamt();
    laden_tabele("kraft", 910 , 166, 150, 150);
}

void Hero_Editor::on_lineEdit_ausdauer_editingFinished()
{
    lvl_speichern();
    loeschen_table_gesamt();
    laden_tabele("ausdauer", 1066 , 167, 150, 150);
}

void Hero_Editor::on_lineEdit_intelligenz_editingFinished()
{
    lvl_speichern();
    loeschen_table_gesamt();
    laden_tabele("intelligenz", 910 , 323, 150, 150);
}

void Hero_Editor::on_lineEdit_verteidigung_editingFinished()
{
    lvl_speichern();
    loeschen_table_gesamt();
    laden_tabele("verteidigung", 1066 , 323, 150, 150);
}

void Hero_Editor::on_lineEdit_glueck_editingFinished()
{
    lvl_speichern();
    loeschen_table_gesamt();
    laden_tabele("glueck", 910, 479, 150, 150);
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
