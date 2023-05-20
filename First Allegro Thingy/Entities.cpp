
#include "Entities.h"


void BaseEntity::draw() {
	//NULL
}

Map BaseEntity::getMap()
{
	return map;
}

void BaseEntity::move(const float dirX, const float dirY) {
	this->x += (dirX * speedX);//moves the entity
	this->y += (dirY * speedY);

	hitbox.move(x, y);
	if (!checkiMap()) {//reverts the movement if outside map

		this->x -= (dirX * speedX);
		this->y -= (dirY * speedY);
		hitbox.move(x,y);
	};
}
Hitbox* BaseEntity::getHitbox()
{
	return &hitbox;
}
bool BaseEntity::checkiMap() {
	if (checkInside(map.limit)) {//checks if inside the map
		return true;
	}return false;
}

bool BaseEntity::checkInside(Hitbox &a)
{
	// Verifies if the one hitbox is inside the other
	bool insideX = hitbox.getTopLeftX() >= a.getTopLeftX() && hitbox.getBottomRightX() <= a.getBottomRightX();
	bool insideY = hitbox.getTopLeftY() >= a.getTopLeftY() && hitbox.getBottomRightY() <= a.getBottomRightY();
	bool insideX2 = a.getTopLeftX() >= hitbox.getTopLeftX() && a.getBottomRightX() <= hitbox.getBottomRightX();
	bool insideY2 = a.getTopLeftY() >= hitbox.getTopLeftY() && a.getBottomRightY() <= hitbox.getBottomRightY();

	return (insideX && insideY) || (insideX2 && insideY2);
}


