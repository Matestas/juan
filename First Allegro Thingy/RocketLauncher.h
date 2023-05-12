#pragma once
#include "Gun.h"
class RocketLauncher:
public Gun
{
public:
	RocketLauncher();
    void fire_bullet() override;
};

