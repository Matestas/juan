#pragma once
#include "Gun.h"
class RocketLauncher:
public Gun
{
public:
	RocketLauncher();
    void fire_bullet(int x, int y, int tick) override;
};

