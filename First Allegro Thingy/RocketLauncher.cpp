#include "RocketLauncher.h"
#include "Ticker.h"
#define FIRERATE 5
#define DAMAGE 20
RocketLauncher::RocketLauncher():Gun(FIRERATE, DAMAGE){

}
void RocketLauncher::fire_bullet(int x, int y,Ticker tick) {        //not yet finished
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
    }
}