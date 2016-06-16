#include "class.h"
#define CLIP_MOUSEOVER 0
#define CLIP_MOUSEOUT 1
#define CLIP_MOUSEDOWN 2


Button::Button( int x, int y, int w, int h, char *str )
{
    buttonSheet = load_image(str);
    int BUTTON_HEIGHT=buttonSheet->h/2,BUTTON_WIDTH=buttonSheet->w;

    num=1;
    //Set the button's attributes
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;

    //Set the default sprite
    clips[0].x=0;
    clips[0].y=0;
    clips[0].w=BUTTON_WIDTH;
    clips[0].h=BUTTON_HEIGHT;

    clips[1].x=0;
    clips[1].y=BUTTON_HEIGHT;
    clips[1].w=BUTTON_WIDTH;
    clips[1].h=BUTTON_HEIGHT;
}
Button::Button()
{
}
void Button::init( int x, int y, int w, int h, char str[] ){
    buttonSheet = load_image(str);
    int BUTTON_HEIGHT=buttonSheet->h/2,BUTTON_WIDTH=buttonSheet->w;

    num=1;
    //Set the button's attributes
    box.x = x;
    box.y = y;
    box.w = w;
    box.h = h;

    //Set the default sprite
    clips[0].x=0;
    clips[0].y=0;
    clips[0].w=BUTTON_WIDTH;
    clips[0].h=BUTTON_HEIGHT;

    clips[1].x=0;
    clips[1].y=BUTTON_HEIGHT;
    clips[1].w=BUTTON_WIDTH;
    clips[1].h=BUTTON_HEIGHT;
}

void Button::handle_events()
{
    //The mouse offsets
    int x = 0, y = 0;

    //If the mouse moved
    if( event.type == SDL_MOUSEMOTION )
    {
        //Get the mouse offsets
        x = event.motion.x;
        y = event.motion.y;

        //If the mouse is over the button
        if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
        {
            //Set the button sprite
            clip = &clips[ CLIP_MOUSEOVER ];
            num=0;
        }
        //If not
        else
        {
            //Set the button sprite
            clip = &clips[ CLIP_MOUSEOUT ];
            num=1;
        }
    }
    //If a mouse button was pressed
    else if( event.type == SDL_MOUSEBUTTONDOWN )
    {
        //If the left mouse button was pressed
        if( event.button.button == SDL_BUTTON_LEFT )
        {
            //Get the mouse offsets
            x = event.button.x;
            y = event.button.y;

            //If the mouse is over the button
            if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
            {
                //Set the button sprite
                clip = &clips[ CLIP_MOUSEOVER ];
                num=2;
            }
        }
    }
    else{
        //Get the mouse offsets
        x = event.motion.x;
        y = event.motion.y;

        //If the mouse is over the button
        if( ( x > box.x ) && ( x < box.x + box.w ) && ( y > box.y ) && ( y < box.y + box.h ) )
        {
            //Set the button sprite
            clip = &clips[ CLIP_MOUSEOVER ];
            num=0;
        }
        //If not
        else
        {
            //Set the button sprite
            clip = &clips[ CLIP_MOUSEOUT ];
            num=1;
        }
    }
}

void Button::show()
{
    //Show the button
    apply_surface( box.x, box.y, buttonSheet, screen, clip );
}
void Button::clear(){
    SDL_FreeSurface(buttonSheet);
}
Button::~Button(){
    clear();
}
