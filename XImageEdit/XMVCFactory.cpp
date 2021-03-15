#include "XMVCFactory.h"
#include "XModel.h"
#include "IController.h"
#include "XEditView.h"
#include "XPenGraph.h"
XModel* XMVCFactory::CreateM()
{
    return new XModel();
}

IView* XMVCFactory::CreateV()
{
    XEditView::Get()->RegView<XPenGraph>(XPEN);
    return XEditView::Get();
}

IController* XMVCFactory::CreateC()
{
    return new IController();
}
