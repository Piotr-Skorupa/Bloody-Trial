#include "Shop.h"



Shop::Shop()
{
	back.loadFromFile("src/shop_inside.png");
	background.setTexture(back);
	background.setPosition(0, 0);
	wskaznik.loadFromFile("src/strzalka.png");
	arrow.setTexture(wskaznik);
	position = 1;
	arrow.setPosition(1350, 160);
	pierwsza.loadFromFile("src/mana_pot.png");
	druga.loadFromFile("src/life_pot.png");
	first.setTexture(pierwsza);
	second.setTexture(druga);
	first.setPosition(70, 160);
	second.setPosition(70, 290);
}


Shop::~Shop()
{
}

void Shop::draw(sf::RenderWindow &window) {
	window.draw(background);
	window.draw(arrow);
	window.draw(first);
	window.draw(second);
}
void Shop::choice() {
	
	if (position == 1) arrow.setPosition(1350, 160);
	else if (position == 2) arrow.setPosition(1350, 280);
	else if (position == 3) arrow.setPosition(1350, 400);
	else if (position == 4) arrow.setPosition(1350, 530);
	else if (position == 5) arrow.setPosition(1350, 630);
	else if (position == 6) arrow.setPosition(1350, 750);
	else if (position == 7) arrow.setPosition(1350, 870);
}