#include "Game.h"



Game::Game()
{
	font.loadFromFile("src/Oswald-Stencil.ttf");
	t1.loadFromFile("src/tutorial1.png");
	t2.loadFromFile("src/tutorial2.png");
	tutorial1.setTexture(t1);
	tutorial2.setTexture(t2);
	tutorial1.setPosition(0, 0);
	tutorial2.setPosition(0, 0);
	zycie.loadFromFile("src/zycie.png");
	czar.loadFromFile("src/mana.png");
	czar075.loadFromFile("src/mana075.png");
	czar05.loadFromFile("src/mana05.png");
	czar025.loadFromFile("src/mana025.png");
	czar0.loadFromFile("src/mana0.png");
	life.setTexture(zycie);
	mana.setTexture(czar);
	level.setFont(font);
	level.setCharacterSize(34);
	pasek.loadFromFile("src/pasek.png");
	label.setTexture(pasek);
	cash.setFont(font);
	cash.setCharacterSize(28);
	
}


Game::~Game()
{
}

void Game::tutorial(sf::RenderWindow &window, bool f) {
	if (f == true) {
		window.draw(tutorial1);
		
	}
	else if (f == false) {
		window.draw(tutorial2);
	}
	
}

void Game::draw(sf::RenderWindow &window) {
	
	window.draw(label);
	window.draw(life);
	window.draw(level);
	window.draw(mana);
	window.draw(cash);

}

void Game::lvlText(int x) {
	std::string _str = std::to_string(x);
	std::string elo = " lvl " + _str ;
	level.setString(elo);

}

void Game::cashText(int x) {
	std::string _str = std::to_string(x);
	std::string elo = " Gold: " + _str;
	cash.setString(elo);

}
