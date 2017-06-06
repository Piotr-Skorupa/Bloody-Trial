#include <iostream>
#include <thread>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Menu.h"
#include "Options.h"
#include "Game.h"
#include "Hero.h"
#include "Spell1.h"
#include "Shop.h"
#include "Zombie.h"
#include "Dragon.h"
#include "Ghost.h"

void attack_on(Zombie z[], Hero &h, bool &x, sf::Sound &bite, bool &g, int &stan, int &numerAtak) {
	while (g) {
		for (int i = 0; i < 20;i++) {
			if (x == true && z[i].isMoving == true && numerAtak <30) {
				h.take_dmga(z[i]._dmg, stan);
				bite.play();
				std::cout << "atakuje" << std::endl;
				x = false;
				sf::sleep(sf::milliseconds(1000));
			}
		}
	}
}

void attack_smok(Dragon &d, Hero &h, bool &x, sf::Sound &bite, bool &g, int &stan, int &numerAtak) {
	while (g) {
		
			if (x == true && d.isMoving == true && numerAtak == 30) {
				h.take_dmga(d._dmg, stan);
				bite.play();
				std::cout << "atakujesmok" << std::endl;
				x = false;
				sf::sleep(sf::milliseconds(1000));
			}
		
	}
}

void attack_duch(Ghost &d,Ghost &d2, Hero &h, bool &x, sf::Sound &bite, bool &g, int &stan, int &numerAtak) {
	while (g) {

		if (x == true && d.isMoving == true && numerAtak == 31 ) {
			h.take_dmga(d._dmg, stan);
			bite.play();
			std::cout << "atakujeduch1" << std::endl;
			x = false;
			sf::sleep(sf::milliseconds(1000));
		}
		if (x == true && d2.isMoving == true && numerAtak == 32) {
			h.take_dmga(d2._dmg, stan);
			bite.play();
			std::cout << "atakujeduch2" << std::endl;
			x = false;
			sf::sleep(sf::milliseconds(1000));
		}

	}
}



int main(void) {
	
	
	//zmienne
	const int zombie_counter = 20;
	int liczba_zombie = 23;
	int nrAtakowanego = 0;
	int stan_okna = 8;
	bool isFullscreen = false;
	bool isGamerunning = false;
	bool isFiring = false;
	bool isAttack_possible = false;
	bool isAttack = false;
	float m;
	float l;
	int kierunek_z;
	bool inshop = false;
	bool isClicked = false;
	bool isGame_End = false;
	int atak1;
	int atak2;
	bool thread_bool;

	std::thread atak_trupow;
	std::thread atak_smoka;
	std::thread atak_duchow;
		
		
	//WINDOW
	sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Bloody Trial v0.1", sf::Style::Default);
	sf::View view;
	view = window.getDefaultView();
	window.setView(view);

	thread_bool = true;

	sf::Texture intro_texture;
	sf::Sprite intro;
	intro_texture.loadFromFile("src/intro.png");
	intro.setTexture(intro_texture);
	intro.setPosition(0, 0);
	

	sf::Texture text;
	text.loadFromFile("src/sure.png");
	sf::Sprite text1;
	text1.setTexture(text);

	sf::Texture mapa;
	sf::Sprite map;
	mapa.loadFromFile("src/pruba.png");
	map.setTexture(mapa);
	map.setPosition(0, 0);
	
	sf::Texture dead;
	dead.loadFromFile("src/urdead.png");
	sf::Sprite death;
	death.setTexture(dead);
	death.setPosition(0, 0);

	Menu menu;
	Game game;
	Options options;
	Shop shop;
	Hero heros;
	Zombie z[zombie_counter];
	Ghost duch1(100,1450);
	Ghost duch2(100, 1620);
	
	Dragon smok;

	float hero_life = heros.stan_zycia();
	float hero_lifemax = heros.getLifeMax();
			
	float mana = heros.stan_many();
	float mana_max = heros.getManaMax();
	std::vector<Spell1> spellVec;

	int lvltxt = heros.getlvl();
	game.lvlText(lvltxt);
	//MUSIC (IT WORKS!)


	
	sf::SoundBuffer soundbuffer;
	sf::Sound sound;
	if (!soundbuffer.loadFromFile("src/haunt.ogg"))
	return -1; // error
	sound.setBuffer(soundbuffer);
	sound.play();

	sf::SoundBuffer buffer_win;
	sf::Sound winnig;
	if (!buffer_win.loadFromFile("src/win.wav"))
		return -1; // error
	winnig.setBuffer(buffer_win);
	
	sf::SoundBuffer strzal;
	sf::Sound ogien;
	if (!strzal.loadFromFile("src/fire.wav"))
		return -1; // error
	ogien.setBuffer(strzal);

	sf::SoundBuffer aaa;
	sf::Sound attack_air;
	if (!aaa.loadFromFile("src/atak_powietrze.wav"))
		return -1; // error
	attack_air.setBuffer(aaa);

	sf::SoundBuffer aaaa;
	sf::Sound attack_cel;
	if (!aaaa.loadFromFile("src/atak_cel.wav"))
		return -1; // error
	attack_cel.setBuffer(aaaa);

	sf::SoundBuffer sb1;
	sf::Sound gamemusic;
	if (!sb1.loadFromFile("src/Darkness.ogg"))
		return -1; // error
	gamemusic.setBuffer(sb1);
	/**/
	sf::SoundBuffer klik;
	sf::Sound click;
	if (!klik.loadFromFile("src/mouse-click.wav"))
		return -1; // error
	click.setBuffer(klik);

	
	// texty
	sf::Font font;
	font.loadFromFile("src/Oswald-Stencil.ttf");
	sf::Text enemyHP;
	enemyHP.setFont(font);
	enemyHP.setCharacterSize(25);

	sf::Text lifepots;
	lifepots.setFont(font);
	lifepots.setCharacterSize(25);

	sf::Text manapots;
	manapots.setFont(font);
	manapots.setCharacterSize(25);
	
	sf::Text you_win;
	you_win.setFont(font);
	you_win.setCharacterSize(200);
	
	

	//thready
	duch1.makethread(window.isOpen());
	for (int i = 0; i < zombie_counter; i++) {
		z[i].makethread(window.isOpen());
		sf::sleep(sf::milliseconds(100));
	}
	smok.makethread(window.isOpen());
	
	duch2.makethread(window.isOpen());

	
	atak_trupow = std::thread(&attack_on, z, std::ref(heros), std::ref(isAttack_possible), std::ref(z[0].bite), std::ref(thread_bool), std::ref(stan_okna), std::ref(nrAtakowanego));
	atak_smoka = std::thread(&attack_smok, std::ref(smok), std::ref(heros), std::ref(isAttack_possible), std::ref(z[0].bite), std::ref(thread_bool), std::ref(stan_okna), std::ref(nrAtakowanego));
	atak_duchow = std::thread(&attack_duch, std::ref(duch1), std::ref(duch2), std::ref(heros), std::ref(isAttack_possible), std::ref(z[0].bite), std::ref(thread_bool), std::ref(stan_okna), std::ref(nrAtakowanego));

	//MAIN LOOP
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			//QUIT
			if (event.type == sf::Event::Closed) {
				isGamerunning = false;
				sound.stop();
				for (int i = 0; i < zombie_counter; i++) {
					z[i].isDead = true;
					z[i].isMoving = false;
				}
				window.close();
			}
			//intro
			if (stan_okna == 8 && ( sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))) {
				stan_okna = 0;
			}
			//pozycja myszki
			sf::Vector2i& position = sf::Mouse::getPosition(window);
			//sf::Vector2i& m = menu.options.getPosition();
			std::cout << "(" << position.x << "," << position.y << ")"<<std::endl;
			
			//MENU BUTTONS
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x > 550 && position.y > 500 && position.x <790 && position.y <548 && stan_okna == 0){
				if (stan_okna == 0) {
					std::cout << "Opcje \n";
					click.play();
					stan_okna = 1;
				}
							
			}
			if (isGamerunning == false && sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x > 600 && position.y > 600 && position.x <738 && position.y <648 && stan_okna == 0) {
				isGamerunning = false;
				for (int i = 0; i < zombie_counter; i++) {
					z[i].isDead = true;
					z[i].isMoving = false;
				}
				click.play();
				sound.stop();
				window.close();

			}
			if (isGamerunning == true && sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x > 600 && position.y > 600 && position.x < 738 && position.y < 648 && stan_okna == 0) {
				stan_okna = 3;
				click.play();
			}
			//Are you sure ? (1) quit
			if (stan_okna == 3) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {
					stan_okna = 0;
					click.play();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Y)) {
					window.close();
					isGamerunning = false;
					click.play();
					for (int i = 0; i < zombie_counter; i++) {
						z[i].isDead = true;
						z[i].isMoving = false;
					}
				}
			}
			//Are you sure ? (2) new game
			if (stan_okna == 4) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {
					stan_okna = 0;
					click.play();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Y)) {
					stan_okna = 5;
					click.play();
					sound.pause();
				}
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x > 600 && position.y > 700 && position.x <738 && position.y <748 && stan_okna == 1) {
				if (stan_okna == 1) {
					std::cout << "powrot do menu \n";
					click.play();
					stan_okna = 0;
				}
			}
			//STARTING GAME
			if (isGamerunning == false && sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x > 525 && position.y > 300 && position.x < 800 && position.y < 350 && stan_okna == 0) {
				
				sound.pause();
				stan_okna = 5;
				isGamerunning = true;
				click.play();

			}
			if (isGamerunning == true && sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x > 525 && position.y > 300 && position.x < 800 && position.y < 350 && stan_okna == 0) {
				stan_okna = 4;
				click.play();
			}
			//Tutorial
			if (stan_okna == 5 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
				stan_okna = 2;
				gamemusic.play();
				heros.newgame();
				isFiring = false;
				for (int i = 0; i < zombie_counter; i++) {
					z[i].newgame();
				}
				smok.newgame();
				duch1.newgame1(100, 1450);
				duch2.newgame1(100, 1620);
				you_win.setString("");
				
			}
			//continue game
			if (isGamerunning == true && sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x > 525 && position.y > 400 && position.x < 800 && position.y < 450 && stan_okna == 0) {
				sound.pause();
				stan_okna = 2;
				click.play();
				gamemusic.play();
			}
			//SWITCHING VIDEO MODE
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x > 800 && position.y > 400 && position.x < 859 && position.y < 450 && stan_okna == 1) {
				if (isFullscreen == false) {
					window.create(desktop, "Bloody Trial v0.1", sf::Style::None);
					isFullscreen = true;
					click.play();
				}
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x > 900 && position.y > 400 && position.x < 970 && position.y < 450 && stan_okna == 1) {
				if (isFullscreen == true) {
					window.create(sf::VideoMode(1366, 768), "Bloody Trial v0.1", sf::Style::Default);
					isFullscreen = false;
					click.play();
				}
			}
			//GAME
			if ((stan_okna == 2 || stan_okna == 5 || stan_okna == 6)&& inshop == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
				stan_okna = 0;
				gamemusic.pause();
				heros.scream.pause();
				sound.play();
				
			}
			//HERO MOVING
			if (stan_okna == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
				heros.moveRight();
			}
			if (stan_okna == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
				heros.moveLeft();
			}
			if (stan_okna == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
				heros.moveUp();
			}
			if (stan_okna == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
				heros.moveDown();
			}
			if (stan_okna == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
				isFiring = true;
				}
			if (stan_okna == 2  && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
				isAttack = true;
				if (isAttack_possible == false) {
					attack_air.play();
					
				}
				else if (isAttack_possible == true) {
					if (nrAtakowanego == 30) {
						smok.take_dmg(heros.attack(), heros.money, liczba_zombie);
						attack_cel.play();
						isAttack_possible = false;
					}
					else if (nrAtakowanego == 31) {
						duch1.take_dmga(heros.attack(), heros.money, liczba_zombie);
						attack_cel.play();
						isAttack_possible = false;
					}
					else if (nrAtakowanego == 32) {
						duch2.take_dmga(heros.attack(), heros.money, liczba_zombie);
						attack_cel.play();
						isAttack_possible = false;
					}
					else {
						z[nrAtakowanego].take_dmg(heros.attack(), heros.money, liczba_zombie);
						attack_cel.play();
						isAttack_possible = false;
					}
					}
				}
			if (isClicked == false && stan_okna == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) {
				heros.life_potion();
				isClicked = true;
			}
			if (isClicked == false && stan_okna == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) {
				heros.mana_potion();
				isClicked = true;
			}
			//wejscie do sklepu
			if (heros.x > 200 && heros.x < 360 && heros.y < 104 && stan_okna == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
				stan_okna = 7;
				isClicked = true;
			}
			if (stan_okna == 7 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
				stan_okna = 2;
			}
			//sklep w srodku
			if (isClicked == false && shop.position < 7 && stan_okna == 7 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
				shop.position += 1;
				isClicked = true;
			}
			if (isClicked == false && stan_okna == 7 && shop.position > 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
				shop.position -= 1;
				isClicked = true;
			}
			if (isClicked == false && stan_okna == 7 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
				isClicked = true;
				shop.buy(heros, isClicked);
			}
			//fontanna
			if (isClicked == false && stan_okna == 2 && hero_life != hero_lifemax && heros.x > 20 && heros.x < 140 && heros.y < 500 && heros.y > 400 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
				heros.full_health();
				isClicked = true;
			}

		}

		window.clear();
		switch (stan_okna) {
		case 0:
			//main menu
			view = window.getDefaultView();
			window.setView(window.getDefaultView());
			menu.draw(window);
			break;
		case 1:
			//options
			options.draw(window);
			break;
		case 2:
			//Gameplay !!!
			window.clear();
			window.draw(map);
			// mana update
			inshop = false;
			isClicked = false;
			heros.weapon_change();
			game.check_wep(heros);
			//animation od attacking !
			if (isAttack == true) {
				if (heros.Right == true) {
					heros.rect.top = 0;
					heros.rect.left = 400;
					if (heros.clock.getElapsedTime().asSeconds() > 0.2f) {
						if (heros.rect.left == 500)
							heros.rect.left = 400;
						else
							heros.rect.left += 100;

						heros.hero.setTextureRect(heros.rect);
						heros.clock.restart();
						isAttack = false;
						
					}
				}
				if (heros.Left == true) {
					heros.rect.top = 0;
					heros.rect.left = 300;
					if (heros.clock.getElapsedTime().asSeconds() > 0.2f) {
						if (heros.rect.left == 200)
							heros.rect.left = 300;
						else
							heros.rect.left -= 100;

						heros.hero.setTextureRect(heros.rect);
						heros.clock.restart();
						isAttack = false;
					}
				}
				
			}
			else {
				heros.rect.top = 100;
				
			}

			atak1 = heros.returndmg1();
			atak2 = heros.returndmg2();
			game.dmgTxt(atak1, atak2);

			mana = heros.stan_many();
			mana_max = heros.getManaMax();
			
			m = (mana / mana_max) * 100;
			
			if (m > 90) game.mana.setTexture(game.czar);
			else if (90 > m && m > 60)  game.mana.setTexture(game.czar075);
			else if (60 > m && m > 35) game.mana.setTexture(game.czar05);
			else if (35 > m && m > 10) game.mana.setTexture(game.czar025);
			else if (m == 0 ) game.mana.setTexture(game.czar0);
			
			// life update 
			hero_life = heros.stan_zycia();
			hero_lifemax = heros.getLifeMax();

			l = (hero_life / hero_lifemax) * 100;

			if (l > 90) game.life.setTexture(game.zycie);
			else if (90 > l && l > 60)  game.life.setTexture(game.zycie075);
			else if (60 > l && l > 35) game.life.setTexture(game.zycie05);
			else if (35 > l && l > 10) game.life.setTexture(game.zycie025);
			else if (l < 10) game.life.setTexture(game.zycie0);

			// widoki i update sprite'ow
			view.setCenter(heros.x, heros.y);
			window.setView(view);
			heros.lifetexty();
			game.cashText(heros.money);
			game.pot1Txt(heros.potki_zycia);
			game.pot2Txt(heros.potki_many);
			game.cash.setPosition(heros.x - 860, heros.y + 480);
			game.label.setPosition(heros.x - 960, heros.y + 350);
			game.life.setPosition(heros.x - 860, heros.y +350);
			game.mana.setPosition(heros.x - 860, heros.y + 400);
			game.level.setPosition(heros.x - 650, heros.y + 390);
			game.pot1.setPosition(heros.x - 550, heros.y + 390);
			game.p1.setPosition(heros.x - 470, heros.y + 390);
			game.pot2.setPosition(heros.x - 430, heros.y + 390);
			game.p2.setPosition(heros.x - 350, heros.y + 390);
			game.weapon.setPosition(heros.x - 300, heros.y + 390);
			game.damage.setPosition(heros.x - 200, heros.y + 420);
			heros.zyc.setPosition(heros.x - 840, heros.y + 360);
			heros.man.setPosition(heros.x - 840, heros.y + 410);
			enemyHP.setPosition(heros.x, heros.y - 500);
			you_win.setPosition(heros.x - 300, heros.y - 200);
			
			//koniec gry
			if (liczba_zombie == 0 && isGame_End == false) {
				you_win.setString("You win !");
				winnig.play();
				isGame_End = true;
			}
			
			// kolizja gracza z zombie (czy moga zaatakowac ? )
			for (int i = 0; i < zombie_counter; i++) {
				if (abs(heros.hero.getPosition().x - z[i].zombi.getPosition().x) < 90 && abs(heros.hero.getPosition().y - z[i].zombi.getPosition().y) < 90 && z[i].isDead == false) {
					isAttack_possible = true;
					nrAtakowanego = i;
					enemyHP.setString("enemy hp: " + z[i].hptext());

				}
				
			}
			if (abs(heros.hero.getPosition().x - smok.dragon.getPosition().x) < 90 && abs(heros.hero.getPosition().y - smok.dragon.getPosition().y) < 90 && smok.isDead == false) {
					isAttack_possible = true;
					nrAtakowanego = 30;
					enemyHP.setString("enemy hp: " + smok.hptext());

				}
			if (abs(heros.hero.getPosition().x - duch1.zombi.getPosition().x) < 90 && abs(heros.hero.getPosition().y - duch1.zombi.getPosition().y) < 90 && duch1.isDead == false) {
				isAttack_possible = true;
				nrAtakowanego = 31;
				enemyHP.setString("enemy hp: " + duch1.hptexta());

			}
			if (abs(heros.hero.getPosition().x - duch2.zombi.getPosition().x) < 90 && abs(heros.hero.getPosition().y - duch2.zombi.getPosition().y) < 90 && duch2.isDead == false) {
				isAttack_possible = true;
				nrAtakowanego = 32;
				enemyHP.setString("enemy hp: " + duch2.hptexta());

			}
			//shop
			if (heros.x > 200 && heros.x < 360 && heros.y < 104) {
				enemyHP.setString("Enter to the Shop");
			}
			// fontanna
			if (heros.x > 20 && heros.x < 140 && heros.y < 500 && heros.y > 400) {
				enemyHP.setString("Full Health (200 glod)");
			}
			for (int i = 0; i < zombie_counter; i++) {
				if (z[i].isDead == false) {
					z[i].zombi.setTexture(z[i].trup);
				}
			}

			for (int i = 0; i < zombie_counter; i++) {
				z[i].draw(window);
			}
			
			window.draw(smok.dragon);
			duch1.draw(window);
			duch2.draw(window);
			game.draw(window);
			window.draw(heros.zyc);
			window.draw(heros.man);
			window.draw(heros.hero);
			window.draw(enemyHP);
			window.draw(you_win);
			if (isFiring == true && mana > 9 ) {
				Spell1 newSpell;
				newSpell.setPos(heros.x - 25, heros.y - 25);
				// kierunek czaru
				if (heros.left == true) newSpell.spell_left = true;
				if (heros.right == true) newSpell.spell_right = true;
				if (heros.down == true) newSpell.spell_down = true;
				if (heros.up == true) newSpell.spell_up = true;
				spellVec.push_back(newSpell);
				isFiring = false;
				heros.stratamany(newSpell.cost);
				ogien.play();
			}
			else isFiring = false;
						
			for (int i = 0; i < spellVec.size(); i++) {
				if (spellVec[i].isShooted == false) {
					spellVec[i].setTex();
					spellVec[i].draw(window);
					spellVec[i].shoot(2);
					for (int j = 0; j < zombie_counter; j++) {
						if (abs(spellVec[i].bolt.getPosition().x - z[j].zombi.getPosition().x) < 80 && abs(spellVec[i].bolt.getPosition().y - z[j].zombi.getPosition().y) < 80 && z[j].isDead == false) {
							z[j].take_dmg(spellVec[i].dmg, heros.money, liczba_zombie);
							spellVec[i].isShooted = true;
						}
					}
					if (abs(spellVec[i].bolt.getPosition().x - smok.dragon.getPosition().x) < 180 && abs(spellVec[i].bolt.getPosition().y - smok.dragon.getPosition().y) < 180 && smok.isDead == false) {
						smok.take_dmg(spellVec[i].dmg, heros.money, liczba_zombie);
						spellVec[i].isShooted = true;
					}
					if (abs(spellVec[i].bolt.getPosition().x - duch1.zombi.getPosition().x) < 80 && abs(spellVec[i].bolt.getPosition().y - duch1.zombi.getPosition().y) < 80 && duch1.isDead == false) {
						duch1.take_dmga(spellVec[i].dmg, heros.money, liczba_zombie);
						spellVec[i].isShooted = true;
					}
					if (abs(spellVec[i].bolt.getPosition().x - duch2.zombi.getPosition().x) < 80 && abs(spellVec[i].bolt.getPosition().y - duch2.zombi.getPosition().y) < 80 && duch2.isDead == false) {
						duch2.take_dmga(spellVec[i].dmg, heros.money, liczba_zombie);
						spellVec[i].isShooted = true;
					}
					
				}
			}
			enemyHP.setString("");
			break;
		case 3:
			//are you sure?
			window.clear(sf::Color::Black);
			if (isFullscreen == false) {
				text1.setPosition(50, 300);
			}
			else if (isFullscreen == true) {
				text1.setPosition(320, 500);
			}
			window.draw(text1);
			break;
		case 4:
			//are you sure?
			window.clear(sf::Color::Black);
			if (isFullscreen == false) {
				text1.setPosition(50, 300);
			}
			else if (isFullscreen == true) {
				text1.setPosition(320, 500);
			}
			window.draw(text1);
			break;
		case 5:
			//newgame tutorial
			game.tutorial(window, isFullscreen);
			break;
		case 6:
			//smierc
			view = window.getDefaultView();
			window.setView(window.getDefaultView());
			isGamerunning = false;
			window.clear();
			window.draw(death);
			break;
		case 7:
			//sklep
			window.clear();
			isClicked = false;
			shop.cashText(heros.money);
			shop.choice();
			view = window.getDefaultView();
			window.setView(window.getDefaultView());
			shop.draw(window);
			inshop = true;
			break;
		case 8:
			window.clear();
			window.draw(intro);
			break;
		}
		
		window.display();
		
	}
	thread_bool = false;
	atak_trupow.join();
	atak_smoka.join();
	atak_duchow.join();
	return 0;
}

