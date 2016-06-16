#pragma once
#ifndef ALARM_H
#define ALARM_H

#include "class.h"
//The attributes of the Alarm
#define ALARM_WIDTH 96
#define ALARM_HEIGHT 102
#define HAND_WIDTH 201
#define HAND_HEIGHT 63

//The direction status of the stick figure

#define ALARM_Left 0
#define ALARM_Right 1
#define HAND_Left 0
#define HAND_Right 1
#define HAND_Up 2
#define HAND_Down 3
#define HAND_Stop 4

//The frame rate regulator
extern Timer fps;

//The square
class Alarm
{
    public:
    SDL_Surface *alarm;
    //The collision box of the square
    SDL_Rect box;

    //The velocity of the dot
    int xVel, yVel;

    //Initializes the variables
    Alarm();
    ~Alarm();

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
    void clear();

    //Sets the camera over the square
};
class Bar{
public:
    Timer t;
    int life;
    TTF_Font *f;
    SDL_Surface *heart;
    SDL_Surface *info;
    SDL_Surface *bk;
    void show();
    Bar();
    ~Bar();
    void clear();
};
class Hand
{
    public:
    Timer timer;
    int time;
    SDL_Surface *hand;
    //The collision box of the square
    SDL_Rect box;

    //The velocity of the dot
    int xVel, yVel;

    //Initializes the variables
    Hand();
    ~Hand();

    //Its animation status
    int status;

    //Moves the square
    void move(SDL_Rect &,Bar &);

    //Shows the dot on the screen
    void show();
    void clear();

};

#endif // CLASS_H
