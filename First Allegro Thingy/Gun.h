#pragma once
#include "Bullet.h"
#define MAX_BULLETS 30
class Gun
{
public:
	Gun(float fireRate = 10, int angle = 0, int fired = 1, int damage = 10, ALLEGRO_SAMPLE* bulletSound = NULL, ALLEGRO_BITMAP* bulletImage = NULL); // fuck you
	ALLEGRO_BITMAP** getBulletImage();
	ALLEGRO_SAMPLE** getBulletSound();
	void setBulletSound(ALLEGRO_SAMPLE* sound);
	void setBulletImage(ALLEGRO_BITMAP* image);
	virtual void fire_bullet();
	ALLEGRO_BITMAP** getBulletImage(int i);
	ALLEGRO_SAMPLE** getBulletSound(int i);
	void moveBullets(Bullet bullets[]);
    Bullet bullets[MAX_BULLETS];
private:
	float fireRate; // SHOTS FIRED
	int bulletAngle ;
	void loadBullets();
	ALLEGRO_SAMPLE* bulletSound;
	ALLEGRO_BITMAP* bulletImage;
	int damage;
};

