#include "IController.h"
#include "IView.h"
#include "XModel.h"

IController* IController::Create(IMVCFactory* f)
{
	if (!f) return 0;
	IController* c = f->CreateC();
	c->f = f;
	//c->m = f->CreateM();
	c->v = f->CreateV();
	return c;
}

void IController::Init(void* device)
{
	v->InitDevice(device);
}

bool IController::InitBack(const char* url)
{
	return v->InitBack(url);
}

void IController::AddModel()
{
	//创建模型，添加观察者
	m = f->CreateM();
	m->Attach(v);
	tasks.push_back(m);
}

void IController::Add(int x, int y)
{
	if (!m) return;
	m->Add(XPos(x, y));
}

void IController::Paint()
{
	v->Paint();
}

IController::IController()
{
}

IController::~IController()
{
}
