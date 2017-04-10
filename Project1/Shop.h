#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Hero.h"

class Shop
{
public:
	sf::Texture back;
	sf::Sprite background;
	sf::Texture wskaznik;
	sf::Sprite arrow;
	sf::Texture pierwsza;
	sf::Sprite first;
	sf::Texture druga;
	sf::Sprite second;
	int position;

	Shop();
	~Shop();
	void draw(sf::RenderWindow &window);
	void choice();
};

