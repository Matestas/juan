#include "Shotgun.h"
#define FIRERATE 5
#define DAMAGE 7
#define SHOTSFIRED 3
Shotgun::Shotgun():Gun(FIRERATE, DAMAGE) {
}
void Shotgun::fire_bullet(int x, int y, int tick) {
    //al_play_sample(*getBulletSound(0), 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    if (tickToFire < tick)
    {
        for (int i = 0; i < SHOTSFIRED ; i++ ) {
            if (i == 0) {
                bullets[bulletsFired].setspeedX(1);
                bullets[bulletsFired].setspeedY(1);
            }
            if (i == 1) {
                bullets[bulletsFired].setspeedX(1);
                bullets[bulletsFired].setspeedY(0);
            }
            if (i == 2) {
                bullets[bulletsFired].setspeedX(1);
                bullets[bulletsFired].setspeedY(-1);
            }
            bullets[bulletsFired].moveto(x, y);
            bullets[bulletsFired].isMoving = true;
            if (bulletsFired == MAX_BULLETS - 1) {
                bulletsFired = 0;
            }
            else {
                bulletsFired++;
            }
            tickFired = tick;
            nextTick();
       }
    }

}