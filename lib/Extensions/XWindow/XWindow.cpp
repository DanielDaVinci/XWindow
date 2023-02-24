#include "XWindow.h"

XWindow::XWindow()
{
    onInitialize();
}

XWindow::~XWindow()
{
    onDestroy();
}

void XWindow::Open()
{
    eventHandler();
}

void XWindow::Close()
{
    inProcess = false;
}

Color XWindow::getColor(string color)
{
    return Color(display, screenNumber, color);
}

void XWindow::setBackgroundColor(Color color)
{
    attributesMask |= CWBackPixel;
    windowAttributes.background_pixel = color;
    if (window != 0)
    {
        XSetWindowBackground(display, window, color);
        XClearArea(display, window, 0, 0, 0, 0, true);
    }
}

void XWindow::setSizeHints(XSizeHints& sizeHints)
{
    windowSizeHints = sizeHints;
    if (window != 0)
        XSetWMNormalHints(display, window, &windowSizeHints);
}

void XWindow::setX(int x)
{
    windowSizeHints.x = x;
    setSizeHints(windowSizeHints);
}

int XWindow::getX() const
{
    return windowSizeHints.x;
}

void XWindow::setY(int y)
{
    windowSizeHints.y = y;
    setSizeHints(windowSizeHints);
}

int XWindow::getY() const
{
    return windowSizeHints.y;
}

void XWindow::setHeight(int height)
{
    windowSizeHints.height = height;
    setSizeHints(windowSizeHints);
}

int XWindow::getHeight() const
{
    return windowSizeHints.height;
}

void XWindow::setWidth(int width)
{
    windowSizeHints.width = width;
    setSizeHints(windowSizeHints);
}

int XWindow::getWidth() const
{
    return windowSizeHints.width;
}

void XWindow::setEventMask(long mask)
{
    eventMask |= mask;
    if (window != 0)
        XSelectInput(display, window, eventMask);
}

void XWindow::setMouseDownNotify()
{
    setEventMask(ButtonPressMask);
}

void XWindow::unsetMouseDownNotify()
{
    setEventMask(~ButtonPressMask);
}

void XWindow::setMouseUpNotify()
{
    setEventMask(ButtonReleaseMask);
}

void XWindow::unsetMouseUpNotify()
{
    setEventMask(~ButtonReleaseMask);
}

void XWindow::setKeyDownNotify()
{
    setEventMask(KeyPressMask);
}

void XWindow::unsetKeyDownNotify()
{
    setEventMask(~KeyPressMask);
}

void XWindow::setKeyUpNotify()
{
    setEventMask(KeyReleaseMask);
}

void XWindow::unsetKeyUpNotify()
{
    setEventMask(~KeyReleaseMask);
}

void XWindow::setMouseEnterNotify()
{
    setEventMask(EnterWindowMask);
}

void XWindow::unsetMouseEnterNotify()
{
    setEventMask(~EnterWindowMask);
}

void XWindow::setMouseLeaveNotify()
{
    setEventMask(LeaveWindowMask);
}

void XWindow::unsetMouseLeaveNotify()
{
    setEventMask(~LeaveWindowMask);
}

void XWindow::onInitialize()
{
    display = XOpenDisplay(NULL);
    if (display == NULL)
        throw std::invalid_argument("Can not connect to the X server!\n");

    screenNumber = DefaultScreen(display);
    depth = DefaultDepth(display, screenNumber);

    graphicContext = DefaultGC(display, screenNumber);

    rootWindow = DefaultRootWindow(display);
    window = 0;
}

void XWindow::onCreate()
{
    window = XCreateWindow(display, rootWindow,
                           windowSizeHints.x, windowSizeHints.y, windowSizeHints.width, windowSizeHints.height, 1,
                           depth, InputOutput, CopyFromParent, attributesMask, &windowAttributes);
    setEventMask(eventMask);
}

void XWindow::onDraw()
{
    XClearArea(display, window, 0, 0, 0, 0, false);
}

void XWindow::onTermination()
{
    XDestroyWindow(display, window);
}

void XWindow::onDestroy()
{
    XFreeGC(display, graphicContext);
    XCloseDisplay(display);
}

void XWindow::onMouseDown()
{

}

void XWindow::onMouseUp()
{

}

void XWindow::onMouseEnter()
{

}

void XWindow::onMouseLeave()
{

}

void XWindow::onKeyDown(KeySym key, unsigned long state)
{

}

void XWindow::onKeyUp(KeySym key, unsigned long state)
{

}

void XWindow::eventHandler()
{
    onCreate();

    XMapWindow(display, window);
    inProcess = true;

    for (XEvent event; inProcess;)
    {
        XNextEvent(display, &event);
        switch (event.type)
        {
            case Expose:
                if (event.xexpose.count == 0)
                    onDraw();
                break;
            case ButtonPress:
                onMouseDown();
                break;
            case ButtonRelease:
                onMouseUp();
                break;
            case EnterNotify:
                onMouseEnter();
                break;
            case LeaveNotify:
                onMouseLeave();
                break;
            case KeyPress:
                onKeyDown(XkbKeycodeToKeysym(display, event.xkey.keycode, 0, 0),
                          event.xkey.state);
                break;
            case KeyRelease:
                onKeyUp(XkbKeycodeToKeysym(display, event.xkey.keycode, 0, event.xkey.state == ShiftMask),
                        event.xkey.state);
                break;
            default:
                break;
        }
    }

    onTermination();
}