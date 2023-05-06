#include "Mover.h"
#include "Map.h"
#include "Collision.h"
#include <math.h>
#define DEGREE_TO_PI_RATIO 0.0174532925
#define PI 3.14159265359
#define PI_OVER_TWO 3.14159265359/2
#define TICK_INTERVAL_16 16
#define TICK_INTERVAL_32 32
#define TICK_INTERVAL_64 64
#define TICK_INTERVAL_128 128

Mover::Mover(int tick) {
	this->tick = tick;
}

void Mover::ticker()
{
	if (tick <= 128) {
		tick += 1;
	}
	else tick = 0;
}

int Mover::getTick()
{
	return tick;
}

void Mover::randomMover(Enemy& enemy,int dirX, int angleMinRange, int angleMaxRange)  // Need to change to BaseEntity as argument, still dont know, if I dont figure it out I will just copy for each class
{
	
	enemy.move(enemy.getdx(), enemy.getdy());

	if (tick % TICK_INTERVAL_16 == 0 ){
		float degrees = (angleMinRange + rand() % (angleMaxRange-angleMinRange));       // give a random angle in degrees between the angles given
		float radians = degrees * DEGREE_TO_PI_RATIO;  // since math.h uses radians, convert the random angle to radians
		enemy.setdy(cos(radians));

		enemy.setdx(dirX*(sqrt(1 - pow(enemy.getdy(), 2))));
		
	
	}
	
	// Need of a route changer if hits with another hitbox

	//std::cout << enemy.getdx() << "," << enemy.getdy() << std::endl;
	//std::cout <<"bottom: ("<< enemy.hitbox.getBottomRightX() << "," << enemy.hitbox.getBottomRightY() << " Top: (" << enemy.hitbox.getTopLeftX() << ", " << enemy.hitbox.getTopLeftY() << ") " << std::endl;
}