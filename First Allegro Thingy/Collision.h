#pragma once

class Hitbox
{
public:
	
	bool operator ==(Hitbox& t);
	~Hitbox() {};
	int getTopLeftX();
	int getTopLeftY();
	int getBottomRightX();
	int getBottomRightY();
	Hitbox(int topLeftX=1, int dimX=1, int topLeftY=1, int dimY=1);
	void move(int xcoord, int ycoord);
	
private:
	int topLeftX;
	int bottomRightX;
	int topLeftY;
	int bottomRightY;
	int dimX;
    int dimY;
	
};
