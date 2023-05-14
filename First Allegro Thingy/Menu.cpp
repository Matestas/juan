#include "Menu.h"

void Menu::draw(bool isHovered){
	
	if(isHovered){
		al_draw_filled_rectangle(640 - dimX / 2, 360 - dimY / 2, 720 + dimX / 2, 360 + dimY / 2,al_map_rgb(255,55,0));
	}
	if(!isHovered){

	}
}