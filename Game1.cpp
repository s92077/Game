#include "class.h"
#include "framework.h"
Game1::Game1(){
    init();
}
Game1::~Game1(){
    clear();
}
int Game1::run(){
    char str[30];breaktime=0;
    bar.t.start();
    while( !quit )
    {
        fps.stop();
        fps.start();
        bar.show();
        while( SDL_PollEvent( &event ) )
        {
            //Handle events for the square
            alarm.handle_input();
            //Handle events for the screen
            myWindow.handle_events();

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                //quit = true;
                clean_up();
                //SDL_Quit();
                exit (EXIT_FAILURE);
            }
            if( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p )
            {
                if( bar.t.is_paused() == false )
                {
                    //Unpause the timer
                    bar.t.pause();
                    setup=0;
                }
                while(!quit && bar.t.is_paused() == true){
                    fps.stop();
                    fps.start();
                    while(SDL_PollEvent( &event )){
                        //If the timer is paused
                        if( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p  )
                        {
                            //Unpause the timer
                            bar.t.unpause();
                        }
                        if( event.type == SDL_QUIT )
                            exit (EXIT_FAILURE);
                    }
                    /*if(setup==0){
                        apply_surface( 0, 0, background1, screen );
                        vc.show();
                        if( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }
                        setup=1;
                    }*/
                    apply_surface( 0, 0, background1, screen );
                    if( SDL_Flip( screen ) == -1 )
                    {
                        return 1;
                    }
                    setup=1;
                    if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                    {
                        SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                    }
                }
            }
        }
        if(bar.life>0)
        alarm.move();
        alarm.show();
        for(int i=0;i<3;i++){
            hand[i].move(alarm.box,bar);
            hand[i].show();
        }
        if(hand[0].status!=HAND_Stop && hand[1].status!=HAND_Stop && hand[2].status!=HAND_Stop)
            Mix_PlayChannel( -1, girlshout[0], 0 );
        if(bar.life<=0){
            bar.t.pause();
            sprintf(str,"惰性控制了你 . . .");
            alpha+=5;
            //Set surface alpha
            SDL_SetAlpha( lose, SDL_SRCALPHA, alpha );
            seconds=TTF_RenderUTF8_Solid( font, str, fc );
            //seconds=TTF_RenderText_Solid( font, "You lose...", fc );
            apply_surface( 260, 220, seconds, lose );
            temp = SDL_DisplayFormat(lose);
            SDL_SetColorKey( temp, SDL_SRCCOLORKEY, SDL_MapRGB( temp->format, 0, 0xFF, 0xFF ) );
            SDL_FreeSurface(seconds);
            //Apply the front
            apply_surface( 0, 0, temp, screen );
            SDL_FreeSurface(temp);
            if(alpha >SDL_ALPHA_OPAQUE-10){
                alpha-=5;
                breaktime+=fps.get_ticks();
                if(breaktime>2000){
                    SDL_FreeSurface(win);
                    SDL_FreeSurface(lose);
                    break;
                }
            }
        }
        if(bar.t.get_ticks()>30000){
            bar.t.pause();
            sprintf(str,"你終於醒了 . . .");
            alpha+=5;
            //Set surface alpha
            SDL_SetAlpha( win, SDL_SRCALPHA, alpha );
            seconds=TTF_RenderUTF8_Solid( font, str, textColor );
            //seconds=TTF_RenderText_Solid( font, "You lose...", fc );
            apply_surface( 260, 220, seconds, win );
            temp = SDL_DisplayFormat(win);
            SDL_SetColorKey( temp, SDL_SRCCOLORKEY, SDL_MapRGB( temp->format, 0, 0xFF, 0xFF ) );
            SDL_FreeSurface(seconds);
            //Apply the front
            apply_surface( 0, 0, temp, screen );
            SDL_FreeSurface(temp);
            if(alpha >SDL_ALPHA_OPAQUE-10){
                alpha-=5;
                breaktime+=fps.get_ticks();
                if(breaktime>2000){
                    SDL_FreeSurface(win);
                    SDL_FreeSurface(lose);
                    break;
                }
            }
        }
        SDL_Flip(screen);
        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }
}
int Game1::init(){

    quit = false;
}
int Game1::clear(){
    bar.clear();
    alarm.clear();
    hand[0].clear();
    hand[1].clear();
    hand[2].clear();
}

