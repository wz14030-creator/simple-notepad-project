//
// Created by Acer on 2026/5/16.
//

// You may need to build the project (run Qt uic code generator) to get
// "ui_word_frequency_dialog.h" resolved

#include "word_frequency_dialog.h"
#include "ui_word_frequency_dialog.h"

word_frequency_dialog::word_frequency_dialog(QWidget *parent)
    : QWidget(parent), ui(new Ui::word_frequency_dialog) {
  ui->setupUi(this);
}

word_frequency_dialog::~word_frequency_dialog() { delete ui; }
