#include "Mover.h"
#define MIN_RANGE 45
#define MAX_RANGE 135

Mover::Mover() : dx(dx), dy(dy) {
                                //Constructor
}
void Mover::toMove(Enemy& enemy, Ticker tick)
{
    if (enemy.moveType == 1){               //checks the Movement type and moves the enemy acording to it
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
            enemy.dx = (-1 * (sqrt(1 - pow(enemy.dy, 2)))); //sets the directions of the movement
        }   
}

void Mover::linearMover(Enemy& enemy, Ticker tick) {
    if (tick.getTick() % TICK_INTERVAL_64 == 0) {
        if (enemy.moveType == 3) {      //sets the direction speed of the movement
            enemy.dy = 0;
            enemy.dx = -1.2;
            
        }
        else {
            enemy.dy *= -1;
        }
    }
}