#pragma once
#include "XSubject.h"

struct XPos
{
	XPos(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int x = 0;
	int y = 0;

};

class XModel :public XSubject
{

public:
	//µã×ø±ê
	std::vector<XPos> poss;
	void Add(XPos pos);
	XModel();
	~XModel();
};

