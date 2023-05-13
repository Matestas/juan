#include "Gun.h"

Gun::Gun(float fireRate,int damage, ALLEGRO_SAMPLE* bulletSound , ALLEGRO_BITMAP* bulletImage ){
	this->fireRate = fireRate;
	this->damage = damage;
	this->bulletSound = bulletSound;
	this->bulletImage = bulletImage;
	bulletsFired = 0;
	tickFired = 0;
}

ALLEGRO_BITMAP** Gun::getBulletImage(int i) {
	return bullets[i].getBulletImage();
}
ALLEGRO_SAMPLE** Gun::getBulletSound(int i) {
	return bullets[i].getBulletSound();
}
void Gun::loadBullets() {
	for (int i = 1; i <= 8; i++) {
		this->bullets[i] = Bullet(bullets[0]);
	}
}
void Gun::moveBullets() {
	for (int i = 0; i < MAX_BULLETS; i++) {
		bullets[i].move();
		bullets[i].draw();
	}
}
void Gun::fire_bullet(int x, int y, int tick) {
	al_play_sample(*getBulletSound(0), 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);

}
void Gun::setBulletSound(ALLEGRO_SAMPLE* sound) {
	bulletSound = sound;
}
void Gun::setBulletImage(ALLEGRO_BITMAP* image) {
	bulletImage = image;
}
ALLEGRO_BITMAP** Gun::getBulletImage() {
	return &bulletImage;
}
ALLEGRO_SAMPLE** Gun::getBulletSound() {
	return &bulletSound;
}
void Gun::resetbullets() {
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (bullets[i].checkhit() || !(bullets[i].checkiMap())) {
			bullets[i].isMoving = false;
			bullets[i].moveto(2000, 2000);
		}
	}
}
void Gun::nextTick() {
	if (tickFired + fireRate >= 128) {
		tickToFire = tickFired + fireRate - 128;
	}
	else {
		tickToFire = tickFired + fireRate;
	}
}