#include "Enemy.h"
#include <math.h>
#define DEGREE_TO_PI_RATIO 0.0174532925
#define PI 3.14159265359
#define PI_OVER_TWO 3.14159265359/2
#define MIN_RANGE 55
#define MAX_RANGE 125





void Enemy::draw()
{
	al_draw_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(255, 255, 255), 5);
	hitbox.draw();
}





bool Enemy::limit()
{
	if (!(map == hitbox)) {
		return true;
	}
	return false;
}

Enemy::Enemy(): BaseEntity(1250,360,20,20)
{

}
Enemy::Enemy(int x, int y, int speedX,int speedY, int moveType,int dimX,int dimY) : BaseEntity(x, y,dimX,dimY,speedX,speedY), moveType(moveType)
{
	dx = 0;
	dy = 0;
	int randomTo2 = rand() % 2 + 1;
	if (randomTo2 == 1) {
		dy = cos(MIN_RANGE * DEGREE_TO_PI_RATIO);
		dx = (-1 * (sqrt(1 - pow(dy, 2))));
	}
	else if (randomTo2 == 2) {
		dy = cos(MAX_RANGE * DEGREE_TO_PI_RATIO);
		dx = (-1 * (sqrt(1 - pow(dy, 2))));
	}
}


