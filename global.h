#pragma once
#ifndef GLOBALVAR_H
#define GLOBALVAR_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <iostream>
using namespace std;

//Screen attributes
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 32
//The frame rate
#define FRAMES_PER_SECOND 25
//The dimensions of the level
#define LEVEL_WIDTH 1920
#define LEVEL_HEIGHT 1440
//The attributes of the square
#define SQUARE_WIDTH 40
#define SQUARE_HEIGHT 60
//The attributes of the enemy1,2
#define ENEMY_WIDTH 80
#define ENEMY_HEIGHT 110
//The attributes of the parenemy
#define PARENEMY_WIDTH 40
#define PARENEMY_HEIGHT 40
//The attributes of the orthoenemy
#define ORTHOENEMY_WIDTH 40
#define ORTHOENEMY_HEIGHT 40
//The attributes of the randenemy
#define RANDENEMY_WIDTH 35
#define RANDENEMY_HEIGHT 45
//The attributes of the centerenemy
#define CENTERENEMY_WIDTH 190
#define CENTERENEMY_HEIGHT 180
//The attributes of the centerenemy
#define BOSS_WIDTH 200
#define BOSS_HEIGHT 262
//The direction status of the stick figure
#define SQUARE_Down 0
#define SQUARE_Left 1
#define SQUARE_Right 2
#define SQUARE_Up 3
#define SQUARE_DownLeft 4
#define SQUARE_DownRight 5
#define SQUARE_UpLeft 6
#define SQUARE_UpRight 7

#define ENEMY_Down 0
#define ENEMY_Left 1
#define ENEMY_Right 2
#define ENEMY_Up 3
#define ENEMY_DownLeft 4
#define ENEMY_DownRight 5
#define ENEMY_UpLeft 6
#define ENEMY_UpRight 7

#define PARENEMY_Right 0

#define ORTHOENEMY_Down 0

#define RANDENEMY_Down 0

#define CENTERENEMY_Down 0

#define BOSS_Down 0

//The surfaces
extern SDL_Surface *square;
extern SDL_Surface *background;
extern SDL_Surface *background1;
extern SDL_Surface *screen;
extern SDL_Surface *enemy;
extern SDL_Surface *orthoenemy;
extern SDL_Surface *parenemy;
extern SDL_Surface *randenemy;
extern SDL_Surface *centerenemy;
extern SDL_Surface *boss;
extern SDL_Surface *startStop;
extern SDL_Surface *pauseMessage;
extern SDL_Surface *seconds;
extern SDL_Surface *gameover;

//The event structure
extern SDL_Event event;

//The font
extern TTF_Font *font;

//The color of the font
extern SDL_Color textColor;

//the wall
extern SDL_Rect wall[19];

//The camera
extern SDL_Rect camera;


//The areas of the sprite sheet
extern SDL_Rect clipsRight[ 4 ];
extern SDL_Rect clipsLeft[ 4 ];
extern SDL_Rect clipsUp[ 4 ];
extern SDL_Rect clipsDown[ 4 ];
extern SDL_Rect clipsUpRight[ 4 ];
extern SDL_Rect clipsUpLeft[ 4 ];
extern SDL_Rect clipsDownRight[ 4 ];
extern SDL_Rect clipsDownLeft[ 4 ];

extern SDL_Rect enemyRight[ 4 ];
extern SDL_Rect enemyLeft[ 4 ];
extern SDL_Rect enemyUp[ 4 ];
extern SDL_Rect enemyDown[ 4 ];
extern SDL_Rect enemyUpRight[ 4 ];
extern SDL_Rect enemyUpLeft[ 4 ];
extern SDL_Rect enemyDownRight[ 4 ];
extern SDL_Rect enemyDownLeft[ 4 ];

extern SDL_Rect parenemyRight[ 4 ];
extern SDL_Rect orthoenemyDown[ 4 ];
extern SDL_Rect randenemyDown[ 2 ];
extern SDL_Rect centerenemyDown[ 4 ];
extern SDL_Rect bossDown[ 2 ];



//The startmusic that will be played
extern Mix_Music *startmusic[ 2 ];

//The gamemusic that will be played
extern Mix_Music *gamemusic[ 4 ];

//The overmusic that will be played
extern Mix_Music *overmusic[ 6 ];


//The sound effects that will be used
extern Mix_Chunk *run;
extern Mix_Chunk *ding;

//The sound effects that will be used
extern Mix_Chunk *girlshout[ 3 ];

SDL_Surface *load_image( std::string );
void set_clips();
bool check_collision( SDL_Rect, SDL_Rect );
bool init();
bool load_files();
void clean_up();
void apply_surface( int , int , SDL_Surface* , SDL_Surface* , SDL_Rect*);
void apply_surface( int , int , SDL_Surface* , SDL_Surface*);
void setWall();
#endif // CORE_H
