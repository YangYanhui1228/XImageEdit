#pragma once
#include "XSubject.h"
#include <map>
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
	void SetPara(std::string key, int val);
	int GetPara(std::string key);
	XModel();
	~XModel();
private:
	std::map<std::string, int>paras;

};
