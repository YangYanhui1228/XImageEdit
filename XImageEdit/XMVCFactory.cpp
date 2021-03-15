#include "XMVCFactory.h"
#include "XModel.h"
#include "IController.h"
#include "XEditView.h"

XMVCFactory::XMVCFactory()
{
}

XMVCFactory::~XMVCFactory()
{
}

XModel* XMVCFactory::CreateM()
{
    return new XModel();
}

IView* XMVCFactory::CreateV()
{
    return XEditView::Get();
}

IController* XMVCFactory::CreateC()
{
    return new IController();
}
