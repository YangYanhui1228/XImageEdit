#include "XImage.h"
#include <QDebug>
#include <QFileDialog>
#include <QPainter>
//#include "XEditView.h"
#include <QMouseEvent>
//#include "XModel.h"
#include "IController.h"
#include "XMVCFactory.h"
//XModel m;
XImage::XImage(QWidget* p):QWidget(p)
{
	c = IController::Create(new XMVCFactory());
	c->Init(this);

	//XEditView::Get()->InitDevice(this);
	//视图观察模型
	//m.Attrach(XEditView::Get());
}

XImage::~XImage()
{
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
	if(!c->InitBack(filename.toLocal8Bit()))
	{
		qDebug() << "src load image failed!";
		return;
	}
	qDebug() << "src load image success!";
	
	//刷新显示
	update();
}


//重载鼠标函数
void  XImage::mousePressEvent(QMouseEvent* e)
{
	//XEditView::Get()->poss.push_back(XPos(e->x(), e->y()));
	//m.Add(XPos(e->x(), e->y()));
	c->AddModel();
	c->Add(e->x(), e->y());
	//创建一个模型
}

//默认鼠标移动事件，按下才触发
void  XImage::mouseMoveEvent(QMouseEvent* e)
{
	c->Add(e->x(), e->y());
	//修改模型数据
	//XEditView::Get()->poss.push_back(XPos(e->x(), e->y()));
	//m.Add(XPos(e->x(), e->y()));
	update();
}

void XImage::SetPen()
{
	c->SetStatus(XPEN);
}

void XImage::SetEraser()
{
	c->SetStatus(XERASER);
}

//重载绘制方法 update后会调用
void XImage::paintEvent(QPaintEvent* e)
{
	c->Paint();
	////在当前窗口（this）绘制
	//QPainter p(this);
	////绘制图片
	//p.drawImage(0, 0, src);
}