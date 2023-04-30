#include "Bullet.h"
#include "Loaders.h"


Bullet::Bullet(int x, int y) {
	if (common_bullet == NULL) {
		this->common_bullet = load_image("juan.jpg", "Ship");
	};
	if (juan_effect == NULL) {

		juan_effect = load_sample("juanito.wav", "juanito.wav");

		int err = al_get_errno();
		std::cout << "no juan" << std::endl;
		std::cout << err << std::endl;
	}
	this->x = x;
	this->y = y;
	this->speed = 60;
}
Bullet::Bullet() {
	if (common_bullet == NULL) {
		this->common_bullet = load_image("juan.jpg", "Ship");
	};
	
}
Bullet::~Bullet() {
	
}
void Bullet::move(const int dirX, const int dirY) {
	this->x += (dirX * speed);
	this->y += (dirY * speed);
}


void Bullet::draw() {

	al_draw_scaled_bitmap(common_bullet, 0, 0, 1083, 1060, x, y, 30, 30, 0);
}
void Bullet::ignite() {
	// charge animation here ( 10 frames maybe) 
	
	al_play_sample(juan_effect,1,0,1,ALLEGRO_PLAYMODE_ONCE,0);
	
}

int Bullet::getspeed() {
	return speed;
}
void limit(std::vector <Bullet>&  bullets) {
	for (int bullet = bullets.size() - 1; bullet >= 0; bullet--) {
		if (bullets[bullet].x > 1280) {
			bullets.erase(bullets.begin() + bullet);
			
		}
	}
	
}
void Bullet::hit() {
	if (checkhit()) {
		this->health -= 1;
	}

	// hit animation function here
}
void Bullet::setspeed() {

}
bool Bullet::checkhit() {

	// check which enemy hit and call beenhit function on the enemy hit, check if the enemy hit with a bullet is not hit again with the same bullet
	// , which can cause bugs with the perfuration mechanic
	return true;
}
