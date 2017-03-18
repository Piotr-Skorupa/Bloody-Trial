#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Menu
{
public:
	sf::Sprite background;
	sf::Sprite title;
	sf::Sprite newgame;
	sf::Sprite continue1;
	sf::Sprite options;
	sf::Sprite escape;
	sf::Texture tlo1;
	sf::Texture tytul;
	sf::Texture newgam;
	sf::Texture kontyn;
	sf::Texture opcje;
	sf::Texture koniec;
	Menu();
	~Menu();

	void draw(sf::RenderWindow &window);

private:


};
