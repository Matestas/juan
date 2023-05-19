#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
class Hitbox
{
public:
	
	bool operator ==(Hitbox& t);
	int getTopLeftX();
	int getTopLeftY();
	int getBottomRightX();
	int getBottomRightY();
	Hitbox(int topLeftX=1, int dimX=1, int topLeftY=1, int dimY=1);
	void move(int xcoord, int ycoord);
	void draw();
	
private:
	int topLeftX;
	int bottomRightX;
	int topLeftY;
	int bottomRightY;
	int dimX;
    int dimY;
	
};
