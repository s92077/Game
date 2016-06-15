#include "class.h"

Boss::Boss()
{
    //Initialize the offsets
    x = 1200;
    y = 850;

    //Initialize the velocity
    xVel = 6;
    yVel = 6;

    //Initialize animation variables
    frame = 0;
    status = BOSS_Down;
}

void Boss::move(int a,int b,int tm)
{
     if(tm%2==0)
     {
         if(x<a)
         {
             x+=xVel;
         }
         if(x>a)
         {
             x-=xVel;
         }
     }
     if(tm%2==1)
     {
         if(y<b)
         {
             y+=yVel;
         }
         if(y>b)
         {
             y-=yVel;
         }
     }
}


void Boss::show()
{
     //Set the animation to left
        status = BOSS_Down;

        //Move to the next frame in the animation
        frame++;


    //Loop the animation
    if( frame >= 2 )
    {
        frame = 0;
    }

        apply_surface( x - camera.x,y - camera.y, boss, screen , &bossDown[ frame ] );

}



