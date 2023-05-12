#pragma once
#include "Gun.h"
class MachineGun :
	public Gun
{
public:
	MachineGun();
	void fire_bullet() override;
protected:
	int bulletFired;
};



