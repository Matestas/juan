#include "RocketLauncher.h"
RocketLauncher::RocketLauncher():Gun(50,0,50,1){

}
void RocketLauncher::fire_bullet() {
    al_play_sample(*getBulletSound(0), 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);

}