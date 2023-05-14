#include "Enemy.h"
#include <math.h>
#define DEGREE_TO_PI_RATIO 0.0174532925
#define PI 3.14159265359
#define PI_OVER_TWO 3.14159265359/2






void Enemy::draw()
{
	al_draw_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(255, 255, 255), 5);
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
Enemy::Enemy(int x, int y, int speedX,int speedY) : BaseEntity(x, y,dimX=20,dimY=20,speedX,speedY)
{

}
