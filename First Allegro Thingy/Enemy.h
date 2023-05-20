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
		health-= damage;
		if (health <= 0) {
			delete this;
			return true;
		}
		return false;
	}
	ALLEGRO_BITMAP* getEnemyImage();
	ALLEGRO_BITMAP* getTotalExplosion();
	void setTotalExplosion(ALLEGRO_BITMAP* totalExplosion);

	
private:
	ALLEGRO_BITMAP* enemyShip;
	ALLEGRO_BITMAP* totalExplosion;
};

