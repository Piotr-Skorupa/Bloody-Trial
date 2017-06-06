#include "Ghost.h"



Ghost::Ghost(int xo, int yo)
{
	x = xo;
	y = yo;
	_hp = 60;
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

std::string Ghost::hptexta() {
	return std::to_string(_hp);
}


void Ghost::newgame1(int xo, int yo) {
	x = xo;
	y = yo;
	_hp = 60;
	_dmg = 12;
	isMoving = true;
	isDead = false;
	zombi.setTexture(trup);
}

int Ghost::money_get() {
	return _gold;
}

void Ghost::take_dmga(int a, int &b, int &c) {
	_hp -= a;
	getHit.play();
	if (_hp <= 0) {
		isDead = true;
		isMoving = false;
		zombi.setTexture(dead);
		b += _gold;
		c -= 1;
	}
}

Ghost::~Ghost()
{
	z_thread.join();
}
