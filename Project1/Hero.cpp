#include "Hero.h"



Hero::Hero()
{
	life_max = 100;
	mana_max = 50;
	life = 100;
	mana = 50;
	str = 10;
	damage1 = 5;
	damage2 = 10;
	x = 20;
	y = 100;
	isMoving = true;
	level = 1;
	up = false;
	down = false;
	left = false;
	right = true;
	potki_many = 1;
	potki_zycia = 1;
	money = 100;
	nr_broni = 0;

	font.loadFromFile("src/Oswald-Stencil.ttf");
	ziomek.loadFromFile("src/hero.png");
	hero.setTexture(ziomek);
	hero.setPosition(x, y);
	zyc.setFont(font);
	man.setFont(font);
	zyc.setCharacterSize(20);
	man.setCharacterSize(20);


}

int Hero::attack() {
	return damage1 + (std::rand() % (damage2 - damage1 + 1));
}

void Hero::take_dmga(int a) {
	life -= a;
}

Hero::~Hero()
{
}

void Hero::moveLeft() {
	isMoving = true;
	if (x <= 0) isMoving = false;
	else {
			if (isMoving == true) {
			x -= 10;
			hero.move(-10, 0);
			up = false;
			down = false;
			left = true;
			right = false;
		}
	}
}

void Hero::moveRight() {
	isMoving = true;
	if (x >= 4900) isMoving = false;
	else {
		if (isMoving == true) {
			x += 10;
			hero.move(10, 0);
			up = false;
			down = false;
			left = false;
			right = true;
		}
	}
}

void Hero::moveUp() {
	isMoving = true;
	if (y <= 0) isMoving = false;
	else {
		if (isMoving == true) {
			y -= 10;
			hero.move(0, -10);
			up = true;
			down = false;
			left = false;
			right = false;
		}
	}
}



void Hero::moveDown() {
	isMoving = true;
	if (y >= 1900) isMoving = false;
	else {
		if (isMoving == true) {
			y += 10;
			hero.move(0, 10);
			up = false;
			down = true;
			left = false;
			right = false;
		}
	}
}

int Hero::getlvl() {
	return level;
}

void Hero::lifetexty() {

	std::string str1 = std::to_string(life);
	std::string str2 = std::to_string(mana);

	zyc.setString(str1);
	man.setString(str2);
}

void Hero::stratamany(int x) {
	mana -= x;
}

int Hero::stan_many() {
	return mana;
}

int Hero::getManaMax() {
	return mana_max;
}

void Hero::newgame() {
	life_max = 100;
	mana_max = 50;
	life = 100;
	mana = 50;
	str = 10;
	damage1 = 5;
	damage2 = 10;
	x = 20;
	y = 100;
	isMoving = true;
	level = 1;
	up = false;
	down = false;
	left = false;
	right = true;
	hero.setPosition(x, y);
	potki_many = 1;
	potki_zycia = 1;
	money = 100;
	nr_broni = 0;

}