#ifndef CLASS_H
#define CLASS_H
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



    //The square
class Square
{
    public:
    //The collision box of the square
    SDL_Rect box;

    //The velocity of the dot
    int xVel, yVel;

    //Initializes the variables
    Square();

    //Its current frame
    int frame;

    //Its animation status
    int status;

    //Takes key presses and adjusts the square's velocity
    void handle_input();

    //Moves the square
    void move();

    //Shows the dot on the screen
    void show();

    //Sets the camera over the square
    void set_camera();
};

class Enemy
{
    public:

    int x,y;

    int xVel,yVel;

    Enemy();

    //Its current frame
    int frame;

    //Its animation status
    int status;

    void move(int a,int b,int eym);

    void show();

};

class OrthoEnemy
{

    public:

    int x,y;

    int xVel,yVel;

    OrthoEnemy();

    //Its current frame
    int frame;

    //Its animation status
    int status;

    void move(int a,int b);

    void show();

};



class ParEnemy
{

    public:

    int x,y;

    int xVel,yVel;

    ParEnemy();

    //Its current frame
    int frame;

    //Its animation status
    int status;

    void move(int a,int b);

    void show();

};

class RandEnemy
{

    public:

    int x,y;

    int xVel,yVel;

    RandEnemy();

    //Its current frame
    int frame;

    //Its animation status
    int status;

    void move(int a,int b,int tm);

    void show();

};



class Boss
{

    public:

    int x,y;

    int xVel,yVel;

    Boss();

    //Its current frame
    int frame;

    //Its animation status
    int status;

    void move(int a,int b,int tm);

    void show();

};


class CenterEnemy
{

    public:

    int x,y;

    CenterEnemy();

    //Its current frame
    int frame;

    //Its animation status
    int status;

    void show();

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

//The button
class Button
{
    private:
    //The attributes of the button
    SDL_Rect box;

    //The part of the button sprite sheet that will be shown
    SDL_Rect *clip;
    SDL_Rect clips[2];
    SDL_Surface *buttonSheet;

    public:
    int num;
    void clear();
    ~Button();
    //Initialize the variables
    Button( int x, int y, int w, int h, char str[] );
    Button();
    void init( int x, int y, int w, int h, char str[] );

    //Handles events and set the button's sprite region
    void handle_events();

    //Shows the button on the screen
    void show();
    void show(int x,int y);
};

class Menu
{
public:
    Menu();
    SDL_Surface *menuback;
    void show();
    int bstatus;
    Button startbutton{280,220,199,62,"./picture/button.png"};
    void clear();
    //Button exitbutton{280,320,199,62,"./picture/button.png"};
};
class Volume
{
public:
    Volume();
    void show();
    int pressed;
    Button volumebutton[2];
    //Button percent[11];
    int appear;
    int volume;
    void clear();
    //Timer clicktime;
};

#endif // CLASS_H
