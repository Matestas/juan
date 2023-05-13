#include "laser.h"
#define FIRERATE 10
#define DAMAGE 10
Laser::Laser() :Gun(FIRERATE, DAMAGE) {

}
void Laser::fire_bullet(int x, int y, Ticker tick) {
    //al_play_sample(*getBulletSound(0), 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
    if (fireRate < tick.getTick())
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
        std::cout << bulletsFired << std::endl;
    }
}