#include "class.h"

Square::Square()
{
    //Initialize the offsets
    box.x = 0;
    box.y = 0;

    //Set the square's dimentions
    box.w = SQUARE_WIDTH;
    box.h = SQUARE_HEIGHT;

    //Initialize the velocity
    xVel = 0;
    yVel = 0;

    //Initialize animation variables
    frame = 0;
    status = SQUARE_Down;
}

void Square::handle_input()
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
        case SDLK_UP: yVel -= 10; break;
        case SDLK_DOWN: yVel += 10; break;
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
        case SDLK_UP: yVel += 10; break;
        case SDLK_DOWN: yVel -= 10; break;
        case SDLK_LEFT: xVel += 10; break;
        case SDLK_RIGHT: xVel -= 10; break;
        }
    }
}

void Square::move()
{
    //Move the square left or right
    box.x += xVel;

    //If the square went too far to the left or right or has collided with the wall
    if(
    ( box.x < 0 )
    || ( box.x + SQUARE_WIDTH > LEVEL_WIDTH )
    || ( check_collision( box, wall[0] ) )
    || ( check_collision( box, wall[1] ) )
    || ( check_collision( box, wall[2] ) )
    || ( check_collision( box, wall[3] ) )
    || ( check_collision( box, wall[4] ) )
    || ( check_collision( box, wall[5] ) )
    || ( check_collision( box, wall[6] ) )
    || ( check_collision( box, wall[7] ) )
    || ( check_collision( box, wall[8] ) )
    || ( check_collision( box, wall[9] ) )
    || ( check_collision( box, wall[10] ) )
    || ( check_collision( box, wall[11] ) )
    || ( check_collision( box, wall[12] ) )
    || ( check_collision( box, wall[13] ) )
    || ( check_collision( box, wall[14] ) )
    || ( check_collision( box, wall[15] ) )
    || ( check_collision( box, wall[16] ) )
    || ( check_collision( box, wall[17] ) )
    || ( check_collision( box, wall[18] ) )
    )
    {

    //Move back
    box.x -= xVel;
    }

    //Move the square up or down
    box.y += yVel;

    //If the square went too far up or down or has collided with the wall
    if(
    ( box.y < 0 )
    || ( box.y + SQUARE_HEIGHT > LEVEL_HEIGHT )
    || ( check_collision( box, wall[0] ) )
    || ( check_collision( box, wall[1] ) )
    || ( check_collision( box, wall[2] ) )
    || ( check_collision( box, wall[3] ) )
    || ( check_collision( box, wall[4] ) )
    || ( check_collision( box, wall[5] ) )
    || ( check_collision( box, wall[6] ) )
    || ( check_collision( box, wall[7] ) )
    || ( check_collision( box, wall[8] ) )
    || ( check_collision( box, wall[9] ) )
    || ( check_collision( box, wall[10] ) )
    || ( check_collision( box, wall[11] ) )
    || ( check_collision( box, wall[12] ) )
    || ( check_collision( box, wall[13] ) )
    || ( check_collision( box, wall[14] ) )
    || ( check_collision( box, wall[15] ) )
    || ( check_collision( box, wall[16] ) )
    || ( check_collision( box, wall[17] ) )
    || ( check_collision( box, wall[18] ) )
    )
    {
    //move back
    box.y -= yVel;
    }
}





void Square::show()
{

     //If Foo is moving left
    if( xVel < 0 && yVel == 0)
    {
        //Set the animation to left
        status = SQUARE_Left;

        //Move to the next frame in the animation
        frame++;
    }
    //If Foo is moving right
    else if( xVel > 0 && yVel == 0)
    {
        //Set the animation to right
        status = SQUARE_Right;

        //Move to the next frame in the animation
        frame++;
    }
    else if( xVel == 0 && yVel > 0)
    {
         //Set the animation to right
        status = SQUARE_Down;

        //Move to the next frame in the animation
        frame++;
        }
    else if( xVel == 0 && yVel < 0)
    {
         //Set the animation to right
        status = SQUARE_Up;

        //Move to the next frame in the animation
        frame++;
        }
    else if( xVel > 0 && yVel > 0)
    {
         //Set the animation to right
        status = SQUARE_DownRight;

        //Move to the next frame in the animation
        frame++;
        }
    else if( xVel < 0 && yVel > 0)
    {
         //Set the animation to right
        status = SQUARE_DownLeft;

        //Move to the next frame in the animation
        frame++;
        }
    else if( xVel > 0 && yVel < 0)
    {
         //Set the animation to right
        status = SQUARE_UpRight;

        //Move to the next frame in the animation
        frame++;
        }
     else if( xVel < 0 && yVel < 0)
    {
         //Set the animation to right
        status = SQUARE_UpLeft;

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
    if( status == SQUARE_Left )
    {
        apply_surface( box.x - camera.x, box.y - camera.y, square, screen, &clipsLeft[ frame ]  );
    }
    else if( status == SQUARE_Right )
    {
        apply_surface( box.x - camera.x, box.y - camera.y, square, screen, &clipsRight[ frame ]  );
    }
    else if( status == SQUARE_Up )
    {
        apply_surface( box.x - camera.x, box.y - camera.y, square, screen, &clipsUp[ frame ]  );
    }
    else if( status == SQUARE_Down )
    {
        apply_surface( box.x - camera.x, box.y - camera.y, square, screen, &clipsDown[ frame ]  );
    }
    else if( status == SQUARE_DownLeft )
    {
        apply_surface( box.x - camera.x, box.y - camera.y, square, screen, &clipsDownLeft[ frame ]  );
    }
    else if( status == SQUARE_DownRight )
    {
        apply_surface( box.x - camera.x, box.y - camera.y, square, screen, &clipsDownRight[ frame ]  );
    }
    else if( status == SQUARE_UpLeft )
    {
        apply_surface( box.x - camera.x, box.y - camera.y, square, screen, &clipsUpLeft[ frame ]  );
    }
    else if( status == SQUARE_UpRight )
    {
        apply_surface( box.x - camera.x, box.y - camera.y, square, screen, &clipsUpRight[ frame ]  );
    }

}



void Square::set_camera()
{
    //Center the camera over the dot
    camera.x = ( box.x + SQUARE_WIDTH / 2 ) - SCREEN_WIDTH / 2;
    camera.y = ( box.y + SQUARE_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;

    //Keep the camera in bounds.
    if( camera.x < 0 )
    {
    camera.x = 0;
    }
    if( camera.y < 0 )
    {
    camera.y = 0;
    }
    if( camera.x > LEVEL_WIDTH - camera.w )
    {
    camera.x = LEVEL_WIDTH - camera.w;
    }
    if( camera.y > LEVEL_HEIGHT - camera.h )
    {
    camera.y = LEVEL_HEIGHT - camera.h;
    }
}
