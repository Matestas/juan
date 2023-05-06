#include "Enemy.h"
#include <math.h>
#define DEGREE_TO_PI_RATIO 0.0174532925
#define PI 3.14159265359
#define PI_OVER_TWO 3.14159265359/2




void Enemy::move(const float dirX, const float dirY) {
	this->x += (dirX * speed*1);
	this->y += (dirY * speed);

	hitbox.move(x, y);
	if (!(map == hitbox)) {

		this->x -= (dirX * speed*1);
	    this->y -= (dirY * speed);
		hitbox.move(this->x, this->y);
		

	};
}

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

Collision Enemy::getHitbox()
{
	return hitbox;
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

Enemy::Enemy(): BaseEntity(1250,360), hitbox(1250,1250 + dimX, 360,360 + dimY)
{

}
Enemy::Enemy(int x, int y, int speed) : BaseEntity(x, y), hitbox(x, x + dimX, y, y + dimY)
{
	this-> speed = speed;

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
