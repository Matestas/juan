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
void Bullet::move() {
	if (isMoving) {
		this->y += speedY;
		this->x += speedX;
		hitbox.move(x, y);
	}
	
}
void Bullet::moveto(const int dirX, const int dirY) {
	this->x = (dirX+60);
    this->y = (dirY);
}

void Bullet::draw() {
	al_draw_filled_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(72, 233, 235));
	//al_draw_scaled_bitmap(bulletImage, 0, 0, 1083, 1060, x, y, 30, 30, 0);
	
}

Bullet::Bullet(Bullet& old) {
	this->x = old.x;
	this->y = old.y;
	this->isMoving = old.isMoving;
	this->speedX = old.speedX;
    this->speedY = old.speedY;
	this->explosion = old.explosion;
	this->hitbox = old.hitbox;
	this->dimX = old.dimX;
	this->dimY = old.dimY;
	

	
}

int Bullet::getspeedX() {
	return speedX;
}
int Bullet::getspeedY() {
    return speedY;
}

void Bullet::explode()
{
	if (ticker.getTick() > 0) {
		
		if (ticker.getTick() <= 5) {
			al_draw_scaled_bitmap(explosion, 0, 0, 32, 32, hitSpotX, hitSpotY, 18, 18, 0);
			ticker.ticker();
		}
		else if (ticker.getTick() <= 2 ) {
			al_draw_scaled_bitmap(explosion, 32, 0, 32, 32, hitSpotX, hitSpotY, 18, 18, 0);
			ticker.ticker();
		}
		else if (ticker.getTick() <= 4 ) {
			al_draw_scaled_bitmap(explosion, 64, 0, 32, 32, hitSpotX, hitSpotY, 18, 18, 0);
			ticker.ticker();
		}
		else if (ticker.getTick() <= 8 ) {
			al_draw_scaled_bitmap(explosion, 96, 0, 32, 32, hitSpotX, hitSpotY, 18, 18, 0);
			ticker.ticker();
			
		}
		else if (ticker.getTick() <= 10 ) {
			al_draw_scaled_bitmap(explosion, 128, 0, 32, 32, hitSpotX, hitSpotY, 18, 18, 0);
			ticker.ticker();
		}
		else if (ticker.getTick() <= 15 ) {
			al_draw_scaled_bitmap(explosion,162, 0, 32, 32, hitSpotX, hitSpotY, 18, 18, 0);
			ticker.ticker();
		}
		else {
			ticker.setTick(0);
			hitSpotX = -100;
			hitSpotY = -100;
		};
	}
}
void Bullet::setspeed(int speedX,int speedY) {
	this->speedX = speedX;
	this->speedY = speedY;
}
bool Bullet::checkhit(Hitbox &x) {
	if (hitbox == x) {
		isMoving = false;
		return true;	
	}
	else {
		if(checkInside(x)){
			isMoving = false;
			return true;		
		}
		else {
			return false;
		}
		
	}
}

void Bullet::setDimensions(int x,int y){
	dimX = x;
	dimY = y;
}



