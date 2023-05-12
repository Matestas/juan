#include "MachineGun.h"
MachineGun::MachineGun():Gun(1,0,1,5) {
    bulletFired = 0;
}
void MachineGun::fire_bullet(){
    al_play_sample(*getBulletSound(0), 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    
}