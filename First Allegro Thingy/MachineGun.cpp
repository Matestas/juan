#include "MachineGun.h"
#include<iostream>
using namespace std;
#define FIRERATE 1
#define DAMAGE 5
MachineGun::MachineGun():Gun(FIRERATE,DAMAGE) {
}
void MachineGun::fire_bullet(int x,int y,int tick){
    //al_play_sample(*getBulletSound(0), 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    if (tickToFire < tick)
    {       
        bullets[bulletsFired].moveto(x, y);
        bullets[bulletsFired].isMoving = true;
        if (bulletsFired == MAX_BULLETS-1) {
            bulletsFired = 0;
        }
        else {
            bulletsFired++;
        }
        tickFired = tick;
        nextTick();
    }
    
}