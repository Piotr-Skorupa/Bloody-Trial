#include "Zombie.h"



Zombie::Zombie()
{

	_hp = 30;
	_dmg = 5;
	x = 500 + (std::rand() % (3500 - 500 + 1));
	y = 600 + (std::rand() % (1850 - 600 + 1));
	isMoving = true;
	isDead = false;
	trup.loadFromFile("src/zombie.png");
	dead.loadFromFile("src/zombie_trup.png");
	zombi.setTexture(trup);
	zombi.setPosition(x, y);

}



void Zombie::draw(sf::RenderWindow &window) {
	window.draw(zombi);
}

void Zombie::take_dmg(int& a) {
	_hp -= a;
	if (_hp <= 0) {
		isDead = true;
		isMoving = false;
		zombi.setTexture(dead);
	}
}

int Zombie::attack() {
	return _dmg;
}

void Zombie::moveLeft() {
	int bb = 1 + (std::rand() % (3 - 1 + 1));
	if (isMoving == true && bb == 1) {
		zombi.move(-5, 0);
	}
	if (isMoving == true && bb == 2) {
		zombi.move(-5, 0);
		zombi.move(-5, 0);
		
	}
	if (isMoving == true && bb == 3) {
		zombi.move(-5, 0);
		zombi.move(-5, 0);
		zombi.move(-5, 0);
	}
}
void Zombie::moveRight() {
	int bb = 1 + (std::rand() % (3 - 1 + 1));
	if (isMoving == true && bb == 1) {
		zombi.move(5, 0);
	}
	if (isMoving == true && bb == 2) {
		zombi.move(5, 0);
		zombi.move(5, 0);

	}
	if (isMoving == true && bb == 3) {
		zombi.move(5, 0);
		zombi.move(5, 0);
		zombi.move(5, 0);
	}
}
void Zombie::moveUp() {
	int bb = 1 + (std::rand() % (3 - 1 + 1));
	if (isMoving == true && bb == 1) {
		zombi.move(0, -5);
	}
	if (isMoving == true && bb == 2) {
		zombi.move(0, -5);
		zombi.move(0, -5);

	}
	if (isMoving == true && bb == 3) {
		zombi.move(0, -5);
		zombi.move(0, -5);
		zombi.move(0, -5);
	}
}
void Zombie::moveDown() {
	int bb = 1 + (std::rand() % (3 - 1 + 1));
	if (isMoving == true && bb == 1) {
		zombi.move(0, 5);
	}
	if (isMoving == true && bb == 2) {
		zombi.move(0, 5);
		zombi.move(0, 5);

	}
	if (isMoving == true && bb == 3) {
		zombi.move(0, 5);
		zombi.move(0, 5);
		zombi.move(0, 5);
	}
}

Zombie::~Zombie()
{
}
