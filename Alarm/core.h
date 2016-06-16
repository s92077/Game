#pragma once

#ifndef CORE_H
#define CORE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


class Timer
{
private:
    //The clock time when the timer started
    int startTicks;
    //The ticks stored when the timer was paused
    int pausedTicks;
    //The timer status
    bool paused;
    bool started;
public:
    //Initializes variables
    Timer();
    //The various clock actions
    void start();
    void stop();
    void pause();
    void unpause();

    int get_ticks();
    //Checks the status of the timer
    bool is_started();
    bool is_paused();
};
class LTexture
{
	public:
	    LTexture();
		LTexture( std::string path );
		~LTexture();
		bool loadFromFile( std::string path );
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
		void free();
		void setColor( Uint8 red, Uint8 green, Uint8 blue );
		void setBlendMode( SDL_BlendMode blending );
		void setAlpha( Uint8 alpha );
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
		int getWidth();
		int getHeight();
		SDL_Rect mRect;
	private:
		SDL_Texture* mTexture;
		int mWidth;
		int mHeight;
};
class LTimer
{
    public:
		LTimer();
		void start();
		void stop();
		void pause();
		void unpause();
		Uint32 getTicks();
		bool isStarted();
		bool isPaused();
    private:
		Uint32 mStartTicks;
		Uint32 mPausedTicks;
		bool mPaused;
		bool mStarted;
};
class Dot
{
    public:
		static const int DOT_WIDTH = 60;
		static const int DOT_HEIGHT = 60;
		static const int DOT_VEL = 10;
		Dot(int x,int y,SDL_Rect &box);
		void handleEvent( SDL_Event& e );
		void move(SDL_Rect &box);
		void render(LTexture &gDotTexture);
    private:
		int mVelX, mVelY;
		int mr=1;
};
class Hand
{
    public:
		static const int DOT_WIDTH = 60;
		static const int DOT_HEIGHT = 60;
		static const int DOT_VEL = 10;
		Hand(int x,int y,SDL_Rect &box);
		void handleEvent( SDL_Event& e );
		void automove(SDL_Rect &box,SDL_Rect &box1);
		void render(LTexture &gDotTexture);
    private:
		int mVelX, mVelY;
		int mr=1;
		int md=1;
		Timer timer;
		int time;
};
bool checkCollision( SDL_Rect a, SDL_Rect b );
//void Apply_IMG(SDL_Surface* source, SDL_Surface* destination, int width, int height, int x, int y);
#endif
