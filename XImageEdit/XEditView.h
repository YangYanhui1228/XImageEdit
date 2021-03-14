#pragma once
#include <QImage>
class QWidget;
class XEditView
{
public:
	//单例模式
	static XEditView* Get()
	{
		static XEditView v;
		return &v;
	}

	//显示目标
	virtual void InitDevice(void* d);

	//载入背景图
	virtual bool InitBack(const char* url);


	//绘制结果
	virtual void Paint();
	~XEditView();
protected:
	XEditView();
	QWidget* device;
	QImage src;
};

