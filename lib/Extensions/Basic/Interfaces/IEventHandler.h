#ifndef XWINDOW_IEVENTHANDLER_H
#define XWINDOW_IEVENTHANDLER_H

#include <X11/Xutil.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/XKBlib.h>

#include "ILifecycle.h"
#include "../XVisual.h"

class IEventHandler
{
private:
    long eventMask = 0;
public:
    /* Notifies( Masks ) */
    long getEventMask() const;

    void setEventMask(Display*, Window, long);
    virtual void setEventMask(long) = 0;
    void unsetEventMask(Display*, Window, long);
    virtual void unsetEventMask(long) = 0;
        /* System */
    void setDrawNotify();
    void unsetDrawNotify();
        /* Mouse */
    void setMouseDownNotify();
    void unsetMouseDownNotify();
    void setMouseUpNotify();
    void unsetMouseUpNotify();
    void setMouseMotionNotify();
    void unsetMouseMotionNotify();
    void setMouseEnterNotify();
    void unsetMouseEnterNotify();
    void setMouseLeaveNotify();
    void unsetMouseLeaveNotify();
        /* KeyBoard */
    void setKeyDownNotify();
    void unsetKeyDownNotify();
    void setKeyUpNotify();
    void unsetKeyUpNotify();
protected:
    /* Events */
    void eventHandle(const XEvent&);
        /* System */
    virtual void onDraw() {};
        /* Mouse */
    virtual void onMouseDown(const XEvent&) {};
    virtual void onMouseUp(const XEvent&) {};
    virtual void onMouseMotion(const XEvent&) {};
    virtual void onMouseEnter(const XEvent&) {};
    virtual void onMouseLeave(const XEvent&) {};
        /* Keyboard */
    virtual void onKeyDown(const XEvent&) {};
    virtual void onKeyUp(const XEvent&) {};
};

#endif
