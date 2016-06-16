#include "core.h"
#include <stdlib.h>
#include <time.h>
extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;
extern LTexture alarm;
bool checkCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if(b.x-a.w+5<=a.x&&b.x+b.w-5>=a.x&&b.y-a.h+5<=a.y&&b.y+b.h-5>=a.y)
        return true;

    //If none of the sides from A are outside B
    return false;
}
Hand::Hand(int x,int y,SDL_Rect &box)
{
    //Initialize the offsets
    box.x = x;
    box.y = y;
    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
    timer.start();
    time=rand()%5000;
    printf("%d %d %d %d\n",box.x,box.y,box.w,box.h);
    printf("%d %d %d %d\n",alarm.mRect.x,alarm.mRect.y,alarm.mRect.w,alarm.mRect.h);

}
void Hand::automove(SDL_Rect &box,SDL_Rect &box1)
{
    //printf("%d\n",timer.get_ticks());
    if(timer.get_ticks()<time){
    if(mr==1){
        box.x += 5;
        //If the dot went too far to the left or right
        if( ( box.x < 40 ) || ( box.x + box.w > SCREEN_WIDTH-40 ) )
        {
            //Move back
            box.x -= 5;
            mr=0;
        }
    }
    else{
        box.x -= 5;

        //If the dot went too far to the left or right
        if( ( box.x < 40 ) || ( box.x + box.w > SCREEN_WIDTH-40 ) )
        {
            //Move back
            box.x += 5;
            mr=1;
        }
    }
    }
    else{
    if(md==1){
        //If the dot went too far to the left or right
        printf("%d",checkCollision(box,box1));
        if(!checkCollision(box,box1)){
            box.y += 5;
            //printf("%d",checkCollision(box,alarm.mRect));
            if( ( box.y < 30 ) || ( box.y + box.h > SCREEN_HEIGHT - 30 ) )
            {
                //Move back
                box.y -= 5;
                md=0;
                mr=0;
            }
        }
        else{
            time=0;
            md=0;
            timer.stop();
            timer.start();
            for(;timer.get_ticks()<500;){;}
        }
    }
    else{
        box.y -= 5;
        //If the dot went too far to the left or right
        if( ( box.y < 30 ) || ( box.y + box.h > SCREEN_HEIGHT - 30 ) )
        {
            //Move back
            box.y += 5;
            md=1;
            timer.stop();
            timer.start();
            time=rand()%5000;
        }
    }
    }
}


void Hand::render(LTexture &gDotTexture)
{
    //Show the dot
	gDotTexture.render( gDotTexture.mRect.x, gDotTexture.mRect.y );
}
