#include "main_editor_lvl.h"
#include "ui_main_editor_lvl.h"

Main_Editor_LVL::Main_Editor_LVL(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Main_Editor_LVL)
{
    ui->setupUi(this);
}

Main_Editor_LVL::~Main_Editor_LVL()
{
    delete ui;
}
