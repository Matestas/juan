#pragma once
#include "Bullet.h"
class Enemy: public BaseEntity
{
public:
	
	Enemy();
	int health;
	Enemy(int x, int y, int speedX,int speedY, int moveType = 1,int dimX= 50,int dimY=50, int health=20);
	float dy;
	float dx;
	void draw();
	bool limit();
	int moveType;
	void setEnemyShip(ALLEGRO_BITMAP* enemyShip);
	bool getDamaged(int damage) {
		health-= damage; //reduces health
		if (health <= 0) {
			delete this;//deletes this object
			return true;
		}
		return false;
	}
	ALLEGRO_BITMAP* getEnemyImage();
	
	void setTotalExplosion(ALLEGRO_BITMAP* totalExplosion);

	
private:
	ALLEGRO_BITMAP* enemyShip;
	
};

