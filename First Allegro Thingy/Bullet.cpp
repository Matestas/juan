#include "Bullet.h"
#include "Loaders.h"


Bullet::Bullet(int x, int y) {
	
	this->x = x;
	this->y = y;
	this->speedX = 20;
	this->speedY = 0;
	isMoving = false;
}
Bullet::Bullet():BaseEntity(2000,2000,10,5,10,0) {
	isMoving = false;
	speedX = 20;
	speedY = 0;
}
Bullet::~Bullet() {
	
}
void Bullet::move(std::vector<Enemy*> enemies) {
	for (int tx = 0; tx < speedX; tx++) {
		for(int ty=0;ty<speedY;ty++){
			this->x += speedX;
		}
		if (isMoving) {	
			this->y += speedY;
		}
		hitbox.move(x, y);
		for (auto it = enemies.begin(); it != enemies.end(); ++it) {
			Enemy* enemy = *it;

			if (checkhit(enemy->getHitbox())) {
				enemies.erase(it);
				delete enemy; // delete the enemy object
			}
		}
	}
	
}
void Bullet::moveto(const int dirX, const int dirY) {
	this->x = (dirX);
    this->y = (dirY);
}

void Bullet::draw() {
	al_draw_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(250, 250, 25), 2);
	//al_draw_scaled_bitmap(bulletImage, 0, 0, 1083, 1060, x, y, 30, 30, 0);
}
void Bullet::ignite() {
	// charge animation here ( 10 frames maybe) 
	
	al_play_sample(bulletSound,1,0,1,ALLEGRO_PLAYMODE_ONCE,0);
	
}
Bullet::Bullet(Bullet& old) {
	this->x = old.x;
	this->y = old.y;
	this->isMoving = old.isMoving;
	this->speedX = old.speedX;
    this->speedY = old.speedY;
	this->bulletImage = old.bulletImage;
	this->bulletSound = old.bulletSound;
}

int Bullet::getspeedX() {
	return speedX;
}
int Bullet::getspeedY() {
    return speedY;
}
void Bullet::setspeed(int speedX,int speedY) {
	this->speedX = speedX;
	this->speedY = speedY;
}
bool Bullet::checkhit(Hitbox x) {
	if (hitbox == x) {
		return true;
	}
	else {
		return false;
	}
}

void Bullet::setDimensions(int x,int y){
	dimX = x;
	dimY = y;
}



void Bullet::setBulletSound(Bullet ID,ALLEGRO_SAMPLE* sound) {
	ID.bulletSound = sound;
}
void Bullet::setBulletImage(Bullet ID,ALLEGRO_BITMAP* image) {
	ID.bulletImage = image;
}
ALLEGRO_BITMAP** Bullet::getBulletImage() {
	return &bulletImage;
}
ALLEGRO_SAMPLE** Bullet::getBulletSound() {
	return &bulletSound;
}