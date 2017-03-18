#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Options
{
public:
	sf::Sprite background;
	sf::Sprite title;
	sf::Sprite options;
	sf::Sprite full;
	sf::Sprite yes;
	sf::Sprite no;
	sf::Sprite back;

	sf::Texture tlo1;
	sf::Texture opcje;
	sf::Texture tytul;
	sf::Texture pelny;
	sf::Texture tak;
	sf::Texture nie;
	sf::Texture wstecz;

	
	Options();
	~Options();
	void draw(sf::RenderWindow &window);
};

