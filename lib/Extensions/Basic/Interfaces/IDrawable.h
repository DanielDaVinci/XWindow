#ifndef XWINDOW_IDRAWABLE_H
#define XWINDOW_IDRAWABLE_H

#include <X11/Xlib.h>

#include "IColorable.h"

class IDrawable: virtual protected IColorable
{
private:
    XFontStruct* fontInfo;
public:
    /* setters */
    void setLineWidth(Display*, GC, int);
    virtual void setLineWidth(int) = 0;

    /* Draw */
        /* Geometry */
    void DrawLine(Display*, Drawable, GC, int, int, int, int, int widthLine = 1, Color color = Color());
    virtual void DrawLine(Drawable, int, int, int, int, int widthLine = 1, Color color = Color()) = 0;
        /* Font and Text */
    void setFont(Display*, GC, const string&);
    virtual void setFont(const string&) = 0;
    void DrawString(Display*, Drawable, GC, int, int, const string&, const Color&);
    virtual void DrawString(Drawable, int, int, const string&, const Color&) = 0;
};

#endif
