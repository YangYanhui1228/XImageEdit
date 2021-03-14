#pragma once

#include <QtWidgets/QWidget>
#include "ui_XImageEdit.h"
#include "XImage.h"

class XImageEdit : public QWidget
{
    Q_OBJECT

public:
    XImageEdit(QWidget *parent = Q_NULLPTR);
protected:

private:
    Ui::XImageEditClass ui;
};
