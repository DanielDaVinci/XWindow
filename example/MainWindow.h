#ifndef XWINDOW_MAINWINDOW_H
#define XWINDOW_MAINWINDOW_H

#include <vector>
#include <string>
#include <stdlib.h>

#include "../lib/Extensions/Basic/XWindow.h"

using namespace std;

class MainWindow: public XWindow
{
private:
    string word;
    vector<string> subWindowLetters;
    vector<XWindow*> subWindows;

    int focusWindowIndex = -1;
    XPoint startWindowPosition = {0, 0};
    XPoint mouseLastPosition = {0, 0};
public:
    MainWindow(const string&, int x = 0, int y = 0, int width = 600, int height = 400);
protected:
    void onInitialize() override;
    void onCreate() override;
    void onMap() override;
    void onDraw() override;

    void onMouseDown(const XEvent&) override;
    void onMouseUp(const XEvent&) override;
    void onMouseLeave(const XEvent&) override;
    void onMouseMotion(const XEvent&) override;

    void onKeyDown(const XEvent&) override;

    void swapWindows(int, int);
};

#endif
