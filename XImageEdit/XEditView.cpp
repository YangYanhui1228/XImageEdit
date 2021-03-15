#include "XEditView.h"
#include <QPainter>
#include <QWidget>
#include "XModel.h"
#include "XPenGraph.h"
//XPenGraph xpen;
XEditView::XEditView()
{
	//初始化图像，未打卡图像直接画图
	out = QImage(1280, 720, QImage::Format_RGB888);
	src = QImage(1280, 720, QImage::Format_RGB888);
}

void XEditView::Update(XSubject* data)
{
	if (!data) return;
	XModel* m = static_cast<XModel*>(data);
	views[m->type]->Draw(m);

	//map<int, IGraph*>::iterator itr = views.begin();
	//for (; itr != views.end(); itr++)
	//{
	//	itr->second->Draw(m);
	//}
	//遍历图元并绘制
	//xpen.Draw(m);

	//XModel

 	//int size = m->poss.size();
 	//QPainter p(&out);
 	//for (int i = 1; i < size; i++)
 	//{
 	//	//绘制线，开始点到结束点
 	//	p.drawline(qline(m->poss[i - 1].x, m->poss[i - 1].y, m->poss[i].x, m->poss[i].y));
 	//}
}

//显示目标
void XEditView::InitDevice(void* d)
{
	this->device = (QWidget*)d;
	if (!op) op = new QPainter(&out);
	//上一次的清理掉
	op->end();
	op->begin(&out);
	map<int, IGraph*>::iterator itr = views.begin();
	for (; itr != views.end(); itr++) 
	{
		itr->second->Init(op, &src);
	}
	//xpen.Init(op, &src);
}

//载入背景图
bool XEditView::InitBack(const char* url)
{
	//载入图片
	if (!src.load(QString::fromLocal8Bit(url))) return false;
	if (op->isActive())
		op->end();
	out = src.copy();
	op->begin(&out);
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
