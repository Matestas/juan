#include "Shotgun.h"

Shotgun::Shotgun() {

}
void Shotgun::fire_bullet() {
    al_play_sample(*getBulletSound(0), 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);

}