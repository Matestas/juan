#include "Shotgun.h"
#define FIRERATE 3
#define DAMAGE 5
#define SHOTSFIRED 3
Shotgun::Shotgun():Gun(FIRERATE, DAMAGE) {
}
void Shotgun::fire_bullet(int x, int y, Ticker tick) {
    
    if (FIRERATE < tick.getTick())
    {
        al_play_sample(gunSound, 0.3, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);   //plays the sound of the shotgun
        for (int i = 0; i < SHOTSFIRED ; i++ ) {        //shots 3 bullets in different directions
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
            if (bulletsFired == MAX_BULLETS - 1) {          //resets the bullets fired
                bulletsFired = 0;
            }
            else {
                bulletsFired++;

            }
        }
        
        tick.setTick(0);            //resets the gun tick
    }

}


