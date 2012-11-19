//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Hero Editor version 0.01.2.1
//
//
//
// Letzte Aenderung 19.11.2012
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "heroeditor.h"
#include "ui_heroeditor.h"
#include "heroeditor_core.cpp"


HeroEditor::HeroEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HeroEditor)


{
    ui->setupUi(this);
    setWindowTitle(tr("Hero Editor[*]"));

    // Umgebungs variabelen
    path_char = QApplication::applicationDirPath() + "/game/chars.ini";
    path_gesicht = QApplication::applicationDirPath() + "/res/Gesicht.jpg";
    path_koerper = QApplication::applicationDirPath() + "/res/Koerper.jpg";

    // LineEdit Buchstaben Sperre
    ui->lineEdit_name->setValidator(new QRegExpValidator( QRegExp("[0-9, A-Z, a-z]+"), this ));
    ui->lineEdit_Mana->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_ausdauer->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_Intelligenz->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_Kraft->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));
    ui->lineEdit_Leben->setValidator(new QRegExpValidator( QRegExp("[0-9]+"), this ));

    // Funktionen die Geladen werden
    qlist_namen_laden();
    //laden_char();

    //Statische werte
    zaehlrt = 0;
}

HeroEditor::~HeroEditor()

{
    delete ui;
}

void HeroEditor::on_okay_clicked()

{
    speichern_char();
    close();
}

void HeroEditor::on_gesicht_clicked()

{

    gesicht_char_laden();

}

void HeroEditor::on_Koerper_clicked()

{
   koerper_char_laden();
}

void HeroEditor::on_pushButton_held_neu_clicked()

{
    zaehlrt = zaehlrt + 1;
    QString zaehlrt_str;

    zaehlrt_str.append(QString("%1").arg(zaehlrt));

    ui->listWidget_helden->addItem("Neuer_Held" + zaehlrt_str);
    ui->lineEdit_name->setText("Neuer_Held" + zaehlrt_str);

    QSettings *settings = new QSettings(path_char,QSettings::IniFormat);
    settings->beginGroup("Held_Neu" + zaehlrt_str);
    settings->setValue("name",  ui->lineEdit_name->text());
    settings->endGroup();

}

void HeroEditor::on_pushButton_held_entfernen_clicked()

{
    QListWidgetItem *item = ui->listWidget_helden->currentItem();
    delete item;
}

void HeroEditor::on_lineEdit_name_editingFinished()

{
    QString name_vorher = ui->listWidget_helden->currentItem()->text();
    QString name_widget = ui->lineEdit_name->text();
    ui->listWidget_helden->currentItem()->setText(name_widget);


    QSettings *settings = new QSettings(path_char,QSettings::IniFormat);
    settings->beginGroup(name_vorher);
    settings->setValue("name",  name_widget);
    settings->endGroup();
}

void HeroEditor::on_listWidget_helden_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)

{
    QString helden_name = ui->listWidget_helden->currentItem()->text();
    ui->lineEdit_name->setText(helden_name);




    //Laden der Settings aus der .ini
    QSettings *settings = new QSettings (path_char, QSettings::IniFormat, this);

    settings->beginGroup(helden_name);
  //  QString name = settings->value("name").toString();
    QString leben = settings->value("leben").toString();
    QString mana = settings->value("mana").toString();
    QString kraft = settings->value("kraft").toString();
    QString ausdauer = settings->value("ausdauer").toString();
    QString Intelligenz = settings->value("Intelligenz").toString();

    bool feuer =settings->value("feuer").toBool();
    bool wind = settings->value("wind").toBool();
    bool gift = settings->value("gift").toBool();
    bool betaeubt = settings->value("betaeubt").toBool();
    bool eis = settings->value("eis").toBool();

    qint16 feuer_pro = settings->value("feuer_pro").toInt();
    qint16 eis_pro = settings->value("eis_pro").toInt();
    qint16 betaeubt_pro = settings->value("betaeubt_pro").toInt();
    qint16 gift_pro = settings->value("gift_pro").toInt();
    qint16 wind_pro = settings->value("wind_pro").toInt();


    settings->endGroup();


    //Sttings in die GUI laden (lineedit)
   // ui->lineEdit_name->setText(name);
    ui->lineEdit_Leben->setText(leben);
    ui->lineEdit_Mana->setText(mana);
    ui->lineEdit_Kraft->setText(kraft);
    ui->lineEdit_ausdauer->setText(ausdauer);
    ui->lineEdit_Intelligenz->setText(Intelligenz);

    //Sttings in die GUI laden (checkbox)
    ui->checkBox_feuer->setChecked(feuer);
    ui->checkBox_wind->setChecked(wind);
    ui->checkBox_gift->setChecked(gift);
    ui->checkBox_betaeubt->setChecked(betaeubt);
    ui->checkBox_eis->setChecked(eis);

    ui->spinBox_feuer->setValue(feuer_pro);
    ui->spinBox_eis->setValue(eis_pro);
    ui->spinBox_betaeubt->setValue(betaeubt_pro);
    ui->spinBox_gift->setValue(gift_pro);
    ui->spinBox_wind->setValue(wind_pro);


}
