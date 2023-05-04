#include "Map.h"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

Map::Map():limit(0,SCREEN_WIDTH,0,SCREEN_HEIGHT) {

}
Map::~Map(){
        
}
bool Map::operator==(Collision& t)
{
    if (t.getTopLeftX() >= limit.getTopLeftX() && t.getBottomRightX() <= limit.getBottomRightX() && t.getTopLeftY() >= limit.getTopLeftY() && t.getBottomRightY() <= limit.getBottomRightY()) {
        return true; // the hitbox is completely inside the map's limit
    }
    return false;
}

