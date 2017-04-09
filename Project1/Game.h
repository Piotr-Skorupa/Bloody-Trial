#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game
{
public:
	sf::Texture t1;
	sf::Texture t2;
	sf::Sprite tutorial1;
	sf::Sprite tutorial2;
	sf::Texture zycie;
	sf::Texture zycie075;
	sf::Texture zycie05;
	sf::Texture zycie025;
	sf::Texture zycie0;
	sf::Sprite life;
	sf::Texture czar;
	sf::Texture czar075;
	sf::Texture czar05;
	sf::Texture czar025;
	sf::Texture czar0;
	sf::Sprite mana;
	sf::Font font;
	sf::Text level;
	sf::Texture pasek;
	sf::Sprite label;
	sf::Text cash;

	Game();
	~Game();
	void draw(sf::RenderWindow &window);
	void tutorial(sf::RenderWindow &window, bool f);
	void lvlText(int x);
	void cashText(int x);
	
};

