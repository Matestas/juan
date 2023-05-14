#include "Mover.h"
#include"Enemy.h"

Mover::Mover() {

}

int Mover::randomMover(Ticker tick)  // Need to change to BaseEntity as argument, still dont know, if I dont figure it out I will just copy for each class
{

    if (tick.getTick() % TICK_INTERVAL_64 == 0) {
        return ((rand() % 7) - 3);
    }
    else {
        return 0;
    }

    // Need of a route changer if hits with another hitbox

    //std::cout << enemy.getdx() << "," << enemy.getdy() << std::endl;
    //std::cout <<"bottom: ("<< enemy.hitbox.getBottomRightX() << "," << enemy.hitbox.getBottomRightY() << " Top: (" << enemy.hitbox.getTopLeftX() << ", " << enemy.hitbox.getTopLeftY() << ") " << std::endl;
}