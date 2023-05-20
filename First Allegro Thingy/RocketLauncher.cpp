#include "RocketLauncher.h"
#include "Ticker.h"
#define FIRERATE 5
#define DAMAGE 20
RocketLauncher::RocketLauncher():Gun(FIRERATE, DAMAGE){

}
void RocketLauncher::fire_bullet(int x, int y,Ticker tick) {
    //al_play_sample(*getBulletSound(0), 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    if (FIRERATE < tick.getTick())
    {
        bullets[bulletsFired].moveto(x, y);
        bullets[bulletsFired].isMoving = true;
        if (bulletsFired == MAX_BULLETS - 1) {
            bulletsFired = 0;
        }
        else {
            bulletsFired++;
        }
        tick.setTick(0);
        //std::cout << bulletsFired << std::endl;
    }
}