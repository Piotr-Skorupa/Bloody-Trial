#include "Zombie.h"



Zombie::Zombie()
{
	_hp = 30;
	_dmg = 5;
	x = 700;
	y = 400;
	isMoving = true;
	trup.loadFromFile("src/zombie.png");
	zombi.setTexture(trup);
	zombi.setPosition(x, y);

}

void Zombie::draw(sf::RenderWindow &window) {
	window.draw(zombi);
}

Zombie::~Zombie()
{
}
