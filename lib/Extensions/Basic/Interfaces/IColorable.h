#ifndef XWINDOW_ICOLORABLE_H
#define XWINDOW_ICOLORABLE_H

#include <string>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "../../Common/Brush.h"

using namespace std;

class IColorable
{
public:
    Brush brush;
};

#endif
