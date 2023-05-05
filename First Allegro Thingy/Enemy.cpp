#include "Enemy.h"
#include <math.h>
#define DEGREE_TO_PI_RATIO 0.0174532925
#define PI 3.14159265359
#define PI_OVER_TWO 3.14159265359/2
void Enemy::move(const float dirX, const float dirY) {
	this->x += (dirX * speed);
	this->y += (dirY * speed);

	hitbox.move(x, y);
	if (!(map == hitbox)) {

		this->x -= (dirX * speed);
		this->y -= (dirY * speed);
		hitbox.move(this->x, this->y);
	};

}

void Enemy::draw()
{
	al_draw_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(255, 255, 255), 5);
}

Enemy::Enemy(): BaseEntity(700,200), hitbox(700,730,200,230)
{

}

void Enemy::automatedMover()
{
	timer += 1;
	move(dx, dy);
	if (timer >= 30) {
		angle = (rand() % 180) * DEGREE_TO_PI_RATIO;  // 0 to pi
		dy = cos(angle);
		
		dx = -(sqrt(1 - pow(dy, 2)));
		move(dx, dy);
		timer = 0;
	}
	std::cout << dx << "," << dy << std::endl;
	//std::cout <<"bottom: ("<< hitbox.getBottomRightX() <<","<< hitbox.getBottomRightY()<<" Top: ("<< hitbox.getTopLeftX() <<", "<< hitbox.getTopLeftY()<<") " <<std::endl;
}
