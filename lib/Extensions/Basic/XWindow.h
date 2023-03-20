#ifndef XWINDOW_XWINDOW_H
#define XWINDOW_XWINDOW_H

#include <iostream>
#include <string>
#include <exception>

#include <X11/X.h>
#include <X11/Xutil.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/XKBlib.h>

#include "XVisualObject.h"
#include "Interfaces/IEventHandler.h"
#include "Interfaces/ILifecycle.h"

using namespace std;

class XWindow: public XVisualObject, virtual public IEventHandler, protected ILifecycle
{
protected:
    Window window;
    XSetWindowAttributes windowAttributes;
    unsigned long attributesMask;
    XSizeHints windowSizeHints;

    /* Lifecycle properties */
    bool inProcess = false;
public:
    XWindow(int x = 0, int y = 0, int width = 1, int height = 1);
    XWindow(Window rootWindow, int x = 0, int y = 0, int width = 1, int height = 1);
    ~XWindow();

    void Open();
    void Create();
    void Map();
    void Close();

    /* Values */
        /* Window */
    Window getWindow() const;
        /* Color */
    void setWindowBackground(const Color&);
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

    /* Event mask */
    void setEventMask(long) override;
    void unsetEventMask(long) override;

    /* Draw */
    void DrawLine(int, int, int, int, int, const Color&);
    void DrawString(int, int, const string&, const Color&);
    void Clear();
    /* Motion */
    void Move(int, int);
protected:
    /* Lifecycle events */
    void onInitialize() override;
    void onCreate() override;
    virtual void onMap();
    void onDraw() override;
    void onTermination() override;
    void onDestroy() override;
private:
    /* Lifecycler */
    void eventHandler();
};

#endif