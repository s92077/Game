#include "core.h"

void CCore::move(SDL_Event e){
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0  ){
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
            break;
            case SDLK_DOWN:
            break;
            case SDLK_LEFT:
                v-=10;
            break;
            case SDLK_RIGHT:
                v+=10;
            break;
            default:
            break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0  ){
        switch( e.key.keysym.sym )
        {
            case SDLK_UP:
            break;
            case SDLK_DOWN:
            break;
            case SDLK_LEFT:
                v+=10;
            break;
            case SDLK_RIGHT:
                v-=10;
            break;
            default:
            break;
        }
    }
    ba.x+=v;
}
