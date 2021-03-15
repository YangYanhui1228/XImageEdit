#include "XSubject.h"
#include "IObserver.h"

//通知观察者
void XSubject::Notify()
{
	for (int i = 0; i < obs.size(); i++) {
		//传递自身对象给观察者
		obs[i]->Update(this);
	}
}

//添加观察者
void XSubject::Attach(IObserver* ob)
{
	this->obs.push_back(ob);
}
