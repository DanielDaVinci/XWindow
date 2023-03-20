#ifndef XWINDOW_COLOR_H
#define XWINDOW_COLOR_H

#include "../Basic/XVisual.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <string>

using namespace std;

class Color: public XVisual
{
private:
    XColor RGB;
    Colormap colorMap;
public:
    Color(const string& = "#000000");
    ~Color();

    Color& operator = (const string&);

    operator string() const;
    operator unsigned long() const;
};

#endif
