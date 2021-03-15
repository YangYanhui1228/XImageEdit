#pragma once
#include "IMVCFactory.h"
class XMVCFactory :public IMVCFactory
{
public:
	static XMVCFactory* Get()
	{
		static XMVCFactory f;
		return &f;
	}
	XMVCFactory();
	~XMVCFactory();
	XModel* CreateM();
	IView* CreateV();
	IController* CreateC();
};

