#include "XEditView.h"
#include <QPainter>
#include <QWidget>

XEditView::XEditView()
{
}

//显示目标
void XEditView::InitDevice(void* d)
{
	this->device = (QWidget*)d;
}

//载入背景图
bool XEditView::InitBack(const char* url)
{
	//载入图片
	if (!src.load(QString::fromLocal8Bit(url))) return false;
	return true;
}

//绘制结果
void XEditView::Paint()
{
	//在device窗口绘制
	QPainter p(device);
	//绘制图片
	p.drawImage(0, 0, src);
}

XEditView::~XEditView()
{
}
