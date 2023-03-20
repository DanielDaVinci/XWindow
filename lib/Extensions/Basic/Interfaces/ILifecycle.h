#ifndef XWINDOW_ILIFECYCLE_H
#define XWINDOW_ILIFECYCLE_H

class ILifecycle
{
public:
    /* Lifecycle events */
    virtual void onInitialize() = 0;
    virtual void onCreate() = 0;
    virtual void onDraw() = 0;
    virtual void onTermination() = 0;
    virtual void onDestroy() = 0;
};

#endif
