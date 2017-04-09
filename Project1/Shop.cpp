#include "Shop.h"



Shop::Shop()
{
	back.loadFromFile("src/shop_inside.png");
	background.setTexture(back);
	background.setPosition(0, 0);
}


Shop::~Shop()
{
}

void Shop::draw(sf::RenderWindow &window) {
	window.draw(background);
}
