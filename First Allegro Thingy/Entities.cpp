
#include "Entities.h"


void BaseEntity::draw() {
	//NULL
}

Map BaseEntity::getMap()
{
	return map;
}

void BaseEntity::move(const float dirX, const float dirY) {
	this->x += (dirX * speedX);
	this->y += (dirY * speedY);

	hitbox.move(x, y);
	if (checkiMap()) {

		this->x -= (dirX * speedX);
		this->y -= (dirY * speedY);
		hitbox.move(this->x, this->y);


	};
}
Hitbox BaseEntity::getHitbox()
{
	return hitbox;
}
bool BaseEntity::checkiMap() {
	if (map == hitbox) {
		return false;
	}return true;
}


