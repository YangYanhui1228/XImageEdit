#include "XEditView.h"
#include <QPainter>
#include <QWidget>
#include "XModel.h"

XEditView::XEditView()
{
	//初始化图像，未打卡图像直接画图
	out = QImage(1280, 720, QImage::Format_RGB888);
	src = QImage(1280, 720, QImage::Format_RGB888);
}

void XEditView::Update(XSubject* data)
{
	if (!data) return;
	//XModel
	XModel* m = static_cast<XModel*>(data);
	int size = m->poss.size();
	QPainter p(&out);
	for (int i = 1; i < size; i++)
	{
		//绘制线，开始点到结束点
		p.drawLine(QLine(m->poss[i - 1].x, m->poss[i - 1].y, m->poss[i].x, m->poss[i].y));
	}
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
	out = src.copy();
	return true;
}

//绘制结果
void XEditView::Paint()
{
	//在device窗口绘制
	QPainter p(device);
	p.drawImage(0, 0, out);
	////绘制图片
	//p.drawImage(0, 0, src);
	////所有坐标的数量
	////从1开始，划线要两个点
	//int size = poss.size();
	//for (int i = 1; i < size; i++)
	//{
	//	//绘制线，开始点到结束点
	//	p.drawLine(QLine(poss[i - 1].x, poss[i - 1].y, poss[i].x, poss[i].y));
	//}
}

XEditView::~XEditView()
{
}
