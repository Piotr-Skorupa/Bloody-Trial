#include "Options.h"



Options::Options()
{
	tlo1.loadFromFile("src/btback.jpg");
	background.setTexture(tlo1);
	background.setPosition(0, 0);
	tytul.loadFromFile("src/title.png");
	title.setTexture(tytul);
	title.setPosition(250, 30);
	opcje.loadFromFile("src/options.png");
	options.setTexture(opcje);
	options.setPosition(550, 300);

	pelny.loadFromFile("src/fullscreen.png");
	full.setTexture(pelny);
	full.setPosition(450, 400);
	tak.loadFromFile("src/on.png");
	yes.setTexture(tak);
	yes.setPosition(800, 400);
	nie.loadFromFile("src/off.png");
	no.setTexture(nie);
	no.setPosition(900, 400);
	wstecz.loadFromFile("src/back.png");
	back.setTexture(wstecz);
	back.setPosition(600, 700);
}


Options::~Options()
{
}

void Options::draw(sf::RenderWindow &window) {

	window.draw(background);
	window.draw(title);
	window.draw(options);
	window.draw(full);
	window.draw(yes);
	window.draw(no);
	window.draw(back);
}