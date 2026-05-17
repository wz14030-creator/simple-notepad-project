//
// Created by Acer on 2026/5/16.
//

#ifndef SIMPLE_NOTEPAD_PROJECT_WORD_FREQUENCY_DIALOG_H
#define SIMPLE_NOTEPAD_PROJECT_WORD_FREQUENCY_DIALOG_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class word_frequency_dialog;
}
QT_END_NAMESPACE

class word_frequency_dialog : public QWidget {
  Q_OBJECT

public:
  explicit word_frequency_dialog(QWidget *parent = nullptr);
  ~word_frequency_dialog() override;

private:
  Ui::word_frequency_dialog *ui;
};

#endif // SIMPLE_NOTEPAD_PROJECT_WORD_FREQUENCY_DIALOG_H
