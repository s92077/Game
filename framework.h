#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include "global.h"

//Our window
class Window
{
    private:
    //Whether the window is windowed or not
    bool windowed;

    //Whether the window is fine
    bool windowOK;

    public:
    //Constructor
    Window();

    //Handle window events
    void handle_events();

    //Turn fullscreen on/off
    void toggle_fullscreen();

    //Check if anything's wrong with the window
    bool error();
};

//The timer
class Timer
{
    private:
    //The clock time when the timer started
    int startTicks;

    //The ticks stored when the timer was paused
    int pausedTicks;

    //The timer status
    bool paused;
    bool started;

    public:
    //Initializes variables
    Timer();

    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    //Gets the timer's time
    int get_ticks();

    //Checks the status of the timer
    bool is_started();
    bool is_paused();
};

extern Timer fps;
extern Window myWindow;

#endif
