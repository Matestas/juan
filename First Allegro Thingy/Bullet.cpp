#include "Bullet.h"
#include "Loaders.h"


Bullet::Bullet(int x, int y) {
	
	this->x = x;
	this->y = y;
	hitSpotX = -100;
	hitSpotY = -100;
	explosion = NULL;
	this->speedX = 20;
	this->speedY = 0;
	isMoving = false;
	
}
Bullet::Bullet():BaseEntity(2000,2000,10,5,10,0) { //bullet constructor
	isMoving = false;
	speedX = 20;
	hitSpotX = -100;
	hitSpotY = -100;
	explosion = NULL;
	speedY = 0;
}
Bullet::~Bullet() {
	
}
void Bullet::move() {//moves bullet
	if (isMoving) {
		this->y += speedY;
		this->x += speedX;
		hitbox.move(x, y);
	}
	
}
void Bullet::moveto(const int dirX, const int dirY) {// moves bullet to a point
	this->x = (dirX+60);
    this->y = (dirY);
}

void Bullet::draw() {
	al_draw_filled_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(72, 233, 235)); //draws bullet
	
}

Bullet::Bullet(Bullet& old) {//copy constructor
	this->x = old.x;
	this->y = old.y;
	this->isMoving = old.isMoving;
	this->speedX = old.speedX;
    this->speedY = old.speedY;
	this->explosion = old.explosion;
	this->hitbox = old.hitbox;
	this->dimX = old.dimX;
	this->dimY = old.dimY;
	hitSpotX = old.hitSpotX;
	hitSpotY = old.hitSpotY;

	
}

int Bullet::getspeedX() {
	return speedX;
}
int Bullet::getspeedY() {
    return speedY;
}

void Bullet::explode()
{
	if (ticker.getTick() > 0) {//shows explosion
		
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
	if (hitbox == x) { //checks hit
		isMoving = false;
		return true;	
	}
	else {
		if(checkInside(x)){ //checks inside 
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



