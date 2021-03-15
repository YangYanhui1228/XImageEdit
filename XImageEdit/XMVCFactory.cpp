#include "XMVCFactory.h"
#include "XModel.h"
#include "IController.h"
#include "XEditView.h"
#include "XPenGraph.h"
#include "XEraseGraph.h"
#include "XRectGraph.h"
#include "XImageGraph.h"
XModel* XMVCFactory::CreateM()
{
    return new XModel();
}

IView* XMVCFactory::CreateV()
{
    XEditView::Get()->RegView<XPenGraph>(XPEN);
    XEditView::Get()->RegView<XEraseGraph>(XERASER);
    XEditView::Get()->RegView<XRectGraph>(XRECT);
    XEditView::Get()->RegView<XImageGraph>(XIMAGE);
    return XEditView::Get();
}

IController* XMVCFactory::CreateC()
{
    return new IController();
}
