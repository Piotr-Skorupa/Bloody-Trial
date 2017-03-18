#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Spell1
{
public:
	
	int dmg;
	int cost; // mana lost
	bool spell_left = false;
	bool spell_right = false;
	bool spell_up = false;
	bool spell_down = false;
	
	Spell1();
	~Spell1();
	void setTex();
	void setPos(int x, int y);
	void shoot(int speed);
	void draw(sf::RenderWindow &window);
	
private:
	sf::Texture fire;
	sf::Sprite bolt;
};

