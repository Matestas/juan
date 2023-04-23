#pragma once
#include "Entities.h"


class Bullet : public BaseEntity {
	friend void moveall(std::vector<Bullet>bullets);
	friend void update(std::vector<Bullet>bullets);

public:
	Bullet();
	Bullet(int, int);
	int getspeed();
	void limit();     // screen limiter
	void hit();

	// hits the enemy
	void ignite();    // firing
	bool checkhit(); // check if hits enemy
	ALLEGRO_BITMAP* common_bullet = NULL;
	private:
	int damage = 1;
	int health = 1;   // used for perfuration mechanics used in buffs
	int speed = 2;
	void setspeed();
	void draw();
	ALLEGRO_BITMAP* juan = NULL;
};


