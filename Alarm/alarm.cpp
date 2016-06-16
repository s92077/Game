#include"core.h"
//extern LTexture gDotTexture;
Dot::Dot(int x,int y,SDL_Rect &box)
{
    //Initialize the offsets
    box.x = x;
    box.y = y;
    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= 0; break;
            case SDLK_DOWN: mVelY += 0; break;
            case SDLK_LEFT: mVelX -= DOT_VEL; break;
            case SDLK_RIGHT: mVelX += DOT_VEL; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += 0; break;
            case SDLK_DOWN: mVelY -= 0; break;
            case SDLK_LEFT: mVelX += DOT_VEL; break;
            case SDLK_RIGHT: mVelX -= DOT_VEL; break;
        }
    }
}
void Dot::move(SDL_Rect &box)
{
    //Move the dot left or right
    box.x += mVelX;

    //If the dot went too far to the left or right
    if( ( box.x < 40 ) || ( box.x + box.w > SCREEN_WIDTH-40 ) )
    {
        //Move back
        box.x -= mVelX;
    }

    //Move the dot up or down
    box.y += mVelY;

    //If the dot went too far up or down
    if( ( box.y < 0 ) || ( box.y + box.h > SCREEN_HEIGHT ) )
    {
        //Move back
        box.y -= mVelY;
    }
}
