#ifndef XWINDOW_COLOR_H
#define XWINDOW_COLOR_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <string>

using namespace std;

class Color
{
private:
    XColor RGB;
    Colormap colorMap;
public:
    Color(Display*, int, const string&);

    operator string() const;
    operator unsigned long() const;
};

#endif
