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

void XWindow::setGC(XGCValues& gcValues)
{
    graphicContextValues = gcValues;
    XChangeGC(display, graphicContext, GCLineWidth, &graphicContextValues);
}

void XWindow::setSizeHints(XSizeHints& sizeHints)
{
    windowSizeHints = sizeHints;
    XSetWMNormalHints(display, window, &windowSizeHints);
}

void XWindow::setEventMask(long mask)
{
    XSelectInput(display, window, mask);
}

void XWindow::setMouseClickable()
{
    setEventMask(KeyPressMask);
}

void XWindow::setKeyboardTappable()
{
    setEventMask(ButtonPressMask);
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
}

void XWindow::onCreate()
{
    window = XCreateWindow(display, rootWindow,
                           windowSizeHints.x, windowSizeHints.y, windowSizeHints.width, windowSizeHints.height, 1,
                           depth, InputOutput, CopyFromParent, CWOverrideRedirect, &windowAttributes);
    setEventMask(eventMask);
}

void XWindow::onDraw()
{

}

void XWindow::onTermination()
{
    XDestroyWindow(display, window);
}

void XWindow::onDestroy()
{
    XCloseDisplay(display);
}

void XWindow::onMousePress()
{

}

void XWindow::onMouseEnter()
{

}

void XWindow::onMouseLeave()
{

}

void XWindow::onKeyPress()
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
                onMousePress();
                break;
            case KeyPress:
                onKeyPress();
                break;
        }
    }

    onTermination();
}



