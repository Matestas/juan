#include "Menu.h"



MenuButton::MenuButton(int x, int y, int dimX, int dimY, const char* text, ALLEGRO_FONT* font, bool isHovered): x(x),y(y),dimX(dimX),dimY(dimY),text(text),font(font),isHovered(isHovered) {
	isChoosen = false;
	
}

void MenuButton::draw(){
	
	if(isHovered){
		al_draw_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(255, 0, 255), 10);
		al_draw_text(font, al_map_rgb(255, 55, 100), x , y , 0, text);
	}
	if(!isHovered){
		al_draw_filled_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(50, 50, 50));
		al_draw_text(font, al_map_rgb(255, 55, 100), x, y, 0, text);
	}
}

bool MenuButton::choose()
{
	isChoosen = true;
	return isChoosen;
}

ALLEGRO_FONT* MenuButton::getFont()
{
	return font;
}

