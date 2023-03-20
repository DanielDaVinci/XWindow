#include "Color.h"


Color::Color(const string& color)
{
    colorMap = DefaultColormap(getDisplay(), getScreenNumber());
    XParseColor(getDisplay(), colorMap, color.c_str(), &RGB);
    XAllocColor(getDisplay(), colorMap, &RGB);
}

Color::~Color()
{
    XFreeColormap(getDisplay(), colorMap);
}

Color& Color::operator = (const string& color)
{
    XParseColor(getDisplay(), colorMap, color.c_str(), &RGB);
    XAllocColor(getDisplay(), colorMap, &RGB);

    return *this;
}

Color::operator string() const
{
    return "#" + to_string(RGB.red) + to_string(RGB.green) + to_string(RGB.blue);
}

Color::operator unsigned long() const
{
    return RGB.pixel;
}