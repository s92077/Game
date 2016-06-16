#include "global.h"

//The surfaces
SDL_Surface *square = NULL;
SDL_Surface *background = NULL;
SDL_Surface *background1 = NULL;
SDL_Surface *screen = NULL;
SDL_Surface *enemy = NULL;
SDL_Surface *orthoenemy = NULL;
SDL_Surface *parenemy = NULL;
SDL_Surface *randenemy = NULL;
SDL_Surface *centerenemy = NULL;
SDL_Surface *boss = NULL;
SDL_Surface *startStop = NULL;
SDL_Surface *pauseMessage = NULL;
SDL_Surface *seconds = NULL;
SDL_Surface *gameover = NULL;

//The event structure
SDL_Event event;

//The font
TTF_Font *font = NULL;

//The color of the font
SDL_Color textColor = { 0, 0, 0 };

//the wall
SDL_Rect wall[19];

//The camera
SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };


//The areas of the sprite sheet
SDL_Rect clipsRight[ 4 ];
SDL_Rect clipsLeft[ 4 ];
SDL_Rect clipsUp[ 4 ];
SDL_Rect clipsDown[ 4 ];
SDL_Rect clipsUpRight[ 4 ];
SDL_Rect clipsUpLeft[ 4 ];
SDL_Rect clipsDownRight[ 4 ];
SDL_Rect clipsDownLeft[ 4 ];

SDL_Rect enemyRight[ 4 ];
SDL_Rect enemyLeft[ 4 ];
SDL_Rect enemyUp[ 4 ];
SDL_Rect enemyDown[ 4 ];
SDL_Rect enemyUpRight[ 4 ];
SDL_Rect enemyUpLeft[ 4 ];
SDL_Rect enemyDownRight[ 4 ];
SDL_Rect enemyDownLeft[ 4 ];

SDL_Rect parenemyRight[ 4 ];
SDL_Rect orthoenemyDown[ 4 ];
SDL_Rect randenemyDown[ 2 ];
SDL_Rect centerenemyDown[ 4 ];
SDL_Rect bossDown[ 2 ];


//The startmusic that will be played
Mix_Music *startmusic[ 2 ];

//The gamemusic that will be played
Mix_Music *gamemusic[ 4 ];

//The overmusic that will be played
Mix_Music *overmusic[ 6 ];


//The sound effects that will be used
Mix_Chunk *run;

//The sound effects that will be used
Mix_Chunk *girlshout[ 3 ];
Mix_Chunk *ding;
