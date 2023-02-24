#ifndef XWINDOW_XWINDOW_H
#define XWINDOW_XWINDOW_H

#include "../Common/Color.h"

#include <X11/X.h>
#include <X11/Xutil.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/XKBlib.h>

#include <iostream>
#include <string>
#include <exception>

using namespace std;

class XWindow
{
protected:
    /* Window properties */
    Display* display;
    int screenNumber;
    int depth;

    GC graphicContext;
    XGCValues graphicContextValues;

    Window rootWindow;
    Window window;
    XSetWindowAttributes windowAttributes;
    unsigned long attributesMask = CWEventMask;
    XSizeHints windowSizeHints;

    Pixmap pixmap;

    unsigned long eventMask = ExposureMask;

    /* Lifecycle properties */
    bool inProcess = false;
public:
    XWindow();
    ~XWindow();

    void Open();
    void Close();
protected:
    /* Values */
        /* Color */
    Color getColor(string);

    void setBackgroundColor(Color);
        /* Size */
    void setSizeHints(XSizeHints&);
    void setX(int);
    int getX() const;
    void setY(int);
    int getY() const;
    void setHeight(int);
    int getHeight() const;
    void setWidth(int);
    int getWidth() const;

    /* Notifies( Mask ) */
    void setEventMask(long);
        /* Mouse */
    void setMouseDownNotify();
    void unsetMouseDownNotify();
    void setMouseUpNotify();
    void unsetMouseUpNotify();
    void setMouseEnterNotify();
    void unsetMouseEnterNotify();
    void setMouseLeaveNotify();
    void unsetMouseLeaveNotify();
        /* KeyBoard */
    void setKeyDownNotify();
    void unsetKeyDownNotify();
    void setKeyUpNotify();
    void unsetKeyUpNotify();

    /* Lifecycle events */
    virtual void onInitialize();
    virtual void onCreate();
    virtual void onDraw();
    virtual void onTermination();
    virtual void onDestroy();

    /* Window events */
        /* Mouse */
    virtual void onMouseDown();
    virtual void onMouseUp();
    virtual void onMouseEnter();
    virtual void onMouseLeave();
        /* Keyboard */
    virtual void onKeyDown(KeySym, unsigned long);
    virtual void onKeyUp(KeySym, unsigned long);

private:
    /* Lifecycler */
    void eventHandler();
};

#endif