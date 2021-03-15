#pragma once
#include <QImage>
#include <vector>
#include "IObserver.h"
#include "IView.h"
using namespace std;

class QWidget;

class XEditView: public IView
{
public:
	//单例模式
	static XEditView* Get()
	{
		static XEditView v;
		return &v;
	}

	//刷新到out中
	virtual void Update(XSubject* data);

	//显示目标
	virtual void InitDevice(void* d);

	//载入背景图
	virtual bool InitBack(const char* url);

	//绘制out结果
	virtual void Paint();
	~XEditView();

protected:
	XEditView();
	QWidget* device;
	//原图
	QImage src;

	//输出图
	QImage out;
};

