#include "Menu.h"


Menu::Menu() {
	//SPRITES
	tlo1.loadFromFile("src/btback.jpg");
	background.setTexture(tlo1);
	background.setPosition(0, 0);
	
	tytul.loadFromFile("src/title.png");
	title.setTexture(tytul);
	title.setPosition(250, 30);
	
	newgam.loadFromFile("src/new.png");
	newgame.setTexture(newgam);
	newgame.setPosition(525, 300);
	
	kontyn.loadFromFile("src/continue.png");
	continue1.setTexture(kontyn);
	continue1.setPosition(525, 400);
	
	opcje.loadFromFile("src/options.png");
	options.setTexture(opcje);
	options.setPosition(550, 500);
	
	koniec.loadFromFile("src/quit.png");
	escape.setTexture(koniec);
	escape.setPosition(600, 600);
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow &window){ 
	window.draw(background);
	window.draw(title);
	window.draw(newgame);
	window.draw(continue1);
	window.draw(options);
	window.draw(escape);
}