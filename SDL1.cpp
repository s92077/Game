//The headers
#include "global.h"
#include "class.h"
#include "Alarm.h"
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BUTTON_DELAY 100


int a,b,eym,f=1,r=1,om=1,show[18],life[18],tm;

//The frame rate regulator
Timer fps;

int main( int argc, char* args[] )
{
    char str[30];
    int setup=1;
    //Create a window
    Window myWindow;
    //If the window failed
    if( myWindow.error() == true )
    {
        return 1;
    }
   //Initialize
    if( init() == false )
    {
        return 1;
    }

    if(setup)
    {
        srand(time(NULL));
        int musicstart=rand()%2,stp;

        sprintf(str,"./music/startmusic%d.wav",musicstart);
        //Load the startmusic
        startmusic[musicstart] = Mix_LoadMUS( str );

        //If there was a problem loading the startmusic
        if( startmusic == NULL )
        {
            return false;
        }

        //If there is no music playing
        if( Mix_PlayingMusic() == 0 )
        {
            //Play the music
            if( Mix_PlayMusic( startmusic[musicstart], -1 ) == -1 )
            {
                return 1;
            }
        }
        stp=musicstart;

        //If there was an error in setting up the screen
        if( screen == NULL )
        {
            return 1;
        }

        //Set the window caption
        //SDL_WM_SetCaption( "Run & Die!", NULL );

        if(stp==0)
        {
            //Load the images
            background1 = load_image( "./picture/Start picture.bmp" );
        }
        else
        {
            //Load the images
            background1 = load_image( "./picture/Start picture1.bmp" );
        }
    }

    //Quit flag
    bool quit = false;

    Menu menu;Volume vc;
    menu.show();
    vc.show();
    int ttemp=0;
    apply_surface( 0, 0, background1, screen );
    while(f)
    {
        fps.stop();
        fps.start();
        apply_surface( 0, 0, background1, screen );
        myWindow.handle_events();
        menu.show();
        vc.show();
        if(menu.startbutton.num==2){
            break;
        }
        if(ttemp==0){
            if(vc.volumebutton[vc.appear].num==2){
                vc.volume=100-vc.volume;
                Mix_Volume(-1, vc.volume);
                //Mix_Volume(0, vc.volume);
                Mix_VolumeMusic(vc.volume);
                Mix_PausedMusic();
                Mix_Pause(-1);
                ttemp+=fps.get_ticks();
                vc.appear=1-vc.appear;
            }
        }
        else{
            if(ttemp<BUTTON_DELAY){
                ttemp+=fps.get_ticks();
            }
            else{
                ttemp=0;
            }

        }

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
        //Apply the background to the screen

        while( SDL_PollEvent( &event ) )
        {
            if( event.type == SDL_KEYDOWN )
            {
                //如果“s”被按下
                if( event.key.keysym.sym == SDLK_s )
                {
                    f=0;
                    //Stop the music
                    Mix_HaltMusic();
                    //Free the startmusic
                    Mix_FreeMusic( startmusic[0] );
                }
            }
            if( event.type == SDL_QUIT ){
                    quit=true;
                    //clean_up();
                    SDL_Quit();
                    return 0;
            }
            if( event.key.keysym.sym == SDLK_m){
                vc.volume=100-vc.volume;
                Mix_Volume(-1, vc.volume);
                //Mix_Volume(0, vc.volume);
                //Mix_VolumeMusic(vc.volume);
            }
        }
        if( fps.get_ticks() < 90 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }


    //The square
    Square mySquare;

    Enemy enemy[2];
    OrthoEnemy orthoenemy[4];
    ParEnemy parenemy[4];
    RandEnemy randenemy[6];

    srand(time(NULL));
    for(int i=0;i<2;i++){
        enemy[i].x=rand()%1900;
        enemy[i].y=rand()%1420;
    }
    for(int i=0;i<4;i++){
        orthoenemy[i].x=rand()%1900;
        orthoenemy[i].y=rand()%1420;
    }
    for(int i=0;i<4;i++){
        parenemy[i].x=rand()%1900;
        parenemy[i].y=rand()%1420;
    }
    for(int i=0;i<6;i++){
        randenemy[i].x=rand()%1900;
        randenemy[i].y=rand()%1420;
    }

    Boss boss1;

    CenterEnemy centerenemy1;


    //Make the timer
    Timer myTimer;

    //Clip the sprite sheet
    set_clips();


    //Load the files
    if( load_files() == false )
    {
    return 1;
    }

    setWall();

    //Start the timer
    myTimer.start();

    int run1=0,music=rand()%4,shout=0;
    Alarm alarm;Hand hand[3];Bar bar;
    int alpha = SDL_ALPHA_TRANSPARENT;
    SDL_Color fc{255,255,255};
    ttemp=0;
    SDL_Surface *win=load_image("./picture/fadein.png"),*lose=load_image("./picture/background.png"),*temp;
    bar.t.start();
    int breaktime=0;
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
                    vc.show();
                    if( SDL_Flip( screen ) == -1 )
                    {
                        return 1;
                    }
                    setup=1;
                    if(ttemp==0){
                        if(vc.volumebutton[vc.appear].num==2){
                            vc.volume=100-vc.volume;
                            Mix_Volume(-1, vc.volume);
                            //Mix_Volume(0, vc.volume);
                            Mix_VolumeMusic(vc.volume);
                            Mix_PausedMusic();
                            Mix_Pause(-1);
                            ttemp+=fps.get_ticks();
                            vc.appear=1-vc.appear;
                        }
                    }
                    else{
                        if(ttemp<BUTTON_DELAY){
                            ttemp+=fps.get_ticks();
                        }
                        else{
                            ttemp=0;
                        }
                    }
                    vc.show();
                    if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                    {
                        SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                    }
                }
            }
        }
        if(ttemp==0){
            if(vc.volumebutton[vc.appear].num==2){
                vc.volume=100-vc.volume;
                Mix_Volume(-1, vc.volume);
                //Mix_Volume(0, vc.volume);
                Mix_VolumeMusic(vc.volume);
                Mix_PausedMusic();
                Mix_Pause(-1);
                ttemp+=fps.get_ticks();
                vc.appear=1-vc.appear;
            }
        }
        else{
            if(ttemp<BUTTON_DELAY){
                ttemp+=fps.get_ticks();
            }
            else{
                ttemp=0;
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
        if(bar.t.get_ticks()>60000){
            bar.t.pause();
            sprintf(str,"你終於醒了 . . .");
            alpha+=5;
            //Set surface alpha
            SDL_SetAlpha( win, SDL_SRCALPHA, alpha );
            seconds=TTF_RenderUTF8_Solid( font, str, textColor );
            //seconds=TTF_RenderText_Solid( font, "You lose...", fc );
            apply_surface( 260, 220, seconds, win );
            SDL_FreeSurface(seconds);
            temp = SDL_DisplayFormat(win);
            SDL_SetColorKey( temp, SDL_SRCCOLORKEY, SDL_MapRGB( temp->format, 0, 0xFF, 0xFF ) );
            SDL_FreeSurface(seconds);
            //Apply the front
            apply_surface( 0, 0, win, screen );
            //SDL_FreeSurface(temp);
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
        //apply_surface(0,0,hand.hand,screen);
        vc.show();
        SDL_Flip(screen);
        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }

    apply_surface( 0, 0, background1, screen );
    SDL_Flip(screen);
    alarm.clear();
    hand[0].clear();
    hand[1].clear();
    bar.clear();
    menu.clear();
    fps.stop();

    myTimer.stop();

    while(quit == false){
        fps.stop();
        fps.start();
        while(SDL_PollEvent(&event)){
            if(event.type==SDL_KEYDOWN && event.key.keysym.sym == SDLK_s){
                quit=true;
                myTimer.start();
            }
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                //quit = true;
                clean_up();
                //SDL_Quit();
                exit (EXIT_FAILURE);
            }
            if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
            {
                SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
            }
        }
        if(ttemp==0){
            if(vc.volumebutton[vc.appear].num==2){
                vc.volume=100-vc.volume;
                Mix_Volume(-1, vc.volume);
                //Mix_Volume(0, vc.volume);
                Mix_VolumeMusic(vc.volume);
                Mix_PausedMusic();
                Mix_Pause(-1);
                ttemp+=fps.get_ticks();
                vc.appear=1-vc.appear;
            }
        }
        else{
            if(ttemp<1000){
                ttemp+=fps.get_ticks();
            }
            else{
                ttemp=0;
            }
        }
        apply_surface( 0, 0, background1, screen );
        vc.show();
        SDL_Flip(screen);
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }
    quit=false;

    //While the user hasn't quit
    while( quit == false )
    {
        if(ttemp==0){
            if(vc.volumebutton[vc.appear].num==2){
                vc.volume=100-vc.volume;
                Mix_Volume(-1, vc.volume);
                //Mix_Volume(0, vc.volume);
                Mix_VolumeMusic(vc.volume);
                Mix_PausedMusic();
                Mix_Pause(-1);
                ttemp+=fps.get_ticks();
                vc.appear=1-vc.appear;
            }
        }
        else{
            if(ttemp<BUTTON_DELAY){
                ttemp+=fps.get_ticks();
            }
            else{
                ttemp=0;
            }

        }
        //Start the frame timer
        fps.stop();
        fps.start();

        while( ((abs(mySquare.xVel)==10)&& (myTimer.get_ticks()>run1)) ||((abs(mySquare.yVel)==10)&& (myTimer.get_ticks()>run1)) )
        {
            //Play the scratch effect
            Mix_PlayChannel( -1, run, 0 );
                //return 9;
            run1+=1850;
        }

        if(((life[0]+life[1]+life[2]+life[3]+life[4]+life[5]+life[6]+life[7]+life[8]+life[9]+life[10]+life[11]+life[12]+life[13]+life[14]+life[15]+life[16]+life[17])==1) && (shout==0) )
        {
            //Play the scratch effect
            if( Mix_PlayChannel( -1, girlshout[2], 0 ) == -1 )
                return 1;
            shout++;
        }
        else if(((life[0]+life[1]+life[2]+life[3]+life[4]+life[5]+life[6]+life[7]+life[8]+life[9]+life[10]+life[11]+life[12]+life[13]+life[14]+life[15]+life[16]+life[17])==2) && (shout==1))
        {
            //Play the scratch effect
            if( Mix_PlayChannel( -1, girlshout[0], 0 ) == -1 )
                return 1;
            shout++;
        }

        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //Handle events for the square
            mySquare.handle_input();
            //Handle events for the screen
            myWindow.handle_events();


            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //If s was pressed
                /*if( event.key.keysym.sym == SDLK_s )
                {
                    //If the timer is running
                    if( myTimer.is_started() == true )
                    {
                        //Stop the timer
                        myTimer.stop();
                    }
                    else
                    {
                        //Start the timer
                        myTimer.start();
                    }
                }*/
                //If p was pressed
                if( event.key.keysym.sym == SDLK_p )
                {
                    if( myTimer.is_paused() == false )
                    {
                        //Unpause the timer
                        myTimer.pause();
                        setup=0;
                    }
                    while(true && myTimer.is_paused() == true){
                    while(SDL_PollEvent( &event )){
                    //If the timer is paused
                        if( event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p  )
                        {
                            //Unpause the timer
                            myTimer.unpause();
                        }
                    }
                    if(setup==0){
                        apply_surface( 0, 0, background1, screen );
                        if( SDL_Flip( screen ) == -1 )
                        {
                            return 1;
                        }
                        setup=1;
                    }
                    }
                }
            }

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
                clean_up();
                SDL_QUIT;
            }
        }

        if( Mix_PlayingMusic() == 0 ){
            if( ( Mix_PlayMusic( gamemusic[music], -1 ) == -1 ))
            {
                return 1;
            }
        }

        //Move the square
        mySquare.move();

        //Set the camera
        mySquare.set_camera();

        //Show the background
        apply_surface( 0, 0, background, screen, &camera );

        //Show the square on the screen
        mySquare.show();


        //Show the wall
        for(int starti=0;starti<19;starti++){
            SDL_FillRect( background, &wall[starti], SDL_MapRGB( screen->format, 0x77, 0x77, 0x77 ) );
        }
        int temp=0;
        for(int i=0;i<2;i++)
        {
            if(abs(mySquare.box.x - enemy[i].x)<= 60 &&  ( ((mySquare.box.y >= enemy[i].y)&&(mySquare.box.y-enemy[i].y<=110))|| ((mySquare.box.y <= enemy[i].y)&&(enemy[i].y-mySquare.box.y<=80))   )   )
            {
                show[temp]=0;
                life[temp]=1;
            }
            else
            {
                show[temp]=1;
                life[temp]=0;
            }
            temp++;
        }

        for(int i=0;i<4;i++)
        {
            if(abs(mySquare.box.x - orthoenemy[i].x)<= 30 && abs(mySquare.box.y - orthoenemy[i].y)<= 30 )
            {
                show[temp]=0;
                life[temp]=1;
            }
            else
            {
                show[temp]=1;
                life[temp]=0;
            }
            temp++;
        }

        for(int i=0;i<4;i++)
        {
            if(abs(mySquare.box.x - parenemy[i].x)<= 30 && abs(mySquare.box.y - parenemy[i].y)<= 30 )
            {
                show[temp]=0;
                life[temp]=1;
            }
            else
            {
                show[temp]=1;
                life[temp]=0;
            }
            temp++;
        }



        int ey1=1,ey2=2;
        temp=0;

        for(int i=0;i<2;i++)
        {
            enemy[i].move(mySquare.box.x,mySquare.box.y,i+1);
            if(show[temp]==1)
                enemy[i].show();
            temp++;
        }

        for(int i=0;i<4;i++)
        {
            orthoenemy[i].move(mySquare.box.x,mySquare.box.y);
            if(show[temp]==1)
                orthoenemy[i].show();
            temp++;
        }

        for(int i=0;i<4;i++)
        {
            parenemy[i].move(mySquare.box.x,mySquare.box.y);
            if(show[temp]==1)
                parenemy[i].show();
            temp++;
        }

        for(int i=0;i<6;i++)
        {
            tm=myTimer.get_ticks();
            if( (myTimer.get_ticks()>20000 && i<2) || (myTimer.get_ticks()>40000 && i<6) )
            {
                randenemy[i].move(mySquare.box.x,mySquare.box.y,tm);
                if((((mySquare.box.x < randenemy[i].x) && (randenemy[i].x - mySquare.box.x) <= 40)||((mySquare.box.x > randenemy[i].x) && (mySquare.box.x - randenemy[i].x <= 35))) && (((mySquare.box.y < randenemy[i].y)&&(randenemy[i].y - mySquare.box.y <= 60))|| ((mySquare.box.y > randenemy[i].y) &&(mySquare.box.y - randenemy[i].y <= 45))))
                {
                    show[temp]=0;
                    life[temp]=1;
                }
                else
                {
                    show[temp]=1;
                    life[temp]=0;
                }
                if(show[temp]==1)
                    randenemy[i].show();
            }
            temp++;
        }


        if((((mySquare.box.x < centerenemy1.x) && (centerenemy1.x - mySquare.box.x) <= 20)||((mySquare.box.x > centerenemy1.x) && (mySquare.box.x - centerenemy1.x <= 170))) && (((mySquare.box.y < centerenemy1.y)&&(centerenemy1.y - mySquare.box.y <= 40))|| ((mySquare.box.y > centerenemy1.y) &&(mySquare.box.y - centerenemy1.y <= 160))))
        {
            show[temp]=0;
            life[temp]=3;
        }
        else
        {
            show[temp]=1;
            life[temp]=0;
        }
        if(show[temp]==1)
            centerenemy1.show();
        temp++;

        tm=myTimer.get_ticks();
        if(myTimer.get_ticks()>40000)
        {
            boss1.move(mySquare.box.x,mySquare.box.y,tm);
            if((((mySquare.box.x < boss1.x) && (boss1.x - mySquare.box.x) <= 40)||((mySquare.box.x > boss1.x) && (mySquare.box.x - boss1.x <= 200))) && (((mySquare.box.y < boss1.y)&&(boss1.y - mySquare.box.y <= 60))|| ((mySquare.box.y > boss1.y) &&(mySquare.box.y - boss1.y <= 262))))
                {
                    show[temp]=0;
                    life[temp]=3;
                }
                else
                {
                    show[temp]=1;
                    life[temp]=0;
                }
                if(show[temp]==1)
                boss1.show();
        }
        temp++;

        //The timer's time as a string
        std::stringstream time;

        //Convert the timer's time to a string
        time << "Timer: " << myTimer.get_ticks() / 1000.f;

        //Render the time surface
        seconds = TTF_RenderText_Solid( font, time.str().c_str(), textColor );

        //Apply the time surface
        apply_surface( ( SCREEN_WIDTH - /*seconds->w*/ 180 ) / 2, 0, seconds, screen );

        //Free the time surface
        SDL_FreeSurface( seconds );

        while(((life[0]+life[1]+life[2]+life[3]+life[4]+life[5]+life[6]+life[7]+life[8]+life[9]+life[10]+life[11]+life[12]+life[13]+life[14]+life[15]+life[16]+life[17])>=3) && (r==1) && quit == false)
        {
            if(shout<3)
            {
                //Play the scratch effect
                if( Mix_PlayChannel( -1, girlshout[1], 0 ) == -1 )
                {
                    return 1;
                }
                shout=shout+5;
            }

            //If there was an error in setting up the screen
            if( screen == NULL )
            {
                return 1;
            }

            //Pause the timer
            myTimer.pause();

            Mix_HaltMusic();
            if(setup){
                if(myTimer.get_ticks()>20000 && myTimer.get_ticks()<30000)
                {
                    gameover = load_image( "./picture/gameoverD.bmp" );
                }
                else if(myTimer.get_ticks()>30000 && myTimer.get_ticks()<40000 )
                {
                    gameover = load_image( "./picture/gameoverC.bmp" );
                }
                else if(myTimer.get_ticks()>40000 && myTimer.get_ticks()<50000)
                {
                    gameover = load_image( "./picture/gameoverB.bmp" );
                }
                else if(myTimer.get_ticks()>50000&&myTimer.get_ticks()<60000)
                {
                    gameover = load_image( "./picture/gameoverA.bmp" );
                }
                else if(myTimer.get_ticks()>60000&&myTimer.get_ticks()<100000)
                {
                    gameover = load_image( "./picture/gameoverS.bmp" );
                }
                else if(myTimer.get_ticks()>100000)
                {
                    gameover = load_image( "./picture/gameoverSS.bmp" );
                }
                else
                {
                    gameover = load_image( "./picture/gameoverE.png" );
                }
                setup=0;
            }
            //Apply the background to the screen
            apply_surface( 0, 0, gameover, screen );
            //Update the screen
            if( SDL_Flip( screen ) == -1 )
            {
                return 1;
            }


            Mix_HaltMusic();
            if( Mix_PlayingMusic() == 0 ){
                if(myTimer.get_ticks()>100000)
                    if( Mix_PlayMusic( overmusic[4], -1 ) == -1 ) return 1;
                else if((myTimer.get_ticks()>60000) && (myTimer.get_ticks()<100000))
                    if( Mix_PlayMusic( overmusic[2], -1 ) == -1 ) return 1;
                else if((myTimer.get_ticks()>50000) && (myTimer.get_ticks()<60000))
                    if( Mix_PlayMusic( overmusic[3], -1 ) == -1 ) return 1;
                else if((myTimer.get_ticks()>30000) && (myTimer.get_ticks()<50000))
                    if( Mix_PlayMusic( overmusic[1], -1 ) == -1 ) return 1;
                else if((myTimer.get_ticks()>20000) && (myTimer.get_ticks()<30000))
                    if( Mix_PlayMusic( overmusic[5], -1 ) == -1 ) return 1;
                else
                    if( Mix_PlayMusic( overmusic[0], -1 ) == -1 ) return 1;
            }
            om=0;

            while( SDL_PollEvent( &event ) )
            {
                myWindow.handle_events();
                if( event.type == SDL_KEYDOWN )
                {
                    //如果“r”被按下
                    if( event.key.keysym.sym == SDLK_r )
                    {
                       r=0;
                       //Stop the music
                       Mix_HaltMusic();
                    }
                    if( event.key.keysym.sym == SDLK_n ){
                        quit=true;
                        break;
                    }
                }
                if( event.type == SDL_QUIT ){
                    quit=true;
                    //clean_up();
                    SDL_QUIT;
                }
            }
        }


        if(r==0)
        {
                 SDL_FreeSurface( background );
        }
        vc.show();
        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
        if(ttemp==0){
            if(vc.volumebutton[vc.appear].num==2){
                vc.volume=100-vc.volume;
                Mix_Volume(-1, vc.volume);
                //Mix_Volume(0, vc.volume);
                Mix_VolumeMusic(vc.volume);
                Mix_PausedMusic();
                Mix_Pause(-1);
                ttemp+=fps.get_ticks();
                vc.appear=1-vc.appear;
            }
        }
        else{
            if(ttemp<BUTTON_DELAY){
                ttemp+=fps.get_ticks();
            }
            else{
                ttemp=0;
            }
        }
        vc.show();

        //Cap the frame rate
        if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }

    }
    //Free the surfaces
    SDL_FreeSurface( background1 );
    //Clean up
    clean_up();

    return 0;
}
