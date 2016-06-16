#include "class.h"

OrthoEnemy::OrthoEnemy()
{
    //Initialize the offsets
    x = 0;
    y = 0;

    //Initialize the velocity
    xVel = 15;
    yVel = 20;

    //Initialize animation variables
    frame = 0;
    status = ORTHOENEMY_Down;
}

void OrthoEnemy::move(int a,int b)
{
    int crashy;
    if(abs(x-a)<30&&abs(y-b)<30)
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
    if(abs(y-b)<30&&abs(x-a)<30)
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
        y+=yVel;
        if(y+20>=1440)
        {
            y=0;
        }
    }
}


void OrthoEnemy::show()
{

        //Set the animation to left
        status = ORTHOENEMY_Down;

        //Move to the next frame in the animation
        frame++;


    //Loop the animation
    if( frame >= 4 )
    {
        frame = 0;
    }

        apply_surface( x - camera.x,y - camera.y, orthoenemy, screen , &orthoenemyDown[ frame ] );

}

ParEnemy::ParEnemy()
{
    //Initialize the offsets
    x = 0;
    y = 0;

    //Initialize the velocity
    xVel = 20;
    yVel = 150;

    //Initialize animation variables
    frame = 0;
    status = PARENEMY_Right;
}
