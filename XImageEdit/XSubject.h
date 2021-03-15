#pragma once
#include <vector>
class IObserver;
class XSubject
{
public:
	int type = 0;
	//通知观察者
	virtual void Notify();
	//添加观察者
	virtual void Attach(IObserver* ob);

protected:

	//观察者队列
	std::vector<IObserver *> obs;
};
