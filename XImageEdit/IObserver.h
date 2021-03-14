#pragma once
class XSubject;
class IObserver
{
public:
	virtual void Update(XSubject* sub) = 0;
};

