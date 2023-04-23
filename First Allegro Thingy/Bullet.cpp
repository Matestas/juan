#include "Bullet.h"
#include "Utils.h"
#include "imageLoader.h"
Bullet::Bullet(int x, int y) {
	if (juan == NULL) {
		this->juan = load_image("juan.jpg", "Ship");
	};
	this->common_bullet = al_create_sub_bitmap(juan, 0, 0, 39, 11);
	this->x = x;
	this->y = y;
}
Bullet::Bullet() {
	if (juan == NULL) {
		this->juan = load_image("juan.jpg", "Ship");
	};
	this->common_bullet = al_create_sub_bitmap(juan, 0, 0, 39, 11);
}

void update(std::vector<Bullet>bullets) {

	for (int bullet = bullets.size() - 1; bullet >= 0; bullet--) {

		bullets[bullet].draw();

	}
}
void moveall(std::vector<Bullet>bullets) {							//friend function of Bullet
	for (int bullet = bullets.size() - 1; bullet >= 0; bullet--) {
		bullets[bullet].move(1, 0);									// for normal bullets only 
		bullets[bullet].limit();
	}

}
void Bullet::draw() {

	this->common_bullet = al_create_sub_bitmap(common_bullet, 143, 135, 39, 11);
}
void Bullet::ignite() {
	// charge animation here ( 10 frames maybe) 


}
int Bullet::getspeed() {
	return speed;
}
void Bullet::limit() {
	if (this->x > 1920) {
		delete this;
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
