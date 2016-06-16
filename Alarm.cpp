#include "Alarm.h"

SDL_Rect AlarmLeft[ 4 ];
SDL_Rect AlarmRight[ 4 ];

Alarm::Alarm()
{
    for(int i=0;i<4;i++){
        AlarmLeft[i].x = ALARM_WIDTH * i;
        AlarmLeft[i].y = 0;
        AlarmLeft[i].w = ALARM_WIDTH;
        AlarmLeft[i].h = ALARM_HEIGHT;

        AlarmRight[i].x = ALARM_WIDTH * i;
        AlarmRight[i].y = 0;
        AlarmRight[i].w = ALARM_WIDTH;
        AlarmRight[i].h = ALARM_HEIGHT;
    }

    alarm = load_image("./picture/alarm1.png");

    //Initialize the offsets
    box.x = 30;
    box.y = 350;

    //Set the square's dimentions
    box.w = ALARM_WIDTH;
    box.h = ALARM_HEIGHT;

    //Initialize the velocity
    xVel = 0;
    yVel = 0;

    //Initialize animation variables
    frame = 0;
    status = SQUARE_Down;
}

void Alarm::handle_input()
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_LEFT: xVel -= 10; break;
            case SDLK_RIGHT: xVel += 10; break;
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_LEFT: xVel += 10; break;
            case SDLK_RIGHT: xVel -= 10; break;
        }
    }
}

void Alarm::move()
{
    //Move the square left or right
    box.x += xVel;

    //If the square went too far to the left or right or has collided with the wall
    if( ( box.x ) < 0 || ( box.x + ALARM_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        box.x -= xVel;
    }

}





void Alarm::show()
{

     //If Foo is moving left
    if( xVel < 0 && yVel == 0)
    {
        //Set the animation to left
        status = ALARM_Left;

        //Move to the next frame in the animation
        //frame++;
    }
    //If Foo is moving right
    else if( xVel > 0 && yVel == 0)
    {
        //Set the animation to right
        status = ALARM_Right;

        //Move to the next frame in the animation
        //frame++;
    }




    //Show the stick figure
    if( status == ALARM_Left )
    {
        apply_surface( box.x , box.y , alarm, screen, &AlarmLeft[ frame ]  );
        frame=(frame+1)%4;
    }
    else if( status == ALARM_Right )
    {
        apply_surface( box.x , box.y , alarm, screen, &AlarmRight[ frame ]  );
        frame=(frame+1)%4;
    }

}
void Alarm::clear(){
    SDL_FreeSurface(alarm);
}
Alarm::~Alarm(){
    clear();
}
