#pragma once
#include "Gun.h"
class Shotgun:
public Gun
{
public:
	Shotgun();
    void fire_bullet() override;
private:
	//void moveBullets(Bullet bullets[]);
};

