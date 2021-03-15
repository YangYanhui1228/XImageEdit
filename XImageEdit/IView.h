#pragma once
#include "IObserver.h"
class IView :public IObserver 
{
public:
	//显示目标
	virtual void InitDevice(void* d) = 0;

	//载入背景图
	virtual bool InitBack(const char* url) = 0;

	//绘制out结果
	virtual void Paint() = 0;
};

