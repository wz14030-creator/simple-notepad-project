//
// Created by Acer on 2026/5/16.
//

// You may need to build the project (run Qt uic code generator) to get
// "ui_find_replace_dialog.h" resolved

#include "find_replace_dialog.h"
#include "ui_find_replace_dialog.h"

find_replace_dialog::find_replace_dialog(QWidget* parent)
    : QWidget(parent), ui(new Ui::find_replace_dialog)
{
    ui->setupUi(this);
}

find_replace_dialog::~find_replace_dialog() { delete ui; }
