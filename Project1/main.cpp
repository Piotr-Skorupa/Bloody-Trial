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

void attack_on(Zombie z[], Hero &h, bool &x, sf::Sound &bite, bool g, int &stan) {
	while (g) {
		for (int i = 0; i < 20;i++) {
			if (x == true && z[i].isMoving == true) {
				h.take_dmga(z[i]._dmg, stan);
				bite.play();
				std::cout << "atakuje" << std::endl;
				x = false;
				sf::sleep(sf::milliseconds(1000));
			}
		}
	}
}



int main(void) {
	
	
	//zmienne
	const int zombie_counter = 20;
	int liczba_zombie;
	int nrAtakowanego = 0;
	int stan_okna = 0;
	bool isFullscreen = false;
	bool isGamerunning = false;
	bool isFiring = false;
	bool isAttack_possible = false;
	float m;
	float l;
	int kierunek_z;
	bool inshop = false;
	bool isClicked = false;
	

	std::thread atak_trupow;
	
		
		
	//WINDOW
	sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Bloody Trial v0.1", sf::Style::Default);
	sf::View view;
	view = window.getDefaultView();
	window.setView(view);


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
	
	
	//thready

	for (int i = 0; i < zombie_counter; i++) {
		z[i].makethread(window.isOpen());
		sf::sleep(sf::milliseconds(100));
	}
	
	atak_trupow = std::thread(&attack_on, z, std::ref(heros), std::ref(isAttack_possible), std::ref(z[0].bite), window.isOpen(), std::ref(stan_okna));
	

	//MAIN LOOP
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			//QUIT
			if (event.type == sf::Event::Closed) {
				window.close();
				isGamerunning = false;
				for (int i = 0; i < zombie_counter; i++) {
					z[i].isDead = true;
					z[i].isMoving = false;
				}
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
				if (stan_okna == 0)	window.close();
				isGamerunning = false;
				for (int i = 0; i < zombie_counter; i++) {
					z[i].isDead = true;
					z[i].isMoving = false;
				}
				click.play();

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
				if (isAttack_possible == false) {
					attack_air.play();
					
				}
				else if (isAttack_possible == true) {
					z[nrAtakowanego].take_dmg(heros.attack(), heros.money);
					attack_cel.play();
					isAttack_possible = false;

					}
				}
			//wejscie do sklepu
			if (heros.x > 200 && heros.x < 360 && heros.y < 104 && stan_okna == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
				stan_okna = 7;
			}
			if (stan_okna == 7 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
				stan_okna = 2;
			}
			//sklep w srodku
			if (isClicked == false && shop.position < 7 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
				shop.position += 1;
				isClicked = true;
			}
			if (isClicked == false && shop.position > 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
				shop.position -= 1;
				isClicked = true;
			}
			//fontanna
			if (isClicked == false && hero_life != hero_lifemax && heros.x > 20 && heros.x < 140 && heros.y < 500 && heros.y > 400 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
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
			game.cash.setPosition(heros.x - 860, heros.y + 480);
			game.label.setPosition(heros.x - 960, heros.y + 350);
			game.life.setPosition(heros.x - 860, heros.y +350);
			game.mana.setPosition(heros.x - 860, heros.y + 400);
			game.level.setPosition(heros.x - 650, heros.y + 390);
			heros.zyc.setPosition(heros.x - 840, heros.y + 360);
			heros.man.setPosition(heros.x - 840, heros.y + 410);
			enemyHP.setPosition(heros.x, heros.y - 500);
			
			
			// kolizja gracza z zombie (czy moga zaatakowac ? )
			for (int i = 0; i < zombie_counter; i++) {
				if (abs(heros.hero.getPosition().x - z[i].zombi.getPosition().x) < 90 && abs(heros.hero.getPosition().y - z[i].zombi.getPosition().y) < 90 && z[i].isDead == false) {
					isAttack_possible = true;
					nrAtakowanego = i;
					enemyHP.setString("enemy hp: " + z[i].hptext());

				}
				
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
			
			game.draw(window);
			window.draw(heros.zyc);
			window.draw(heros.man);
			window.draw(heros.hero);
			window.draw(enemyHP);
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
					spellVec[i].shoot(1);
					for (int j = 0; j < zombie_counter; j++) {
						if (abs(spellVec[i].bolt.getPosition().x - z[j].zombi.getPosition().x) < 80 && abs(spellVec[i].bolt.getPosition().y - z[j].zombi.getPosition().y) < 80 && z[j].isDead == false) {
							z[j].take_dmg(spellVec[i].dmg, heros.money);
							spellVec[i].isShooted = true;
						}
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
			shop.choice();
			isClicked = false;
			view = window.getDefaultView();
			window.setView(window.getDefaultView());
			shop.draw(window);
			inshop = true;
			break;
		}
		
		window.display();
		
	}
	atak_trupow.join();
	return 0;
}

