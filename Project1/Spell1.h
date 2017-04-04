#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Spell1
{
public:
	
	int dmg;
	int cost; // mana lost
	bool spell_left;
	bool spell_right;
	bool spell_up;
	bool spell_down;
	bool isShooted;
	sf::Texture fire;
	sf::Sprite bolt;

	Spell1();
	~Spell1();
	void setTex();
	void setPos(int x, int y);
	void shoot(int speed);
	void draw(sf::RenderWindow &window);
	

	
};

