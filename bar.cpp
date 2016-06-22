#include "Alarm.h"
#include <stdlib.h>
#include <iostream>

Bar::Bar(){
    TTF_Init();
    f = TTF_OpenFont( "lazy.ttf", 24 );
    heart=load_image("./picture/heart.png");
    bk=load_image("./picture/bk.jpg");
    t.start();
    life = 3;
}
Bar::~Bar(){
    clear();
}
void Bar::clear(){
    SDL_FreeSurface(heart);
    SDL_FreeSurface(bk);
    TTF_CloseFont(f);
}
void Bar::show(){
    SDL_Rect box{20,20,32,32};
    SDL_Color{0,0,0};
    char str[20];

    //Convert the timer's time to a string
    sprintf(str, "Timer: %d",30-t.get_ticks()/1000);

    //Render the time surface
    apply_surface(0,0,bk,screen);
    info = TTF_RenderText_Solid( f, str, textColor );
    apply_surface(280,25,info,screen);
    SDL_FreeSurface(info);


    for(int i=0;i<life;i++){
        apply_surface( box.x, box.y, heart, screen );
        box.x+=32;
    }

}
