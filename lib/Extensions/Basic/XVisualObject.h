#ifndef XWINDOW_XVISUALOBJECT_H
#define XWINDOW_XVISUALOBJECT_H

#include "XVisual.h"
#include "Interfaces/IColorable.h"
#include "Interfaces/IDrawable.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>

class XVisualObject: virtual public XVisual, virtual public IColorable, virtual public IDrawable
{
protected:
    Window rootWindow;
public:
    XVisualObject();
    XVisualObject(Window rootWindow);

    /* IDrawable */
    void setLineWidth(int) override;
    void DrawLine(Drawable, int, int, int, int, int widthLine = 1, Color color = Color()) override;
    void setFont(const std::string &) override;
    void DrawString(Drawable, int, int, const std::string&, const Color&) override;
};

#endif
