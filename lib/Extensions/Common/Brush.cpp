#include "Brush.h"

Brush::Brush(const Color& foregroundColor, const Color& backgroundColor): XVisual()
{
    setForegroundColor(foregroundColor);
    setBackgroundColor(backgroundColor);
}

void Brush::setForegroundColor(const Color& color)
{
    foregroundColor = color;
    XSetForeground(getDisplay(), getGraphicContext(), foregroundColor);
}

Color Brush::getForegroundColor() const
{
    return foregroundColor;
}

void Brush::setBackgroundColor(const Color& color)
{
    backgroundColor = color;
    XSetBackground(getDisplay(), getGraphicContext(), backgroundColor);
}

Color Brush::getBackgroundColor() const
{
    return backgroundColor;
}