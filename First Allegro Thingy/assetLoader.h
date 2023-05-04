#pragma once
#include "Loaders.h"
#include "Player.h"
#include "RocketLauncher.h"
#include "Shotgun.h"
#include "MachineGun.h"

void loadTest(Player& player, Gun&gun,RocketLauncher& rocket,Shotgun &shotgun , MachineGun & mGun) {
	player.setShipImage(load_image("Main_Ship.png", "Player Ship"));
	gun.setBulletSound(load_sample("juanito.wav", "bulletEffect"));
	gun.setBulletImage(load_image("juan.jpg", "bulletImage"));
	//rocket.setBulletSound(load_sample("juanito.wav", "bulletEffect"));
	//rocket.setBulletImage(load_image("juan.jpg", "bulletImage"));
	//shotgun.setBulletSound(load_sample("juanito.wav", "bulletEffect"));
	//shotgun.setBulletImage(load_image("juan.jpg", "bulletImage"));
	//mGun.setBulletSound(load_sample("juanito.wav", "bulletEffect"));
	//mGun.setBulletImage(load_image("juan.jpg", "bulletImage"));
};