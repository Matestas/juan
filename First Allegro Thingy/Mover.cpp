#include "Mover.h"
#include"Enemy.h"
#define MIN_RANGE 55
#define MAX_RANGE 125
Mover::Mover() {

}

void Mover::randomMover(Ticker tick)  // Need to change to BaseEntity as argument, still dont know, if I dont figure it out I will just copy for each class
{
 

    
        if (tick.getTick() % TICK_INTERVAL_16 == 0) {
            float degrees = (MIN_RANGE + rand() % (MAX_RANGE - MIN_RANGE));       // give a random angle in degrees between the angles given
            float radians = degrees * DEGREE_TO_PI_RATIO;  // since math.h uses radians, convert the random angle to radians
            dy = (cos(radians));
            dx = (-1 * (sqrt(1 - pow(dy, 2))));
        }
    //if (tick.getTick() % TICK_INTERVAL_64 == 0) {
       // return ((rand() % 7) - 3);
   // }
   // else {
     //   return 0;
   // }

    // Need of a route changer if hits with another hitbox

    //std::cout << enemy.getdx() << "," << enemy.getdy() << std::endl;
    //std::cout <<"bottom: ("<< enemy.hitbox.getBottomRightX() << "," << enemy.hitbox.getBottomRightY() << " Top: (" << enemy.hitbox.getTopLeftX() << ", " << enemy.hitbox.getTopLeftY() << ") " << std::endl;
}