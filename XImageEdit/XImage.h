#pragma once
#include <QWidget>

class XImage :public QWidget
{
	Q_OBJECT

public:
	XImage(QWidget* p = 0);
	~XImage();
public slots:
	void Open();
};
