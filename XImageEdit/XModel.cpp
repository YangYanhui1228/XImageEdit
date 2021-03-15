#include "XModel.h"

void XModel::Add(XPos pos)
{
	this->poss.push_back(pos);
	//通知观察者
	//this->Notify();
}

XModel::XModel()
{
}

XModel::~XModel()
{
}
