#ifndef XWINDOW_XWINDOW_H
#define XWINDOW_XWINDOW_H

#include <X11/X.h>
#include <X11/Xutil.h>
#include <X11/Xlib.h>
#include <X11/keysymdef.h>
#include <X11/XKBlib.h>

#include <iostream>
#include <exception>

class XWindow
{
protected:
    Display* display;
    int screenNumber;
    int depth;

    GC graphicContext;
    XGCValues graphicContextValues;

    Window rootWindow;
    Window window;
    XSetWindowAttributes windowAttributes;
    XSizeHints windowSizeHints;

    Pixmap pixmap;

    long eventMask = ExposureMask;

    /* Lifecycle properties */
    bool inProcess = false;
public:
    XWindow();
    ~XWindow();

    void Open();
    void Close();
protected:
    /* Setters */
    void setGC(XGCValues&);
    void setSizeHints(XSizeHints&);

        /* Mask */
    void setEventMask(long);
    void setMouseClickable();
    void setKeyboardTappable();

    /* Lifecycle events */
    virtual void onInitialize();
    virtual void onCreate();
    virtual void onDraw();
    virtual void onTermination();
    virtual void onDestroy();

    /* Window events */

        /* Mouse */
    virtual void onMousePress();
    virtual void onMouseEnter();
    virtual void onMouseLeave();

        /* Keyboard */
    virtual void onKeyPress();

private:
    /* Lifecycler */
    void eventHandler();
};

#endif
