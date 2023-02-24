#include "Color.h"


Color::Color(Display* display, int screenNumber, const string& color)
{
    colorMap = DefaultColormap(display, screenNumber);
    XParseColor(display, colorMap, color.c_str(), &RGB);
    XAllocColor(display, colorMap, &RGB);
}

Color::operator string() const
{
    return "#" + to_string(RGB.red) + to_string(RGB.green) + to_string(RGB.blue);
}

Color::operator unsigned long() const
{
    return RGB.pixel;
}