#include "Enemy.h"
#include <math.h>
#define DEGREE_TO_PI_RATIO 0.0174532925
#define PI 3.14159265359
#define PI_OVER_TWO 3.14159265359/2
#define MIN_RANGE 55
#define MAX_RANGE 125





void Enemy::draw()
{
	al_draw_scaled_bitmap(enemyShip, 7, 6, 15, 12, x, y, dimX, dimY, ALLEGRO_FLIP_HORIZONTAL); //draws the enemy png
	

}





bool Enemy::limit()
{
	if (!(map == hitbox)) {//checks if inside map
		return true;
	}
	return false;
}

void Enemy::setEnemyShip(ALLEGRO_BITMAP* enemyShip)
{
	this->enemyShip = enemyShip;
}



ALLEGRO_BITMAP* Enemy::getEnemyImage()
{
	return enemyShip;
}

Enemy::Enemy(): BaseEntity(1250,360,20,20) //base constructor
{

}
ALLEGRO_BITMAP* Enemy::getTotalExplosion()
{
	return totalExplosion;
}

void Enemy::setTotalExplosion(ALLEGRO_BITMAP* totalExplosion)
{
	this->totalExplosion = totalExplosion;
}

Enemy::Enemy(int x, int y, int speedX,int speedY, int moveType,int dimX,int dimY,int health) : BaseEntity(x, y,dimX,dimY,speedX,speedY), moveType(moveType) //Used Constructor
{
	this->health = health;
	dx = 0;
	enemyShip = NULL;
	totalExplosion = NULL;
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


