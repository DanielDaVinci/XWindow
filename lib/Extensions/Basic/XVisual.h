#ifndef XWINDOW_XVISUAL_H
#define XWINDOW_XVISUAL_H

#include <iostream>
#include <exception>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "XSystem.h"

using namespace std;

class XVisual
{
private:
    GC graphicContext;
protected:
    XVisual();

    /* getters ans setters */
        /* System */
    Display* getDisplay() const;
    int getScreenNumber() const;
    int getDepth() const;
        /* GC */
    GC getGraphicContext() const;
    void setGraphicContext(XGCValues&, unsigned long);
    XGCValues getGCValues(unsigned long) const;
};

#endif
