#include "Shotgun.h"
#define FIRERATE 5
#define DAMAGE 7
#define SHOTSFIRED 3
Shotgun::Shotgun():Gun(FIRERATE, DAMAGE) {
}
void Shotgun::fire_bullet(int x, int y, Ticker tick) {
    //al_play_sample(*getBulletSound(0), 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    if (FIRERATE < tick.getTick())
    {
        for (int i = 0; i < SHOTSFIRED ; i++ ) {
            bullets[bulletsFired].moveto(x, y);
            bullets[bulletsFired].isMoving = true;
            if (i == 0) {
                bullets[bulletsFired].setspeed(10,4);
            }
            if (i == 1) {
                bullets[bulletsFired].setspeed(10,0);
            }
            if (i == 2) {
                bullets[bulletsFired].setspeed(10,-4);
            }
            if (bulletsFired == MAX_BULLETS - 1) {
                bulletsFired = 0;
            }
            else {
                bulletsFired++;

            }
        }
        
        tick.setTick(0);
        std::cout << bulletsFired << std::endl;
    }

}