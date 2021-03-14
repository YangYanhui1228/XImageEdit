#include "XImage.h"
#include <QDebug>
#include <QFileDialog>
#include <QPainter>
#include "XEditView.h"

XImage::XImage(QWidget* p)
{
	XEditView::Get()->InitDevice(this);
}

XImage::~XImage()
{
}

void XImage::paintEvent(QPaintEvent* e)
{
	XEditView::Get()->Paint();
	////在当前窗口（this）绘制
	//QPainter p(this);
	////绘制图片
	//p.drawImage(0, 0, src);
}

void XImage::Open()
{
	qDebug() << "XImage::Open()";
	//选择图片
	QString filename = QFileDialog::getOpenFileName(this, QStringLiteral("打开图片"),
		"", QStringLiteral("支持的格式(*.jpg *.png *.bmp)"));
	if (filename.isEmpty()) 
	{
		qDebug() << "Open filename is empty!";
		return;
	}
	////载入图片
	//if (!src.load(filename))
	if(!XEditView::Get()->InitBack(filename.toLocal8Bit()))
	{
		qDebug() << "src load image failed!";
		return;
	}
	qDebug() << "src load image success!";
	
	//刷新显示
	update();
}