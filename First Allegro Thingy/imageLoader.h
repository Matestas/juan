#pragma once
#include <iostream>
#include "Utils.h";

 ALLEGRO_BITMAP* load_image(const char* filename,const char* image_ID) {
    ALLEGRO_BITMAP* image = al_load_bitmap(filename);
    
    if (!image) {
        std::cerr << "Failed to load " << image_ID << std::endl;
        
    }
    return image;
}




