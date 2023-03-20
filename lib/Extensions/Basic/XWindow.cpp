#include "XWindow.h"

XWindow::XWindow(int x, int y, int width, int height): XVisualObject()
{
    onInitialize();

    windowSizeHints.flags = USSize | USPosition;
    windowSizeHints.x = x;
    windowSizeHints.y = y;
    windowSizeHints.width = width;
    windowSizeHints.height = height;
}

XWindow::XWindow(Window rootWindow, int x, int y, int width, int height): XVisualObject(rootWindow)
{
    onInitialize();

    windowSizeHints.flags = USSize | USPosition;
    windowSizeHints.x = x;
    windowSizeHints.y = y;
    windowSizeHints.width = width;
    windowSizeHints.height = height;
}

XWindow::~XWindow()
{
    onDestroy();
}

void XWindow::Open()
{
    Create();
    Map();
    eventHandler();
}

void XWindow::Create()
{
    windowAttributes.event_mask = getEventMask();
    attributesMask |= CWEventMask;
    window = XCreateWindow(getDisplay(), rootWindow,
                           windowSizeHints.x, windowSizeHints.y, windowSizeHints.width, windowSizeHints.height, 1,
                           getDepth(), InputOutput, CopyFromParent, attributesMask, &windowAttributes);
    onCreate();
}

void XWindow::Map()
{
    XMapWindow(getDisplay(), window);
    onMap();
}

void XWindow::Close()
{
    inProcess = false;
}

Window XWindow::getWindow() const
{
    return window;
}

void XWindow::setWindowBackground(const Color& color)
{
    attributesMask |= CWBackPixel;
    windowAttributes.background_pixel = color;
    if (window != 0)
    {
        XSetWindowBackground(getDisplay(), window, color);
        XClearArea(getDisplay(), window, 0, 0, 0, 0, true);
    }
}

void XWindow::setSizeHints(XSizeHints& sizeHints)
{
    windowSizeHints = sizeHints;
    if (window != 0)
        XSetNormalHints(getDisplay(), window, &windowSizeHints);
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

void XWindow::onInitialize()
{
    window = 0;
    windowAttributes = {};
    attributesMask = CWEventMask;
    windowSizeHints = {};
}

void XWindow::onCreate()
{

}

void XWindow::onMap()
{

}

void XWindow::onDraw()
{
    Clear();
}

void XWindow::onTermination()
{
    XDestroyWindow(getDisplay(), window);
}

void XWindow::onDestroy()
{

}

void XWindow::setEventMask(long mask)
{
    windowAttributes.event_mask |= mask;
    IEventHandler::setEventMask(getDisplay(), window, mask);
}

void XWindow::unsetEventMask(long mask)
{
    windowAttributes.event_mask &= ~mask;
    IEventHandler::unsetEventMask(getDisplay(), window, mask);
}

void XWindow::DrawLine(int x1, int y1, int x2, int y2, int lineWidth, const Color& color)
{
    XVisualObject::DrawLine(window, x1, y1, x2, y2, lineWidth, color);
}

void XWindow::DrawString(int x, int y, const std::string& text, const Color& color)
{
    XVisualObject::DrawString(window, x, y, text, color);
}

void XWindow::Clear()
{
    XClearArea(getDisplay(), window, 0, 0, 0, 0, false);
}

void XWindow::Move(int x, int y)
{
    setX(x);
    setY(y);
    XMoveWindow(getDisplay(), window, x, y);
}

void XWindow::eventHandler()
{
    inProcess = true;
    for (XEvent event; inProcess;)
    {
        XNextEvent(getDisplay(), &event);
        eventHandle(event);
    }

    onTermination();
}