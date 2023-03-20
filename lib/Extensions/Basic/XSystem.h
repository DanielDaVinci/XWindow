#ifndef XWINDOW_XSYSTEM_H
#define XWINDOW_XSYSTEM_H

#include <iostream>
#include <exception>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

class XVisual;

class XSystem
{
private:
    Screen* screen;
    int screenNumber;

    friend XVisual;
public:
    XSystem();
    ~XSystem();
};

static XSystem System;

#endif
