#pragma once

#include <QtWidgets/QWidget>
#include "ui_XImageEdit.h"

class XImageEdit : public QWidget
{
    Q_OBJECT

public:
    XImageEdit(QWidget *parent = Q_NULLPTR);

private:
    Ui::XImageEditClass ui;
};
