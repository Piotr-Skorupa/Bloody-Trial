#include "Spell1.h"



Spell1::Spell1()
{
	dmg = 15;
	cost = 10;
	spell_left = false;
	spell_right = false;
	spell_up = false;
	spell_down = false;
	isShooted = false;
	fire.loadFromFile("src/fire.png");
	bolt.setTexture(fire);

}
void Spell1::setTex() {
	bolt.setTexture(fire);
	
}


Spell1::~Spell1()
{
}

void Spell1::setPos(int x, int y) {
	bolt.setPosition(x + 100, y + 40);
}

void Spell1::shoot(int speed) {
	if (spell_right == true) {
		bolt.move(speed, 0);
	}
	if (spell_left == true) {
		bolt.setRotation(180);
		bolt.move(-speed, 0);
	}
	if (spell_down == true) {
		bolt.setRotation(90);
		bolt.move(0, speed);
	}
	if (spell_up == true) {
		bolt.setRotation(270);
		bolt.move(0, -speed);
	}
}

void Spell1::draw(sf::RenderWindow &window) {
	window.draw(bolt);
}