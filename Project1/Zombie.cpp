#include "Zombie.h"



Zombie::Zombie()
{
	_hp = 30;
	_dmg = 5;
	x = 400;
	y = 200;
	isMoving = true;
	trup.loadFromFile("src/zombie.png");
	zombi.setTexture(trup);
	zombi.setPosition(x, y);

}


Zombie::~Zombie()
{
}
