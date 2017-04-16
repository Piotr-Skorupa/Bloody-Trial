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
	sf::Texture trzecia;
	sf::Sprite third;
	sf::Texture czwarta;
	sf::Texture piata;
	sf::Texture szosta;
	sf::Texture siodma;
	sf::Sprite fourth;
	sf::Sprite fifth;
	sf::Sprite sixth;
	sf::Sprite seventh;
	sf::Text cash;
	sf::Font font;
	sf::SoundBuffer pieniadze;
	sf::Sound coin;

	int position;

	Shop();
	~Shop();
	void draw(sf::RenderWindow &window);
	void choice();
	void cashText(int x);
	void buy(Hero &h, bool x);
	
};

