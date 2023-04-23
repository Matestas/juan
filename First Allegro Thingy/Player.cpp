#include "Utils.h"
#include "Player.h"


Player::Player() : BaseEntity(0, 0) {
	if (Ship == NULL) {
		this->Ship = load_image("juan.jpg", "Ship");
	};

	speed = 20;
}
void Player::fire_bullet() {
	Bullet newbullet(x + 50, y);
	bullets.push_back(newbullet);
	newbullet.ignite();
}
void Player::move(const int dirX, const int dirY) {
	this->x += (dirX * speed);
	this->y += (dirY * speed);
	update();

}
void Player::draw() {

	al_draw_scaled_bitmap(Ship, 0, 0, 1083, 1063, x, y, 100, 100, 0);
	std::cout << x << ", " << y << std::endl;
}
Player::~Player() {

}
void Player::update() {
	draw();

}
std::vector<Bullet> Player::getbullets() {
	return bullets;
}