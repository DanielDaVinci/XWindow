#include "XVisual.h"

XVisual::XVisual()
{
    graphicContext = XDefaultGC(getDisplay(), getScreenNumber());
}

Display* XVisual::getDisplay() const
{
    return System.screen->display;
}

int XVisual::getScreenNumber() const
{
    return System.screenNumber;
}

int XVisual::getDepth() const
{
    return System.screen->root_depth;
}

GC XVisual::getGraphicContext() const
{
    return graphicContext;
}

void XVisual::setGraphicContext(XGCValues& gcValues, unsigned long mask)
{
    XChangeGC(getDisplay(), getGraphicContext(), mask, &gcValues);
}

XGCValues XVisual::getGCValues(unsigned long mask) const
{
    XGCValues gcValues;
    XGetGCValues(getDisplay(), getGraphicContext(), mask, &gcValues);
    return gcValues;
}