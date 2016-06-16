#include"class.h"
CenterEnemy::CenterEnemy()
{
    //Initialize the offsets
    x = 1200;
    y = 850;

    //Initialize animation variables
    frame = 0;
    status = CENTERENEMY_Down;
}


void CenterEnemy::show()
{

     //Set the animation to left
        status = CENTERENEMY_Down;

        //Move to the next frame in the animation
        frame++;


    //Loop the animation
    if( frame >= 4 )
    {
        frame = 0;
    }

        apply_surface( x - camera.x,y - camera.y, centerenemy, screen , &centerenemyDown[ frame ] );

}
