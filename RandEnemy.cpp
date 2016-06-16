#include "class.h"

RandEnemy::RandEnemy()
{
    //Initialize the offsets
    x = 0;
    y = 0;

    //Initialize the velocity
    xVel = 2;
    yVel = 1;

    //Initialize animation variables
    frame = 0;
    status = RANDENEMY_Down;
}

void RandEnemy::move(int a,int b,int tm)
{
    if((((a < x) && (x - a) <= 40)||((a > x) && (a - x <= 35))) && (((b < y)&&(y - b <= 60))|| ((b > y) &&(b - y <= 45))))
    {
        if(x<a)
        {
        xVel=10;
        x+=xVel;
        }
        else if(x>a)
        {
        xVel=10;
        x-=xVel;
        }
    }
    else
    {
        switch(rand()%3)
        {
            case 0:
                 for(int i=tm;i<=tm+5000;i+=200)
                 {
                     x+=xVel;
                     if(x+35>1920)
                     {
                         x=960;
                     }
                 }
                 break;
            case 1:
                 for(int i=tm;i<=tm+5000;i+=200)
                 {
                     x-=xVel;
                     if(x<=0)
                     {
                         x=960;
                     }
                 }
                 break;
            case 2:
                 for(int i=tm;i<=tm+5000;i+=200)
                 {
                     x=x;
                 }
                 break;
        }
    }
    if((((a < x) && (x - a) <= 40)||((a > x) && (a - x <= 35))) && (((b < y)&&(y - b <= 60))|| ((b > y) &&(b - y <= 45))))
    {
        if(y<b)
        {
        yVel=10;
        y+=yVel;
        }
        else if(y>b)
        {
        yVel=10;
        y-=yVel;
        }
    }
    else
    {
        switch(rand()%3)
        {
            case 0:
                 for(int i=tm;i<=tm+5000;i+=200)
                 {
                     y+=yVel;
                     if(y+45>1440)
                     {
                         y=720;
                     }
                 }
                 break;
            case 1:
                 for(int i=tm;i<=tm+5000;i+=200)
                 {
                     y-=yVel;
                     if(y<=0)
                     {
                         y=720;
                     }
                 }
                 break;
            case 2:
                 for(int i=tm;i<=tm+5000;i+=200)
                 {
                     y=y;
                 }
                 break;
        }
    }
}


void RandEnemy::show()
{
     //Set the animation to left
        status = RANDENEMY_Down;

        //Move to the next frame in the animation
        frame++;


    //Loop the animation
    if( frame >= 2 )
    {
        frame = 0;
    }

        apply_surface( x - camera.x,y - camera.y, randenemy, screen , &randenemyDown[ frame ] );

}
