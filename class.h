#ifndef CLASS_H
#define CLASS_H
#include "global.h"
#include "framework.h"
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
};

class Menu
{
public:
    Menu();
    SDL_Surface *menuback;
    void show();
    Button startbutton{220,220,199,62,"./picture/button.png"};
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
    int pressedTime;
    void clear();
    //Timer clicktime;
};
class Game1{
public:
    Game1();
    ~Game1();
    int run();
    int init();
    int clear();
private:
    bool quit;
    Alarm alarm;
    Hand hand[3];
    Bar bar;
    int alpha = SDL_ALPHA_TRANSPARENT;
    SDL_Color fc{255,255,255};
    SDL_Surface *win=load_image("./picture/fadein.png"),*lose=load_image("./picture/background.png"),*temp;
    int setup=1;
    int breaktime;
};
#endif // CLASS_H
