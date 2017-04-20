#include "Ghost.h"



Ghost::Ghost(int xo, int yo)
{
	x = xo;
	y = yo;
	_hp = 30;
	_dmg = 12;
	isMoving = true;
	isDead = false;
	trup.loadFromFile("src/ghost.png");
	dead.loadFromFile("src/dead_ghost.png");
	zombi.setTexture(trup);
	zombi.setPosition(x, y);
	pain.loadFromFile("src/zombie_pain.wav");
	getHit.setBuffer(pain);
	atakasz.loadFromFile("src/bite.wav");
	bite.setBuffer(atakasz);
}

int Ghost::money_get() {
	return _gold;
}

Ghost::~Ghost()
{
	z_thread.join();
}
