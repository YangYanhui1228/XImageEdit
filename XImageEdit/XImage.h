#pragma once
#include <QWidget>
#include <QImage>
class IController;
class XImage :public QWidget
{
	Q_OBJECT

public:
	XImage(QWidget* p = 0);
	~XImage();
	
	//重载绘制方法 update后会调用
	void paintEvent(QPaintEvent *e);

	//重载鼠标函数
	void mousePressEvent(QMouseEvent* e);
	void mouseMoveEvent(QMouseEvent* e);



public slots:
	void Open();
protected:
	IController* c = 0;
};
