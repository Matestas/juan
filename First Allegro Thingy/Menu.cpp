#include "Menu.h"

Menu::Menu(int x, int y, int dimX, int dimY, const char* text, ALLEGRO_FONT* font): x(x),y(y),dimX(dimX),dimY(dimY),text(text),font(font) {
	isChoosen = false;
	isHovered = false;
}

void Menu::draw(){
	
	if(isHovered){
		al_draw_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(255, 0, 255), 10);
		al_draw_text(font, al_map_rgb(255, 55, 100), x + 90, y + 40, 0, text);
	}
	if(!isHovered){
		al_draw_filled_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(50, 50, 50));
		al_draw_text(font, al_map_rgb(255, 55, 100), x + 90, y+40, 0, text);
	}
}

bool Menu::choose()
{
	isChoosen = true;
	return isChoosen;
}

ALLEGRO_FONT* Menu::getFont()
{
	return font;
}
