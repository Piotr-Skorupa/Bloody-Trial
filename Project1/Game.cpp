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
	zycie075.loadFromFile("src/zycie075.png");
	zycie05.loadFromFile("src/zycie05.png");
	zycie025.loadFromFile("src/zycie025.png");
	zycie0.loadFromFile("src/zycie0.png");
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
	potman.loadFromFile("src/mana_pot.png");
	potlif.loadFromFile("src/life_pot.png");
	bron1.loadFromFile("src/basic_sword.png");
	bron2.loadFromFile("src/steel_sword.png");
	bron3.loadFromFile("src/long_sword.png");
	bron4.loadFromFile("src/elven_sword.png");
	bron5.loadFromFile("src/dragon_sword.png");
	weapon.setTexture(bron1);
	pot1.setTexture(potlif);
	pot2.setTexture(potman);
	p1.setFont(font);
	p1.setCharacterSize(28);
	p2.setFont(font);
	p2.setCharacterSize(28);
	damage.setFont(font);
	damage.setCharacterSize(24);
	
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
	window.draw(pot1);
	window.draw(pot2);
	window.draw(p1);
	window.draw(p2);
	window.draw(weapon);
	window.draw(damage);

}

void Game::dmgTxt(int x, int y) {
	std::string _str = std::to_string(x);
	std::string _str2 = std::to_string(y);
	std::string elo = " Damage : " + _str + " - " + _str2;
	damage.setString(elo);
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

void Game::pot1Txt(int x) {
	std::string _str = std::to_string(x);
	p1.setString(_str);
}

void Game::pot2Txt(int x) {
	std::string _str = std::to_string(x);
	p2.setString(_str);
}

void Game::check_wep(Hero &h) {
	if (h.nr_broni == 0) {
		weapon.setTexture(bron1);
	}
	else if (h.nr_broni == 1) {
		weapon.setTexture(bron2);
	}
	else if (h.nr_broni == 2) {
		weapon.setTexture(bron3);
	}
	else if (h.nr_broni == 3) {
		weapon.setTexture(bron4);
	}
	else if (h.nr_broni == 4) {
		weapon.setTexture(bron5);
	}
}