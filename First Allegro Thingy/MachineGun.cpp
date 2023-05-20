#include "MachineGun.h"
#include<iostream>
#include "Ticker.h"
using namespace std;
#define FIRERATE 1
#define DAMAGE 5
MachineGun::MachineGun():Gun(FIRERATE,DAMAGE) {
}
void MachineGun::fire_bullet(int x,int y,Ticker tick){
    al_play_sample(gunSound, 1.5, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    if (FIRERATE < tick.getTick())
    {       
        bullets[bulletsFired].moveto(x, y);
        bullets[bulletsFired].isMoving = true;
        if (bulletsFired == MAX_BULLETS-1) {
            bulletsFired = 0;
        }
        else {
            bulletsFired++;
        }
        tick.setTick(0);
        //std::cout << bulletsFired << std::endl;
    }
    
}