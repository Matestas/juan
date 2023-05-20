#include "Menu.h"



MenuButton::MenuButton(int x, int y, int dimX, int dimY,ALLEGRO_BITMAP* buttonImage, bool isHovered): x(x),y(y),dimX(dimX),dimY(dimY),buttonImage(buttonImage),isHovered(isHovered) {
	isChoosen = false;
	
}

void MenuButton::draw(){
	
	if(isHovered){
		al_draw_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(164, 32, 32), 10);
		al_draw_bitmap(buttonImage, x, y, 0);
		
	}
	if(!isHovered){
		al_draw_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(100, 100, 100),10);
		al_draw_bitmap(buttonImage, x, y,0);
	}
}

bool MenuButton::choose()
{
	isChoosen = true;
	return isChoosen;
}

ALLEGRO_BITMAP* MenuButton::getImage()
{
	return buttonImage;
}

