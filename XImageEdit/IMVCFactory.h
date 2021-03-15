#pragma once
class IController;
class XModel;
class IView;
	class IMVCFactory
{
public:
	virtual XModel *CreateM() = 0;
	virtual IView *CreateV() = 0;
	virtual IController *CreateC() = 0;
};

