#include "XVisualObject.h"

XVisualObject::XVisualObject(): XVisual()
{
    rootWindow = XRootWindow(getDisplay(), getScreenNumber());
}

XVisualObject::XVisualObject(Window rootWindow)
{
    this->rootWindow = rootWindow;
}

void XVisualObject::setLineWidth(int lineWidth)
{
    IDrawable::setLineWidth(getDisplay(), getGraphicContext(), lineWidth);
}

void XVisualObject::DrawLine(Drawable drawable, int x1, int y1, int x2, int y2, int widthLine, Color color)
{
    IDrawable::DrawLine(getDisplay(), drawable, getGraphicContext(), x1, y1, x2, y2, widthLine, color);
}

void XVisualObject::setFont(const std::string& fontName)
{
    IDrawable::setFont(getDisplay(), getGraphicContext(), fontName);
}

void XVisualObject::DrawString(Drawable drawable, int x, int y, const std::string& text, const Color& color)
{
    IDrawable::DrawString(getDisplay(), drawable, getGraphicContext(), x, y, text, color);
}