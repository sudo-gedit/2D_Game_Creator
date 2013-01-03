//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Monster Editor version 0.01.2.3
//
//Es kann sein dass noch variablen den namen Hero Tragen aber das ist erstmal nicht so schlimm
//
// Letzte Aenderung 27.11.2012
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include "monster_editor.h"
#include "monster_editor_void.cpp"
#include "ui_monster_editor.h"

Monster_Editor::Monster_Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Monster_Editor)

{
    //Male Fenster
    ui->setupUi(this);
    setWindowTitle(tr("Monster Editor[*]"));
    setFixedSize(1200, 685);

    // Umgebungs Variabelen
    path_config = QApplication::applicationDirPath() + "/game/config.ini";
    path_char = QApplication::applicationDirPath() + "/game/monster.ini";
    path_res = QApplication::applicationDirPath() + "/game/res/";

    // LineEdit Buchstaben Sperre
    ui->lineEdit_name->setValidator(new QRegExpValidator( QRegExp("[0-9, A-Z, a-z]+"), this ));
    ui->lineEdit_Mana->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_ausdauer->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_intelligenz->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_Kraft->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_Leben->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_verteidigung->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));

    // Funktionen die geladen werden
    qlist_namen_laden();

}

Monster_Editor::~Monster_Editor()

{
    delete ui;
}

void Monster_Editor::on_okay_clicked()
//Funktion um vom gewaellten Helden zu alle Werte zu Speichern (Button)
{
    speichern_char();
}

void Monster_Editor::on_gesicht_clicked()
//Funktion um das Gesicht des Helden zu Speichern (laden)
{
    objekt = "gesicht_";
    char_pic_speichern(objekt);
}

void Monster_Editor::on_Koerper_clicked()
//Funktion um das Koerper des Helden zu Speichern (laden)
{
    objekt = "koerper_";
    char_pic_speichern(objekt);
}

void Monster_Editor::on_pushButton_monster_neu_clicked()
//Funktion um einen neuen Helden zu erstellen
{
    int count = ui->listWidget_monster->count();

    //Die erstellung des Monsters
    count = count + 1;
    QString count_str;

    count_str.append(QString("%1").arg(count));
    ui->listWidget_monster->addItem("Neues_Monster" + count_str);
    ui->lineEdit_name->setText("Neuer_Monster" + count_str);

    QSettings *settings = new QSettings(path_char,QSettings::IniFormat);
        settings->beginGroup("Neuer_Monster" + count_str);
        settings->setValue("name",  ui->lineEdit_name->text());
        settings->endGroup();
}

void Monster_Editor::on_pushButton_monster_entfernen_clicked()
//Funktion um den gewaellten Monster zu loeschen (mit Pruefmechanismus)
{
    int count = ui->listWidget_monster->count();

    if (count == 1)
    {
        QMessageBox::critical(this, "Achtung", "Du versuchst den letzten Helden zu loeschen, das ist nicht moeglich.", QMessageBox::Ok);
    }

        else
        {

            if    (ui->listWidget_monster->currentItem() == 0) {

            QMessageBox::critical(this, "Achtung", "Es wurde kein Held gewaehlt.", QMessageBox::Ok);

        }
            else
            {
                        QListWidgetItem *item = ui->listWidget_monster->currentItem();
                        QStringList qlistwidgetitem_convert;
                        qlistwidgetitem_convert << item->text();
                        QString qlistwidgetitem_convert_qstring = qlistwidgetitem_convert.at(0);

                        //Workaround
                        delete item;
                        //Workaround

                        QSettings *settings = new QSettings(path_char,QSettings::IniFormat);
                        settings->remove (qlistwidgetitem_convert_qstring);

        }
    }
}


void Monster_Editor::on_pushButton_schliessen_clicked()
{
     close();
}
