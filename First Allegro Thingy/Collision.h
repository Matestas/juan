#pragma once

class Collision
{
public:
	
	bool operator ==(Collision& t);
	Collision() {};
	~Collision() {};
	int getTopLeftX();
	int getTopLeftY();
	int getBottomRightX();
	int getBottomRightY();
	Collision(int topLeftX, int bottomRightX, int topLeftY, int bottomRightY);
	void move(int xcoord, int ycoord);

private:
	int topLeftX;
	int bottomRightX;
	int topLeftY;
	int bottomRightY;
	int dimX;
    int dimY;
	
};
