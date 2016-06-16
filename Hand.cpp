#include "Alarm.h"
#include "global.h"

//extern Bar bar;
Hand::Hand()
{
    hand=load_image("./picture/hand1.png");
    //Initialize the offsets
    box.x = 40 + rand() % ( 640 - HAND_WIDTH - 82 );
    box.y = 70;

    //Set the square's dimentions
    box.w = HAND_WIDTH;
    box.h = HAND_HEIGHT;

    //Initialize the velocity
    xVel = 0;
    yVel = 0;

    //Initialize animation variables
    status = rand()%2;
    timer.start();
    time=rand()%5000;
}
void Hand::clear(){
    SDL_FreeSurface(hand);
}
void Hand::move(SDL_Rect &box1,Bar &b)
{
    if(status==HAND_Right){
        if(timer.get_ticks()<time){
            box.x+=10;
            if( ( box.x < 40 ) || ( box.x + box.w > SCREEN_WIDTH-40 ) ){
                box.x-=10;
                status=HAND_Left;
            }
        }
        else{
            status=HAND_Down;
        }
    }
    if(status==HAND_Left){
        if(timer.get_ticks()<time){
            box.x-=10;
            if( ( box.x < 40 ) || ( box.x + box.w > SCREEN_WIDTH-40 ) ){
                box.x+=10;
                status=HAND_Right;
            }
        }
        else{
            status=HAND_Down;
        }
    }
    if(status==HAND_Down){
        if(!check_collision(box,box1)){
            box.y += 10;
            //printf("%d",checkCollision(box,alarm.mRect));
            if( ( box.y < 70 ) || ( box.y + box.h > SCREEN_HEIGHT - 30 ) )
            {
                //Move back
                box.y -= 10;
                status=HAND_Up;
            }
        }
        else{
            b.life--;
            status=HAND_Stop;
            time=rand()%2000;
            timer.stop();
            timer.start();
        }
    }
    if(status==HAND_Up){
        box.y -= 10;
        if( ( box.y < 70 ) || ( box.y + box.h > SCREEN_HEIGHT - 30 ) )
        {
            //Move back
            box.y += 10;
            status=rand()%2;
            time=rand()%5000;
            timer.stop();
            timer.start();
        }
    }
    if(status==HAND_Stop){
        Mix_PauseMusic();
        if(timer.get_ticks()>500){
            timer.stop();
            timer.start();
            status=HAND_Up;
        }
    }
}



void Hand::show()
{
    apply_surface( box.x, box.y, hand, screen  );
}

Hand::~Hand(){
    clear();
}
