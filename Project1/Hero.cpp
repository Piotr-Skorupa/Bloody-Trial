#include "Hero.h"



Hero::Hero()
{
	life_max = 100;
	mana_max = 50;
	life = 100;
	mana = 50;
	str = 10;
	speed = 20;
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
	
	krzyk.loadFromFile("src/scream.wav");
	scream.setBuffer(krzyk);
	picie.loadFromFile("src/potion.wav");
	drink.setBuffer(picie);


}

int Hero::attack() {
	return damage1 + (std::rand() % (damage2 - damage1 + 1));
}

void Hero::take_dmga(int a, int &stan) {
	life -= a;
	if (life <= 0) {
		stan = 6;
		scream.play();
	}
}

Hero::~Hero()
{
}

void Hero::moveLeft() {
	isMoving = true;
	if (x <= 0) isMoving = false;
	else {
			if (isMoving == true) {
			x -= speed;
			hero.move(-speed, 0);
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
			x += speed;
			hero.move(speed, 0);
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
			y -= speed;
			hero.move(0, -speed);
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
			y += speed;
			hero.move(0, speed);
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

int Hero::stan_zycia() {
	return life;
}

int Hero::getLifeMax() {
	return life_max;
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

void Hero::full_health() {
	if (money > 150) {
		life = life_max;
		mana = mana_max;
		money -= 200;
	}
}

int Hero::returndmg1() {
	return damage1;
}

int Hero::returndmg2() {
	return damage2;
}

void Hero::life_potion() {
	if (potki_zycia !=0 && life < life_max - 30) {
		life += 30;
		potki_zycia -= 1;
		drink.play();
	}
	else if (potki_zycia != 0 && life_max > life && life >= life_max - 30) {
		life = life_max;
		potki_zycia -= 1;
		drink.play();
	}

}

void Hero::mana_potion() {
	if (potki_many !=0 && mana < mana_max - 20) {
		mana += 20;
		potki_many -= 1;
		drink.play();
	}
	else if (potki_many != 0 && mana_max > mana && mana >= mana_max - 20) {
		mana = mana_max;
		potki_many -= 1;
		drink.play();
	}

}

void Hero::weapon_change() {
	switch (nr_broni) {
	case 0:
		damage1 = 5;
		damage2 = 10;
		break;
	case 1:
		damage1 = 8;
		damage2 = 15;
		break;
	case 2:
		damage1 = 5;
		damage2 = 20;
		break;
	case 3:
		damage1 = 15;
		damage2 = 25;
		break;
	case 4:
		damage1 = 20;
		damage2 = 40;
		break;
	}
}