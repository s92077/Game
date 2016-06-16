#include "class.h"
Menu::Menu(){
    bstatus=1;
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
    volumebutton[appear].show();
};
void Volume::clear(){
    volumebutton[0].clear();
    volumebutton[1].clear();
}
