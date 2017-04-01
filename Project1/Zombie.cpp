#include "Zombie.h"



Zombie::Zombie()
{

	_hp = 30;
	_dmg = 5;
	x = 500 + (std::rand() % (3500 - 500 + 1));
	y = 700 + (std::rand() % (1850 - 600 + 1));
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

int Zombie::attack(void) {
	return _dmg;
}

Zombie::~Zombie()
{
}
