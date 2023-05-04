#include "Collision.h"

bool Collision::operator==(Collision &t)
{
	if (topLeftX < t.bottomRightX) return false;   // rect1 is to the left of rect2
	if (bottomRightX > t.topLeftX) return false;   // rect1 is to the right of rect2
    if (topLeftY < t.bottomRightY) return false;   // rect1 is above rect2
	if (bottomRightY > t.topLeftY) return false; 
	return true;
}

void Collision::move(int xcoord, int ycoord) {
	this->topLeftX = xcoord;
	this->topLeftY = ycoord;
	bottomRightX = xcoord + 120;
	bottomRightY = ycoord + 83;
}

Collision::Collision(int topLeftX, int bottomRightX, int topLeftY, int bottomRightY)
{
	this->bottomRightX = bottomRightX;
	this->topLeftY = topLeftY;
	this->bottomRightY = bottomRightY;
	this->topLeftX = topLeftX;
	this->dimX =  bottomRightX;
	this->dimY = bottomRightY;
}

int Collision::getTopLeftX() {
	return topLeftX;
}
int Collision::getTopLeftY() {
	return topLeftY;
}
int Collision::getBottomRightX() {
	return bottomRightX;
}

int Collision::getBottomRightY() {
	return bottomRightY;
}
