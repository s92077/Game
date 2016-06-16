#include "core.h"

void Apply_IMG(SDL_Surface* source, SDL_Surface* destination, int width, int height, int x, int y){
	SDL_Rect offset;
	offset.h=height;
	offset.w=width;
	offset.x=x;
	offset.y=y;
	SDL_BlitSurface( source, NULL, destination, &offset );
}

