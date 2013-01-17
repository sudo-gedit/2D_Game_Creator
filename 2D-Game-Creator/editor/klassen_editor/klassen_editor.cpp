#include "klassen_editor.h"
#include "ui_klassen_editor.h"

Klassen_Editor::Klassen_Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Klassen_Editor)
{
    ui->setupUi(this);
}

Klassen_Editor::~Klassen_Editor()
{
    delete ui;
}
