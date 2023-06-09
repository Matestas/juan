#include "Gun.h"
Gun::Gun(float fireRate,int damage, ALLEGRO_SAMPLE* bulletSound , ALLEGRO_BITMAP* bulletImage ){ //gun constructor
	this->fireRate = fireRate;
	this->damage = damage;
	this->gunSound = bulletSound;
	this->bulletImage = bulletImage;
	
	bulletsFired = 0;
	
}
void Gun::loadBullets() { 
	for (int i = 1; i <= 29 ; i++) {
		this->bullets[i] = Bullet(bullets[0]); //loads bullets
	}
}
void Gun::moveBullets() {
	for (int i = 0; i < MAX_BULLETS; i++) { //moves and draws all the bullets
		bullets[i].move();
		if (bullets[i].isMoving) {
			bullets[i].draw();
		}		
	}
}
void Gun::fire_bullet(int x, int y, Ticker tick) {
	al_play_sample(getGunSound(), 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0); //example function

}
void Gun::setGunSound(ALLEGRO_SAMPLE* sound) {
	gunSound = sound;
}
void Gun::setBulletImage(ALLEGRO_BITMAP* image) {
	bulletImage = image;
}
void Gun::setExplosion(ALLEGRO_BITMAP* image)
{
	bullets[0].explosion = image;

}
ALLEGRO_BITMAP* Gun::getBulletImage() {
	return bulletImage;
}
ALLEGRO_SAMPLE* Gun::getGunSound() {
	return gunSound;
}
void Gun::resetbullets(Hitbox hit) {
	for (int i = 0; i < MAX_BULLETS; i++) { //resets all bullets outside the map
		if (bullets[i].isMoving) {
			if (!bullets[i].checkiMap()) {
				bullets[i].isMoving = false;
				bullets[i].moveto(2000, 2000);
			}
			if (bullets[i].checkhit(hit)) {
				bullets[i].isMoving = false;
				bullets[i].moveto(2000, 2000);
			}
		}
	}
}

bool Gun::checkhit(Hitbox &x)
{
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (bullets[i].isMoving) {
			if (bullets[i].checkhit(x)) { //checks for hits in all bullets and sets the coordinates for the explosions
				bullets[i].hitSpotX = bullets[i].getX() + bullets[i].getDimX();
				bullets[i].hitSpotY = bullets[i].getY();
				bullets[i].ticker.ticker();
				bullets[i].explode();
				return true;
			}
		}
	}
	return false;
}

void Gun::drawBullets()
{
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (bullets[i].isMoving) {
			bullets[i].draw();  //draws all moving bullets
		}	
	}
}

int Gun::getDamage()
{
	return damage; //returns damage
}
