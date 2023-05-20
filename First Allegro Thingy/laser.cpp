#include "laser.h"
#define FIRERATE 10
#define DAMAGE 10
Laser::Laser() :Gun(FIRERATE, DAMAGE) {

}
void Laser::fire_bullet(int x, int y, Ticker tick) {
    if (fireRate < tick.getTick())//checks if it can fire
    {
        bullets[bulletsFired].moveto(x, y); // moves to the player
        bullets[bulletsFired].isMoving = true;
        al_play_sample(gunSound, 0.6, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0); //plays the gun sound
        if (bulletsFired == MAX_BULLETS - 1) { //resets the bullets fired when it its the maximum
            bulletsFired = 0;
        }
        else {
            bulletsFired++;
        }
        tick.setTick(0);
    }
}

