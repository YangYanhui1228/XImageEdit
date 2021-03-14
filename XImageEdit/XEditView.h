#pragma once
#include <QImage>
#include <vector>
using namespace std;

class QWidget;
struct XPos 
{
	XPos(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int x = 0;
	int y = 0;
};
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
	//定坐标
	vector<XPos> poss;
protected:
	XEditView();
	QWidget* device;
	QImage src;
};

