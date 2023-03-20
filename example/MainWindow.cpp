#include "MainWindow.h"

MainWindow::MainWindow(const string& word, int x, int y, int width, int height): XWindow(x, y, width, height)
{
    onInitialize();

    this->word = word;
    subWindowLetters = vector<string>(word.size() + 1);
    for (int i = 0; i < word.size(); i++)
        subWindowLetters[i] = string(1, word[i]);
}

void MainWindow::onInitialize()
{
    setKeyDownNotify();
    setWindowBackground(Color("#ffffff"));
}

void MainWindow::onCreate()
{
    XWindow::onCreate();

    for (int i = 0; i < word.size() + 2; i++)
    {
        XWindow* subWindow = new XWindow(window,55 * i + 50, 50, 50, 50);
        subWindow->setWindowBackground(Color("#ffffff"));
        subWindow->setDrawNotify();
        subWindow->setMouseDownNotify();
        subWindow->setMouseUpNotify();
        subWindow->setMouseLeaveNotify();
        subWindow->setMouseMotionNotify();
        subWindow->Create();
        subWindows.push_back(subWindow);
    }
}

void MainWindow::onMap()
{
    XWindow::onMap();
    XMapSubwindows(getDisplay(), window);
}

void MainWindow::onDraw()
{
    XWindow::onDraw();

    for (int i = 1; i < word.size() + 1; i++)
    {
        subWindows[i]->Clear();
        subWindows[i]->setFont("9x15");
        subWindows[i]->DrawString(20, 30, subWindowLetters[i - 1], Color("#000000"));
    }
}

void MainWindow::onMouseDown(const XEvent& event)
{
    for (int i = 0; i < subWindows.size(); i++)
    {
        if (event.xbutton.window != subWindows[i]->getWindow())
            continue;

        if (i == 0 or i == subWindows.size() - 1)
            Close();

        startWindowPosition.x = subWindows[i]->getX();
        startWindowPosition.y = subWindows[i]->getY();

        mouseLastPosition.x = event.xbutton.x;
        mouseLastPosition.y = event.xbutton.y;

        focusWindowIndex = i;
        XRaiseWindow(getDisplay(), subWindows[focusWindowIndex]->getWindow());
    }
}

void MainWindow::onMouseUp(const XEvent& event)
{
    if (focusWindowIndex == -1)
        return;

    for (int i = 0; i < subWindows.size() - 1; i++)
    {
        if (subWindows[focusWindowIndex]->getX() >= subWindows[i]->getX() and subWindows[focusWindowIndex]->getX() <= subWindows[i]->getX() + subWindows[i]->getWidth()
            and subWindows[focusWindowIndex]->getX() + subWindows[focusWindowIndex]->getWidth() >= subWindows[i + 1]->getX()
            and subWindows[focusWindowIndex]->getX() + subWindows[focusWindowIndex]->getWidth() <= subWindows[i + 1]->getX() + subWindows[i + 1]->getWidth())
        {
            subWindows[focusWindowIndex]->Move(startWindowPosition.x, startWindowPosition.y);
            if (focusWindowIndex < i)
            {
                for (int j = i; j >= focusWindowIndex; j--)
                    swapWindows(j, focusWindowIndex);
            }
            else
            {
                for (int j = i + 1; j <= focusWindowIndex; j++)
                    swapWindows(j, focusWindowIndex);
            }
            return;
        }
    }

    subWindows[focusWindowIndex]->Move(startWindowPosition.x, startWindowPosition.y);
    focusWindowIndex = -1;
}

void MainWindow::onMouseLeave(const XEvent &)
{
    if (focusWindowIndex == -1)
        return;

    subWindows[focusWindowIndex]->Move(startWindowPosition.x, startWindowPosition.y);
    focusWindowIndex = -1;
}

void MainWindow::onMouseMotion(const XEvent& event)
{
    if (focusWindowIndex == -1)
        return;

    if (subWindows[focusWindowIndex]->getWindow() == event.xmotion.window)
    {
        subWindows[focusWindowIndex]->setX(subWindows[focusWindowIndex]->getX() + event.xmotion.x - mouseLastPosition.x);
        XMoveWindow(getDisplay(), subWindows[focusWindowIndex]->getWindow(),
                    subWindows[focusWindowIndex]->getX(), subWindows[focusWindowIndex]->getY());
    }
}

void MainWindow::onKeyDown(const XEvent& event)
{
    KeySym sym = XkbKeycodeToKeysym(getDisplay(), event.xkey.keycode, 0, 0);

    if (sym == XK_Escape)
    {
        for (int i = 0; i < word.size(); i++)
            subWindowLetters[i] = string(1, word[i]);
        for (int i = 1; i < word.size() + 1; i++)
        {
            subWindows[i]->Clear();
            subWindows[i]->setFont("9x15");
            subWindows[i]->DrawString(20, 30, subWindowLetters[i - 1], Color("#000000"));
        }
    }
}

void MainWindow::swapWindows(int first, int second)
{
    int firstX = subWindows[first]->getX();
    int firstY = subWindows[second]->getY();
    subWindows[first]->Move(subWindows[second]->getX(), subWindows[second]->getY());
    subWindows[second]->Move(firstX, firstY);

    XWindow* window = subWindows[first];
    subWindows[first] = subWindows[second];
    subWindows[second] = window;

    char letter = subWindowLetters[first - 1][0];
    subWindowLetters[first - 1] = subWindowLetters[second - 1];
    subWindowLetters[second - 1] = string(1, letter);
}

