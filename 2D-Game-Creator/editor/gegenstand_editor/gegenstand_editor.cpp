//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Gegenstand Editor version 0.00.0.1
//
//
//
// Letzte Aenderung 03.01.2013
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gegenstand_editor.h"
#include "ui_gegenstand_editor.h"

Gegenstand_Editor::Gegenstand_Editor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gegenstand_Editor)
{
    ui->setupUi(this);
}

Gegenstand_Editor::~Gegenstand_Editor()
{
    delete ui;
}
