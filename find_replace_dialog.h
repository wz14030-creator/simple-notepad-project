//
// Created by Acer on 2026/5/16.
//

#ifndef SIMPLE_NOTEPAD_PROJECT_FIND_REPLACE_DIALOG_H
#define SIMPLE_NOTEPAD_PROJECT_FIND_REPLACE_DIALOG_H

#include <QWidget>

QT_BEGIN_NAMESPACE

namespace Ui
{
    class find_replace_dialog;
}

QT_END_NAMESPACE

class find_replace_dialog : public QWidget
{
    Q_OBJECT

public:
    explicit find_replace_dialog(QWidget* parent = nullptr);
    ~find_replace_dialog() override;

private:
    Ui::find_replace_dialog* ui;
};

#endif // SIMPLE_NOTEPAD_PROJECT_FIND_REPLACE_DIALOG_H
