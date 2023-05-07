#include "Enemy.h"
#include <math.h>
#define DEGREE_TO_PI_RATIO 0.0174532925
#define PI 3.14159265359
#define PI_OVER_TWO 3.14159265359/2






void Enemy::draw()
{
	al_draw_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(255, 255, 255), 5);
}

float Enemy::getdx()
{
	return dx;
}

float Enemy::getdy()
{
	return dy;
}



void Enemy::setdy(float dy)
{
	this->dy = dy;
}

void Enemy::setdx(float dx)
{
	this->dx = dx;
}

bool Enemy::limit()
{
	if (!(map == hitbox)) {
		return true;
	}
}

Enemy::Enemy(): BaseEntity(1250,360)
{

}
Enemy::Enemy(int x, int y, int speedX,int speedY) : BaseEntity(x, y,dimX,dimY,speedX,speedY)
{

}

void Enemy::automatedMover()  // just a prototype, can be removed
{
	timer += 1;
	move(dx, dy);

	if (timer >= 20) {
		float degree = (55 + rand() % 70);   
		angle = degree * DEGREE_TO_PI_RATIO;  // 0 to pi
		dy = cos(angle);
		
		dx = -(sqrt(1 - pow(dy, 2)));
		move(dx, dy);
		timer = 0;
		std::cout << degree << std::endl;
	}
	
	//std::cout << dx << "," << dy << std::endl;
	//std::cout <<"bottom: ("<< hitbox.getBottomRightX() <<","<< hitbox.getBottomRightY()<<" Top: ("<< hitbox.getTopLeftX() <<", "<< hitbox.getTopLeftY()<<") " <<std::endl;
}
