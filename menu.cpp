#include "class.h"
#include "framework.h"
Menu::Menu(){
}

void Menu::show(){
    //apply_surface(0,0,menuback,screen);
    startbutton.handle_events();
    startbutton.show();
}
void Menu::clear(){
    startbutton.clear();
}
Volume::Volume(){
    appear=1;
    volume=100;
    volumebutton[0].init(640-43,0,43,43,"./picture/mute.png");
    volumebutton[1].init(640-43,0,43,43,"./picture/volume.png");
}
void Volume::show(){
    volumebutton[appear].handle_events();
    if(pressedTime==0){
        if(volumebutton[appear].num==2){
            volume=100-volume;
            Mix_Volume(-1, volume);
            //Mix_Volume(0, vc.volume);
            Mix_VolumeMusic(volume);
            Mix_PausedMusic();
            Mix_Pause(-1);
            pressedTime+=fps.get_ticks();
            appear=1-appear;
        }
    }
    else{
        if(pressedTime<200){
            pressedTime+=fps.get_ticks();
        }
        else{
            pressedTime=0;
        }
    }
    volumebutton[appear].show();
};
void Volume::clear(){
    volumebutton[0].clear();
    volumebutton[1].clear();
}
