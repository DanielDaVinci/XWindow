#include "IDrawable.h"

void IDrawable::setLineWidth(Display* display, GC graphicContext, int widthLine)
{
    XGCValues gcValues;
    gcValues.line_width = widthLine;
    XChangeGC(display, graphicContext,  GCLineWidth, &gcValues);
}

void IDrawable::DrawLine(Display* display, Drawable drawable, GC graphicContext, int x1, int y1, int x2, int y2, int widthLine, Color color)
{
    setLineWidth(display, graphicContext, widthLine);
    XGCValues gcValues;
    gcValues.foreground = color;
    XChangeGC(display, graphicContext, GCForeground, &gcValues);
    XDrawLine(display, drawable, graphicContext, x1, y1, x2, y2);
}

void IDrawable::setFont(Display* display, GC graphicContext, const std::string& fontName)
{
    if ((fontInfo =  XLoadQueryFont(display, fontName.c_str())) == NULL){
        cerr << "Font not found!" << endl;
    }
    XSetFont(display, graphicContext, fontInfo->fid);
}

void IDrawable::DrawString(Display* display, Drawable drawable, GC graphicContext, int x, int y, const std::string& text, const Color& color)
{
    XSetForeground(display, graphicContext, color);
    XDrawString(display, drawable, graphicContext, x, y, text.c_str(), text.size());
}