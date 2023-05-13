#pragma once
#include "Gun.h"
class Laser :
    public Gun
{
    Laser();
    void fire_bullet(int x, int y, int tick) override;
};

