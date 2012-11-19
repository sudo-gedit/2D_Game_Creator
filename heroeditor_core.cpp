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

void HeroEditor::laden_char() // Werte von dem gewaellten Charakter laden

{
    //Laden der Settings aus der .ini
    QSettings *settings = new QSettings (path_char, QSettings::IniFormat, this);

    settings->beginGroup("Charakter");
    QString name = settings->value("name").toString();
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
    ui->lineEdit_name->setText(name);
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


    /////////////////////////////////////////////////
    // Beide Bilder laden (Gesicht und Körper)
    /////////////////////////////////////////////////
    path_gesicht = QApplication::applicationDirPath() + "/res/Gesicht.jpg";
    path_koerper = QApplication::applicationDirPath() + "/res/Koerper.jpg";

    QImage image_gesicht(path_gesicht);
    QGraphicsScene *gesicht = new QGraphicsScene();
    gesicht->addPixmap(QPixmap::fromImage(image_gesicht));
    ui->graphicsView_gesicht->setScene(gesicht);


    QImage image_koerper(path_koerper);
    QGraphicsScene *koerper = new QGraphicsScene();
    koerper->addPixmap(QPixmap::fromImage(image_koerper));
    ui->graphicsView_koerper->setScene(koerper);
    /////////////////////////////////////////////////
    // ENDE
    /////////////////////////////////////////////////


}

void HeroEditor::gesicht_char_laden()

{
    //// verbessern
    QDir mdir;
    QString mpath = QApplication::applicationDirPath() + "/res/";
    mdir.mkpath(mpath);

    //Auswahl Bild für Gesicht und Autoentfernung des alten Bildes
    QString path_gesicht_open = QFileDialog::getOpenFileName(this, tr("Avatar Bild wählen"), "", tr("Images  (*.png *.xpm *.jpg)"));
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
    for (int i = 0; i < 10; i)
    {
        i = i + 1;
        QString i_str;

        i_str.append(QString("%1").arg(i));
        ui->listWidget_helden->addItem("Neuer_Held" + i_str);
        ui->lineEdit_name->setText("Neuer_Held" + i_str);
    }
}
