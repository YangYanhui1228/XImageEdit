#pragma once
#include "IMVCFactory.h"
#include <vector>
enum XSTATUS
{
	XPEN,
	XERASER,
	XRECT,
	XIMAGE
};

class IController
{
public:
	static IController* Create(IMVCFactory *f);
	virtual void Init(void* device);
	//载入背景图
	virtual bool InitBack(const char* url);
	//添加模型对象 -1取当前状态
	virtual void AddModel(int s = -1);
	//给当前模型添加数据
	virtual void Add(int x, int y);
	virtual void Paint();
	virtual void SetStatus(XSTATUS s) { status = s; }
	virtual void NotifyAll();
	virtual void Undo();
	virtual void Redo();
	virtual void SetPara(std::string key, int val);
	IController();
	~IController();
protected:
	IView* v = 0;
	XModel* m = 0;
	IMVCFactory* f = 0;
	//命令队列
	std::vector<XModel*> tasks;
	std::vector<XModel*> retasks;
	XSTATUS status = XPEN;
};

