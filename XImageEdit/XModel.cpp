#include "XModel.h"

void XModel::Add(XPos pos)
{
	this->poss.push_back(pos);
	//通知观察者
	//this->Notify();
}

void XModel::SetPara(std::string key, int val)
{
	//没有添加
	if (paras.find(key) == paras.end()) 
	{
		paras.insert(make_pair(key, val));
	}
	else 
	{
		//如果有值  修改
		paras[key] = val;
	}


}

int XModel::GetPara(std::string key)
{
	//没有添加
	if (paras.find(key) == paras.end())
	{
		return 0;
	}
	return paras[key];
}

XModel::XModel()
{
}

XModel::~XModel()
{
}
