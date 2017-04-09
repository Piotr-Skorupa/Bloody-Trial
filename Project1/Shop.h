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
	sf::Sprite Arrow;

	Shop();
	~Shop();
	void draw(sf::RenderWindow &window);
};

