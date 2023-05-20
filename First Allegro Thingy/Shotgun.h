#pragma once
#include "Gun.h"
class Shotgun:
public Gun
{

public:
	Shotgun();
    void fire_bullet(int x, int y, Ticker tick) override;
	
};

