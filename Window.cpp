#include "class.h"
Window::Window()
{
                //Set up the screen
                screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT , SCREEN_BPP, SDL_SWSURFACE /*| SDL_RESIZABLE*/ );

                //If there's an error
                if( screen == NULL )
                {
                   windowOK = false;
                   return;
                }
                 else
                 {
                     windowOK = true;
                 }

        //Set window flag
        windowed = true;
}

void Window::handle_events()
{
    //If there's something wrong with the window
    if( windowOK == false )
    {
    return;
    }

    //If the window resized
    if( event.type == SDL_VIDEORESIZE )
    {
    //Resize the screen
    screen = SDL_SetVideoMode( event.resize.w, event.resize.h, SCREEN_BPP, SDL_SWSURFACE /*| SDL_RESIZABLE*/ );

    //If there's an error
    if( screen == NULL )
    {
    windowOK = false;
    return;
    }
    }
    //If enter was pressed
    else if( ( event.type == SDL_KEYDOWN ) && ( event.key.keysym.sym == SDLK_RETURN ) )
    {
         //Turn fullscreen on/off
         toggle_fullscreen();
    }
    //If the window focus changed
    else if( event.type == SDL_ACTIVEEVENT )
    {
        //If something happened to the mouse focus
        if( event.active.state & SDL_APPMOUSEFOCUS )
        {
            //If the application lost mouse focus
            if( event.active.gain == 0 )
            {
                SDL_WM_SetCaption( "Run & Die! : Mouse Focus Lost", NULL );
            }
            else
            {
                SDL_WM_SetCaption( "Run & Die!", NULL );
            }
        }
    }
    //If the window's screen has been altered
    else if( event.type == SDL_VIDEOEXPOSE )
    {
         //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            //If there's an error
            windowOK = false;
            return;
        }
    }
}

void Window::toggle_fullscreen()
{
    //If the screen is windowed
    if( windowed == true )
    {
    //Set the screen to fullscreen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE /*| SDL_RESIZABLE*/ | SDL_FULLSCREEN );

    //If there's an error
    if( screen == NULL )
    {
    windowOK = false;
    return;
    }

    //Set the window state flag
    windowed = false;
    }
    //If the screen is fullscreen
    else if( windowed == false )
    {
    //Window the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE /*| SDL_RESIZABLE*/ );

    //If there's an error
    if( screen == NULL )
    {
    windowOK = false;
    return;
    }

    //Set the window state flag
    windowed = true;
    }
}

bool Window::error()
{
     return !windowOK;
}
