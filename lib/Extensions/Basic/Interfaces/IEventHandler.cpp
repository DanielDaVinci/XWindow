#include "IEventHandler.h"

long IEventHandler::getEventMask() const
{
    return eventMask;
}

void IEventHandler::setEventMask(Display* display, Window window, long mask)
{
    eventMask |= mask;
    if (window != 0)
        XSelectInput(display, window, eventMask);
}

void IEventHandler::unsetEventMask(Display* display, Window window, long mask)
{
    eventMask &= ~mask;
    if (window != 0)
        XSelectInput(display, window, eventMask);
}

void IEventHandler::setDrawNotify()
{
    setEventMask(ExposureMask);
}

void IEventHandler::unsetDrawNotify()
{
    unsetEventMask(ExposureMask);
}

void IEventHandler::setMouseDownNotify()
{
    setEventMask(ButtonPressMask);
}

void IEventHandler::unsetMouseDownNotify()
{
    unsetEventMask(ButtonPressMask);
}

void IEventHandler::setMouseUpNotify()
{
    setEventMask(ButtonReleaseMask);
}

void IEventHandler::unsetMouseUpNotify()
{
    unsetEventMask(ButtonReleaseMask);
}

void IEventHandler::setMouseMotionNotify()
{
    setEventMask(ButtonMotionMask);
}

void IEventHandler::unsetMouseMotionNotify()
{
    unsetEventMask(ButtonMotionMask);
}

void IEventHandler::setKeyDownNotify()
{
    setEventMask(KeyPressMask);
}

void IEventHandler::unsetKeyDownNotify()
{
    unsetEventMask(KeyPressMask);
}

void IEventHandler::setKeyUpNotify()
{
    setEventMask(KeyReleaseMask);
}

void IEventHandler::unsetKeyUpNotify()
{
    unsetEventMask(KeyReleaseMask);
}

void IEventHandler::setMouseEnterNotify()
{
    setEventMask(EnterWindowMask);
}

void IEventHandler::unsetMouseEnterNotify()
{
    unsetEventMask(EnterWindowMask);
}

void IEventHandler::setMouseLeaveNotify()
{
    setEventMask(LeaveWindowMask);
}

void IEventHandler::unsetMouseLeaveNotify()
{
    unsetEventMask(LeaveWindowMask);
}

void IEventHandler::eventHandle(const XEvent& event)
{
    switch (event.type)
    {
        case Expose:
            if (event.xexpose.count != 0)
                break;
            onDraw();
            break;
        case ButtonPress:
            onMouseDown(event);
            break;
        case ButtonRelease:
            onMouseUp(event);
            break;
        case MotionNotify:
            onMouseMotion(event);
            break;
        case EnterNotify:
            onMouseEnter(event);
            break;
        case LeaveNotify:
            onMouseLeave(event);
            break;
        case KeyPress:
            onKeyDown(event);
            break;
        case KeyRelease:
            onKeyUp(event);
            break;
        default:
            break;
    }
}