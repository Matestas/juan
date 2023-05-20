#include "MachineGun.h"
#include<iostream>
#include "Ticker.h"
using namespace std;
#define FIRERATE 1
#define DAMAGE 5
MachineGun::MachineGun():Gun(FIRERATE,DAMAGE) {
}
void MachineGun::fire_bullet(int x,int y,Ticker tick){
    al_play_sample(gunSound, 1.5, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0); //plays the gun noise
    if (FIRERATE < tick.getTick()) //checks if it can fire again
    {       
        bullets[bulletsFired].moveto(x, y); //moves the bullets to the player
        bullets[bulletsFired].isMoving = true;
        if (bulletsFired == MAX_BULLETS-1) { //resets the bullets fired when it its the maximum
            bulletsFired = 0;
        }
        else {
            bulletsFired++;
        }
        tick.setTick(0);  //resets the gun tick
    }
    
}