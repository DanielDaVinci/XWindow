#ifndef XWINDOW_BRUSH_H
#define XWINDOW_BRUSH_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "Color.h"
#include "../Basic/XVisual.h"

class Brush: virtual public XVisual
{
private:
    Color foregroundColor;
    Color backgroundColor;
public:
    Brush(const Color& foregroundColor = Color(), const Color& backgroundColor = Color());

    /* getters ans setters */
    void setForegroundColor(const Color&);
    Color getForegroundColor() const;
    void setBackgroundColor(const Color&);
    Color getBackgroundColor() const;
};

#endif
