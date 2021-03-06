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
	void paintEvent(QPaintEvent* e);

	//重载鼠标函数
	void mousePressEvent(QMouseEvent* e);
	void mouseMoveEvent(QMouseEvent* e);
public slots:
	void Open();
	void SetPen();
	void SetEraser();
	void SetRect();
	void Undo();
	void Redo();
	void SetPenSize(int size);
	void SetPenColor(int r, int g, int b, int a);
protected:
	IController* c = 0;
	int penSize = 5;
	int r = 255; 
	int g = 0; 
	int b = 0; 
	int a = 255;
};
