#include "class.h"

Enemy::Enemy()
{
    //Initialize the offsets
    x = 0;
    y = 0;

    //Initialize the velocity
    xVel = 0;
    yVel = 0;

    //Initialize animation variables
    frame = 0;
    status = ENEMY_Down;
}

void Enemy::move(int a,int b,int eym)
{

   if(eym==1)
   {
        if(abs(a - x)<= 60 &&  ( ((b >= y)&&(b-y<=110))|| ((b <= y)&&(y-b<=80))   )   )
        {
            if(x<a)
            {
            xVel=10;
            x+=xVel;
            }
            else if(x>a)
            {
            xVel=-10;
            x+=xVel;
            }
        }
        else if(x<a)
        {
            xVel=5;
            x+=xVel;
        }
        else if(x>a)
        {
            xVel=-5;
            x+=xVel;
        }

        if(abs(a - x)<= 60 &&  ( ((b >= y)&&(b-y<=110))|| ((b <= y)&&(y-b<=80))   )   )
        {
            if(y<b)
            {
            yVel=10;
            y+=yVel;
            }
            else if(y>b)
            {
            yVel=-10;
            y+=yVel;
            }
        }
        else if(y<b)
        {
            yVel=5;
            y+=yVel;
        }
        else if(y>b)
        {
            yVel=-5;
            y+=yVel;
        }
   }

   if(eym==2)
   {
        if(abs(a - x)<= 60 &&  ( ((b >= y)&&(b-y<=110))|| ((b <=y)&&(y-b<=80))   )   )
        {
            if(x<a)
            {
            xVel=10;
            x+=xVel;
            }
            else if(x>a)
            {
            xVel=-10;
            x+=xVel;
            }
        }
        else if(x<a)
        {
            xVel=4;
            x+=xVel;
        }
        else if(x>a)
        {
            xVel=-4;
            x+=xVel;
        }

        if(abs(a - x)<= 60 &&  ( ((b >= y)&&(b-y<=110))|| ((b <= y)&&(y-b<=80))   )   )
        {
            if(y<b)
            {
            yVel=10;
            y+=yVel;
            }
            else if(y>b)
            {
            yVel=-10;
            y+=yVel;
            }
        }
        else if(y<b)
        {
            yVel=4;
            y+=yVel;
        }
        else if(y>b)
        {
            yVel=-4;
            y+=yVel;
        }
   }

}

void Enemy::show()
{

     //If Foo is moving left
    if( xVel < 0 && yVel == 0)
    {
        //Set the animation to left
        status = ENEMY_Left;

        //Move to the next frame in the animation
        frame++;
    }
    //If Foo is moving right
    else if( xVel > 0 && yVel == 0)
    {
        //Set the animation to right
        status = ENEMY_Right;

        //Move to the next frame in the animation
        frame++;
    }
    else if( xVel == 0 && yVel > 0)
    {
         //Set the animation to right
        status = ENEMY_Down;

        //Move to the next frame in the animation
        frame++;
        }
    else if( xVel == 0 && yVel < 0)
    {
         //Set the animation to right
        status = ENEMY_Up;

        //Move to the next frame in the animation
        frame++;
        }
    else if( xVel > 0 && yVel > 0)
    {
         //Set the animation to right
        status = ENEMY_DownRight;

        //Move to the next frame in the animation
        frame++;
        }
    else if( xVel < 0 && yVel > 0)
    {
         //Set the animation to right
        status = ENEMY_DownLeft;

        //Move to the next frame in the animation
        frame++;
        }
    else if( xVel > 0 && yVel < 0)
    {
         //Set the animation to right
        status = ENEMY_UpRight;

        //Move to the next frame in the animation
        frame++;
        }
     else if( xVel < 0 && yVel < 0)
    {
         //Set the animation to right
        status = ENEMY_UpLeft;

        //Move to the next frame in the animation
        frame++;
        }
    //If Foo standing
    else
    {
        //Restart the animation
        frame = 0;
    }

        //Loop the animation
        if( frame >= 4 )
        {
            frame = 0;
        }


    //Show the stick figure
    if( status == ENEMY_Left )
    {
        apply_surface( x - camera.x,y - camera.y, enemy, screen , &enemyLeft[ frame ] );
    }
    else if( status == ENEMY_Right )
    {
        apply_surface( x - camera.x,y - camera.y, enemy, screen , &enemyRight[ frame ] );
    }
    else if( status == ENEMY_Up )
    {
        apply_surface( x - camera.x,y - camera.y, enemy, screen , &enemyUp[ frame ] );
    }
    else if( status == ENEMY_Down )
    {
        apply_surface( x - camera.x,y - camera.y, enemy, screen , &enemyDown[ frame ] );
    }
    else if( status == ENEMY_DownLeft )
    {
        apply_surface( x - camera.x,y - camera.y, enemy, screen , &enemyDownLeft[ frame ] );
    }
    else if( status == ENEMY_DownRight )
    {
        apply_surface( x - camera.x,y - camera.y, enemy, screen , &enemyDownRight[ frame ] );
    }
    else if( status == ENEMY_UpLeft )
    {
        apply_surface( x - camera.x,y - camera.y, enemy, screen , &enemyUpLeft[ frame ] );
    }
    else if( status == ENEMY_UpRight )
    {
        apply_surface( x - camera.x,y - camera.y, enemy, screen , &enemyUpRight[ frame ] );
    }

}
