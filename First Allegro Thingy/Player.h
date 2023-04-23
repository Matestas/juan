#pragma once

#include "Bullet.h"
class Player : public BaseEntity {
public:
	Player();
	~Player();
	//void spawn();
	void fire_bullet();
	void update();
	void move(const int, const int);
	std::vector<Bullet> getbullets();
	ALLEGRO_BITMAP* Ship = NULL;

private:
	std::vector<Bullet> bullets;
	int health = 10;
	bool speedBoost = false;
	void draw();
	ALLEGRO_BITMAP* juan = NULL;

};