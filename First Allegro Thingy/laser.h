#pragma once
#include "Gun.h"
class Laser :
    public Gun
{
public:
    Laser();
    void fire_bullet(int x, int y, Ticker tick) override;
};

