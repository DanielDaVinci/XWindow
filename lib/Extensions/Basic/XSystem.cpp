#include "XSystem.h"

XSystem::XSystem()
{
    Display* display = XOpenDisplay(NULL);
    if (display == NULL)
        throw std::invalid_argument("Can not connect to the X server!\n");

    screen = XDefaultScreenOfDisplay(display);

    screenNumber = DefaultScreen(display);
}

XSystem::~XSystem()
{
    XCloseDisplay(screen->display);
}