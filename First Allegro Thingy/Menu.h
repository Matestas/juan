#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

class Menu
{
private:
	int dimX;
	int dimY;
	int x;
	int y;
	bool isChoosen;
	bool isHovered;
public:
	void draw(bool isHovered);
	
};

