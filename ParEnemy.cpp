#include "class.h"

void ParEnemy::move(int a,int b)
{
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
    else
    {
        x+=xVel;
        if(x+20>=1920)
        {
            x=0;
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
}


void ParEnemy::show()
{

        //Set the animation to left
        status = PARENEMY_Right;

        //Move to the next frame in the animation
        frame++;

    //Loop the animation
    if( frame >= 4 )
    {
        frame = 0;
    }

        apply_surface( x - camera.x,y - camera.y, parenemy, screen , &parenemyRight[ frame ] );


}
