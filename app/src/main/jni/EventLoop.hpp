#ifndef _PACKT_EVENTLOOP_HPP_
#define _PACKT_EVENTLOOP_HPP_

#include "ActivityHandler.hpp"

#include <android_native_app_glue.h>

class EventLoop {
public:
    EventLoop(android_app *pApplication, ActivityHandler &pActivityHandler);

    void run();

private:
    void activate();

    void deactivate();

    void processAppEvent(int32_t pCommand);

    static void callback_appEvent(android_app *pApplication, int32_t pCommand);

private:
    android_app *mApplication;
    ActivityHandler &mActivityHandler;
    bool mEnabled;
    bool mQuit;
};
#endif
