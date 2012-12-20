#include "faehigkeiten_editor.h"
#include "ui_faehigkeiten_editor.h"

Faehigkeiten_Editor::Faehigkeiten_Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Faehigkeiten_Editor)
{
    ui->setupUi(this);
}

Faehigkeiten_Editor::~Faehigkeiten_Editor()
{
    delete ui;
}
