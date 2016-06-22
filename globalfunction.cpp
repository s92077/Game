#include "global.h"
SDL_Surface *load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    /*if( loadedImage != NULL )
    {
    //Create an optimized surface
    optimizedImage = SDL_DisplayFormat( loadedImage );

    //Free the old surface
    SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
        //Color key surface
        SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }
    //optimizedImage = loadedImage;
    //Return the optimized surface
    return optimizedImage;*/
    return loadedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip )
{
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
    SDL_Rect* clip=NULL;
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

void set_clips()
{
    //Clip the sprites
    for(int i=0; i<4; i++){
        clipsDown[ i ].x = SQUARE_WIDTH * i;
        clipsDown[ i ].y = 0;
        clipsDown[ i ].w = SQUARE_WIDTH;
        clipsDown[ i ].h = SQUARE_HEIGHT;

        clipsLeft[ i ].x = SQUARE_WIDTH * i;
        clipsLeft[ i ].y = SQUARE_HEIGHT;
        clipsLeft[ i ].w = SQUARE_WIDTH;
        clipsLeft[ i ].h = SQUARE_HEIGHT;

        clipsRight[ i ].x = SQUARE_WIDTH * i;
        clipsRight[ i ].y = SQUARE_HEIGHT * 2;
        clipsRight[ i ].w = SQUARE_WIDTH;
        clipsRight[ i ].h = SQUARE_HEIGHT;

        clipsUp[ i ].x = SQUARE_WIDTH * i;
        clipsUp[ i ].y = SQUARE_HEIGHT * 3;
        clipsUp[ i ].w = SQUARE_WIDTH;
        clipsUp[ i ].h = SQUARE_HEIGHT;

        clipsDownLeft[ i ].x = SQUARE_WIDTH * i;
        clipsDownLeft[ i ].y = SQUARE_HEIGHT * 4;
        clipsDownLeft[ i ].w = SQUARE_WIDTH;
        clipsDownLeft[ i ].h = SQUARE_HEIGHT;

        clipsDownRight[ i ].x = SQUARE_WIDTH * i;
        clipsDownRight[ i ].y = SQUARE_HEIGHT * 5;
        clipsDownRight[ i ].w = SQUARE_WIDTH;
        clipsDownRight[ i ].h = SQUARE_HEIGHT;

        clipsUpLeft[ i ].x = SQUARE_WIDTH * i;
        clipsUpLeft[ i ].y = SQUARE_HEIGHT * 6;
        clipsUpLeft[ i ].w = SQUARE_WIDTH;
        clipsUpLeft[ i ].h = SQUARE_HEIGHT;

        clipsUpRight[ i ].x = SQUARE_WIDTH * i;
        clipsUpRight[ i ].y = SQUARE_HEIGHT * 7;
        clipsUpRight[ i ].w = SQUARE_WIDTH;
        clipsUpRight[ i ].h = SQUARE_HEIGHT;

        enemyDown[ i ].x = ENEMY_WIDTH * i;
        enemyDown[ i ].y = 0;
        enemyDown[ i ].w = ENEMY_WIDTH;
        enemyDown[ i ].h = ENEMY_HEIGHT;


        enemyLeft[ i ].x = ENEMY_WIDTH * i;
        enemyLeft[ i ].y = ENEMY_HEIGHT;
        enemyLeft[ i ].w = ENEMY_WIDTH;
        enemyLeft[ i ].h = ENEMY_HEIGHT;

        enemyRight[ i ].x = ENEMY_WIDTH * i;
        enemyRight[ i ].y = ENEMY_HEIGHT * 2;
        enemyRight[ i ].w = ENEMY_WIDTH;
        enemyRight[ i ].h = ENEMY_HEIGHT;

        enemyUp[ i ].x = ENEMY_WIDTH * i;
        enemyUp[ i ].y = ENEMY_HEIGHT * 3;
        enemyUp[ i ].w = ENEMY_WIDTH;
        enemyUp[ i ].h = ENEMY_HEIGHT;

        enemyDownLeft[ i ].x = ENEMY_WIDTH * i;
        enemyDownLeft[ i ].y = ENEMY_HEIGHT * 4;
        enemyDownLeft[ i ].w = ENEMY_WIDTH;
        enemyDownLeft[ i ].h = ENEMY_HEIGHT;

        enemyDownRight[ i ].x = ENEMY_WIDTH * i;
        enemyDownRight[ i ].y = ENEMY_HEIGHT * 5;
        enemyDownRight[ i ].w = ENEMY_WIDTH;
        enemyDownRight[ i ].h = ENEMY_HEIGHT;

        enemyUpLeft[ i ].x = ENEMY_WIDTH * i;
        enemyUpLeft[ i ].y = ENEMY_HEIGHT * 6;
        enemyUpLeft[ i ].w = ENEMY_WIDTH;
        enemyUpLeft[ i ].h = ENEMY_HEIGHT;

        enemyUpRight[ i ].x = ENEMY_WIDTH * i;
        enemyUpRight[ i ].y = ENEMY_HEIGHT * 7;
        enemyUpRight[ i ].w = ENEMY_WIDTH;
        enemyUpRight[ i ].h = ENEMY_HEIGHT;

        orthoenemyDown[ i ].x = ORTHOENEMY_WIDTH * i;
        orthoenemyDown[ i ].y = 0;
        orthoenemyDown[ i ].w = ORTHOENEMY_WIDTH;
        orthoenemyDown[ i ].h = ORTHOENEMY_HEIGHT;

        parenemyRight[ i ].x = PARENEMY_WIDTH * i;
        parenemyRight[ i ].y = PARENEMY_HEIGHT * 2;
        parenemyRight[ i ].w = PARENEMY_WIDTH;
        parenemyRight[ i ].h = PARENEMY_HEIGHT;

        centerenemyDown[ i ].x = CENTERENEMY_WIDTH * i;
        centerenemyDown[ i ].y = 0;
        centerenemyDown[ i ].w = CENTERENEMY_WIDTH;
        centerenemyDown[ i ].h = CENTERENEMY_HEIGHT;
    }


    randenemyDown[ 0 ].x = 0;
    randenemyDown[ 0 ].y = 0;
    randenemyDown[ 0 ].w = RANDENEMY_WIDTH;
    randenemyDown[ 0 ].h = RANDENEMY_HEIGHT;

    randenemyDown[ 1 ].x = RANDENEMY_WIDTH;
    randenemyDown[ 1 ].y = 0;
    randenemyDown[ 1 ].w = RANDENEMY_WIDTH;
    randenemyDown[ 1 ].h = RANDENEMY_HEIGHT;


    bossDown[ 0 ].x = 0;
    bossDown[ 0 ].y = 0;
    bossDown[ 0 ].w = BOSS_WIDTH;
    bossDown[ 0 ].h = BOSS_HEIGHT;

    bossDown[ 1 ].x = BOSS_WIDTH;
    bossDown[ 1 ].y = 0;
    bossDown[ 1 ].w = BOSS_WIDTH;
    bossDown[ 1 ].h = BOSS_HEIGHT;

}

bool check_collision( SDL_Rect A, SDL_Rect B )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
    return false;
    }

    if( topA >= bottomB )
    {
    return false;
    }

    if( rightA <= leftB )
    {
    return false;
    }

    if( leftA >= rightB )
    {
    return false;
    }

    //If none of the sides from A are outside B
    return true;
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
        return false;

    //Set up the screen
    //screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    //if( screen == NULL )
     //   return false;

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
        return false;

    //Initialize SDL_mixer

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
        return false;

    //Set the window caption
    SDL_WM_SetCaption( "Run & Die!", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the square image
    square = load_image( "./picture/irene_run.bmp" );

    //Load the background
    background = load_image( "./picture/background.bmp" );

    //Load the enemy
    enemy = load_image("./picture/enemy.bmp");

    orthoenemy = load_image("./picture/small_animal_01.bmp");

    parenemy = load_image("./picture/small_animal_01.bmp");

    randenemy = load_image("./picture/fire.bmp");

    boss = load_image("./picture/boss.bmp");

    centerenemy = load_image("./picture/centerenemy.bmp");

    //Open the font
    font = TTF_OpenFont( "msjh.ttf", 24 );

    //If there was a problem in loading the square
    if( square == NULL )
    {
        return false;
    }

    //If there was a problem in loading the background
    if( background == NULL )
    {
        return false;
    }

    //If there was a problem in loading the enemy
    if( enemy == NULL )
    {
        return false;
    }

    if( orthoenemy == NULL )
    {
        return false;
    }

    if( parenemy == NULL )
    {
        return false;
    }

    if( randenemy == NULL)
    {
        return false;
    }

    if( boss == NULL)
    {
        return false;
    }

    if(centerenemy == NULL)
    {
        return false;
    }

    //If there was an error in loading the font
    if( font == NULL )
    {
        return false;
    }

    //Load the gamemusic
    char str[30];
    for(int i=0;i<4;i++){
        sprintf(str,"./music/game sound%d.wav",i);
        gamemusic[i] = Mix_LoadMUS( str );
    }

    //If there was a problem loading the startmusic
    if( gamemusic == NULL )
    {
        return false;
    }

    //Load the overmusic
    for(int i=0;i<6;i++){
        sprintf(str,"./music/overmusic%d.wav",i);
        overmusic[i] = Mix_LoadMUS( str );
    }

    //If there was a problem loading the startmusic
    if( overmusic == NULL )
    {
        return false;
    }


     //Load the sound effects
    run = Mix_LoadWAV( "./music/run.wav" );

    //If there was a problem loading the startmusic
    if( run == NULL )
    {
        return false;
    }

    //Load the sound effects
    for(int i=0;i<3;i++){
        sprintf(str,"./music/girl shout%d.wav",i);
        girlshout[i] = Mix_LoadWAV( str );
    }
    ding = Mix_LoadWAV("./music/Windows Ding.wav");

    //If there was a problem loading the startmusic
    if( girlshout == NULL )
    {
        return false;
    }

    //If everything loaded fine
    return true;
}

void clean_up()
{
    //Free the surfaces
    if( enemy != NULL)
	{
		SDL_FreeSurface( enemy );
	}
    if( orthoenemy != NULL)
	{
		SDL_FreeSurface( orthoenemy );
	}
    if( parenemy != NULL)
	{
		SDL_FreeSurface( parenemy );
	}
    if( randenemy != NULL)
	{
		SDL_FreeSurface( randenemy );
	}
    if( boss != NULL)
	{
		SDL_FreeSurface( boss );
	}
    if( centerenemy != NULL)
	{
		SDL_FreeSurface( centerenemy );
	}
    if( square != NULL)
	{
		SDL_FreeSurface( square );
	}
    if( background != NULL)
	{
		SDL_FreeSurface( background );
	}
    if( startStop != NULL)
	{
		SDL_FreeSurface( startStop );
	}
    if( pauseMessage != NULL)
	{
		SDL_FreeSurface( pauseMessage );
	}

    //Free the gamemusic
    for(int i=0;i<6;i++){
        if(gamemusic[i]!=NULL)
            Mix_FreeMusic( gamemusic[i] );
    }

    //Free the gamemusic
    for(int i=0;i<6;i++){
        if(overmusic[i]!=NULL)
            Mix_FreeMusic( overmusic[i] );
    }

    //Free the sound effects
    if(run!=NULL)
        Mix_FreeChunk( run );

    //Free the sound effects
    for(int i=0;i<3;i++){
        if(girlshout[i]!=NULL)
        Mix_FreeChunk( girlshout[i] );
    }


    //Quit SDL_mixer
    Mix_CloseAudio();

    //Close the font
    TTF_CloseFont( font );

    //Quit SDL_ttf
    TTF_Quit();

    //Quit SDL
    SDL_Quit();
}
void setWall()
{
    //Set the wall
    wall[0].x = 150;
    wall[0].y = 500;
    wall[0].w = 80;
    wall[0].h = 80;

    wall[1].x = 230;
    wall[1].y = 260;
    wall[1].w = 80;
    wall[1].h = 320;

    wall[2].x = 310;
    wall[2].y = 260;
    wall[2].w = 80;
    wall[2].h = 80;

    wall[3].x = 210;
    wall[3].y = 800;
    wall[3].w = 80;
    wall[3].h = 320;

    wall[4].x = 290;
    wall[4].y = 1040;
    wall[4].w = 330;
    wall[4].h = 80;

    wall[5].x = 450;
    wall[5].y = 880;
    wall[5].w = 130;
    wall[5].h = 80;

    wall[6].x = 500;
    wall[6].y = 640;
    wall[6].w = 80;
    wall[6].h = 160;

    wall[7].x = 380;
    wall[7].y = 720;
    wall[7].w = 360;
    wall[7].h = 80;

    wall[8].x = 660;
    wall[8].y = 800;
    wall[8].w = 80;
    wall[8].h = 320;

    wall[9].x = 740;
    wall[9].y = 1040;
    wall[9].w = 100;
    wall[9].h = 80;

    wall[10].x = 650;
    wall[10].y = 300;
    wall[10].w = 80;
    wall[10].h = 240;

    wall[11].x = 840;
    wall[11].y = 0;
    wall[11].w = 80;
    wall[11].h = 320;

    wall[12].x = 1170;
    wall[12].y = 440;
    wall[12].w = 300;
    wall[12].h = 80;//*//

    wall[13].x = 800;
    wall[13].y = 810;
    wall[13].w = 240;
    wall[13].h = 80;

    wall[14].x = 1040;
    wall[14].y = 650;
    wall[14].w = 80;
    wall[14].h = 240;

    wall[15].x = 930;
    wall[15].y = 960;
    wall[15].w = 160;
    wall[15].h = 300;

    wall[16].x = 1600;
    wall[16].y = 840;
    wall[16].w = 80;
    wall[16].h = 400;

    wall[17].x = 1500;
    wall[17].y = 200;
    wall[17].w = 160;
    wall[17].h = 80;

    wall[18].x = 1660;
    wall[18].y = 280;
    wall[18].w = 80;
    wall[18].h = 400;
}

