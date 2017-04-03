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
#include "Stats.h"
#include "Zombie.h"

void thread_func1(Zombie &z, int &kierunek_z, int &zombieAlive) {
	while (zombieAlive != 0 ) {
		kierunek_z = 1 + (std::rand() % (4 - 1 + 1));
		if (kierunek_z == 1) z.moveLeft();
		if (kierunek_z == 2) z.moveRight();
		if (kierunek_z == 3) z.moveUp();
		if (kierunek_z == 4) z.moveDown();
		sf::sleep(sf::milliseconds(100));
	}
}


int main(void) {
	
	//zmienne
	const int zombie_counter = 20;
	int nrAtakowanego = 0;
	int stan_okna = 0;
	bool isFullscreen = false;
	bool isGamerunning = false;
	bool isFiring = false;
	bool isAttack_possible = false;
	float m;
	int kierunek_z;
	sf::Time time;
	std::thread zombie_thread[zombie_counter];
		
	
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
	

	Menu menu;
	Game game;
	Options options;
	Hero heros;
	Zombie z[zombie_counter];
		
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

	sf::SoundBuffer krzyk;
	sf::Sound scream;
	if (!krzyk.loadFromFile("src/scream.wav"))
		return -1; // error
	scream.setBuffer(krzyk);

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
				scream.play();
				stan_okna = 2;
				gamemusic.play();
				heros.newgame();
				isFiring = false;
				
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
			if ((stan_okna == 2 || stan_okna == 5) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
				stan_okna = 0;
				gamemusic.pause();
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
				if (isAttack_possible == false) { attack_air.play(); }
				else if (isAttack_possible == true) {
					z[nrAtakowanego].take_dmg(heros.attack());
					attack_cel.play();
					isAttack_possible = false;
					}
				}

		}

		window.clear();
		switch (stan_okna) {
		case 0:
			view = window.getDefaultView();
			window.setView(window.getDefaultView());
			menu.draw(window);
			break;
		case 1:
			options.draw(window);
			break;
		case 2:
			window.clear();
			window.draw(map);
			mana = heros.stan_many();
			mana_max = heros.getManaMax();
			m = (mana / mana_max) * 100;
			//proba watku
			/*
			for (int i = 0; i < zombie_counter; i++) {
				zombie_thread[i] = std::thread(&thread_func1, std::ref(z[i]), std::ref(kierunek_z), std::ref(zombie_counter));
				
			}
			for (int i = 0; i < zombie_counter; i++) {
				zombie_thread[i].join();
			}
			*/
			

			if (m > 90) game.mana.setTexture(game.czar);
			else if (90 > m && m > 60)  game.mana.setTexture(game.czar075);
			else if (60 > m && m > 35) game.mana.setTexture(game.czar05);
			else if (35 > m && m > 10) game.mana.setTexture(game.czar025);
			else if (m == 0 ) game.mana.setTexture(game.czar0);
						
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
			

			//poruszanie sie zombie
			/*
			for (int i = 0; i < zombie_counter ; i++) {
				kierunek_z = 1 + (std::rand() % (4 - 1 + 1));
				if (kierunek_z == 1) z[i].moveLeft();
				if (kierunek_z == 2) z[i].moveRight();
				if (kierunek_z == 3) z[i].moveUp();
				if (kierunek_z == 4) z[i].moveDown();
				z[i].draw(window);
								
			}*/

			// kolizja gracza z zombie (czy moga zaatakowac ? )
			for (int i = 0; i < zombie_counter; i++) {
				if (abs(heros.hero.getPosition().x - z[i].zombi.getPosition().x) < 90 && abs(heros.hero.getPosition().y - z[i].zombi.getPosition().y) < 90 && z[i].isDead == false) {
					heros.take_dmg(z[i].attack());
					isAttack_possible = true;
					nrAtakowanego = i;

				}
				
			}
			
			for (int i = 0; i < zombie_counter; i++) {
				z[i].draw(window);
			}
			game.draw(window);
			window.draw(heros.zyc);
			window.draw(heros.man);
			window.draw(heros.hero);
			if (isFiring == true && mana > 9 ) {
				Spell1 newSpell;
				newSpell.setPos(heros.x + 25, heros.y - 25);
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
				
				spellVec[i].setTex();
				spellVec[i].draw(window);
				spellVec[i].shoot(1);					
			}
			
			break;
		case 3:
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
			game.tutorial(window, isFullscreen);
			break;
		}
		
		window.display();
		
	}
	
	return 0;
}

