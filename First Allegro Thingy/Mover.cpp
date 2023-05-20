#include "Mover.h"
#define MIN_RANGE 45
#define MAX_RANGE 135

Mover::Mover() : dx(dx), dy(dy) {

}
void Mover::toMove(Enemy& enemy, Ticker tick)
{
    //std::cout << enemy.moveType << std::endl;
    if (enemy.moveType == 1){
        randomMover(enemy, tick);
    }
    else if (enemy.moveType == 2) {
        
        linearMover(enemy, tick);
    }
    else if (enemy.moveType == 3) {

        linearMover(enemy, tick);
    }
}
void Mover::randomMover(Enemy& enemy,Ticker tick)  // Need to change to BaseEntity as argument, still dont know, if I dont figure it out I will just copy for each class
{
 

    
        if (tick.getTick() % TICK_INTERVAL_16 == 0) {
            float degrees = (MIN_RANGE + rand() % (MAX_RANGE - MIN_RANGE + 1));       // give a random angle in degrees between the angles given
            float radians = degrees * DEGREE_TO_PI_RATIO;  // since math.h uses radians, convert the random angle to radians
            
            enemy.dy = (cos(radians));
            enemy.dx = (-1 * (sqrt(1 - pow(enemy.dy, 2))));
            //cout << enemy.dy << endl;
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

void Mover::linearMover(Enemy& enemy, Ticker tick) {
    if (tick.getTick() % TICK_INTERVAL_64 == 0) {
        if (enemy.moveType == 3) {
            enemy.dy = 0;
            enemy.dx = -1.2;
            
        }
        else {
            enemy.dy *= -1;
        }
    }
}