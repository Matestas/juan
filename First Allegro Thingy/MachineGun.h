#pragma once
#include "Gun.h"
class MachineGun :
	public Gun
{
public:
	MachineGun();
	void fire_bullet(int x,int y,int tick) override;
};



