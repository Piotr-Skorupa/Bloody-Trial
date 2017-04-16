#include "Shop.h"



Shop::Shop()
{
	font.loadFromFile("src/Oswald-Stencil.ttf");
	cash.setFont(font);
	cash.setCharacterSize(50);
	cash.setPosition(1500,50);
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
	trzecia.loadFromFile("src/basic_sword.png");
	third.setTexture(trzecia);
	third.setPosition(70, 400);
	czwarta.loadFromFile("src/steel_sword.png");
	fourth.setTexture(czwarta);
	fourth.setPosition(70, 520);
	piata.loadFromFile("src/long_sword.png");
	fifth.setTexture(piata);
	fifth.setPosition(70, 640);
	szosta.loadFromFile("src/elven_sword.png");
	sixth.setTexture(szosta);
	siodma.loadFromFile("src/dragon_sword.png");
	seventh.setTexture(siodma);
	sixth.setPosition(70, 760);
	seventh.setPosition(70, 880);
	pieniadze.loadFromFile("src/coin.wav");
	coin.setBuffer(pieniadze);
}

void Shop::cashText(int x) {
	std::string _str = std::to_string(x);
	std::string elo = " Gold: " + _str;
	cash.setString(elo);

}


Shop::~Shop()
{
}

void Shop::draw(sf::RenderWindow &window) {
	window.draw(background);
	window.draw(arrow);
	window.draw(first);
	window.draw(second);
	window.draw(third);
	window.draw(fourth);
	window.draw(fifth);
	window.draw(sixth);
	window.draw(seventh);
	window.draw(cash);
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

void Shop::buy(Hero &h, bool x) {
	if (position == 1 && x == true && h.money >= 50) {
		h.money -= 50;
		h.potki_many += 1;
		coin.play();
	}
	if (position == 2 && x == true && h.money >= 50) {
		h.money -= 50;
		h.potki_zycia += 1;
		coin.play();
	}
	if (position == 3 && x == true ) {
		h.nr_broni = 0;
		coin.play();
	}
	if (position == 4 && x == true && h.money >= 500) {
		h.money -= 500;
		h.nr_broni = 1;
		coin.play();
	}
	if (position == 5 && x == true && h.money >= 1000) {
		h.money -= 1000;
		h.nr_broni = 2;
		coin.play();
	}
	if (position == 6 && x == true && h.money >= 2500) {
		h.money -= 2500;
		h.nr_broni = 3;
		coin.play();
	}
	if (position == 7 && x == true && h.money >= 5000) {
		h.money -= 5000;
		h.nr_broni = 4;
		coin.play();
	}
}