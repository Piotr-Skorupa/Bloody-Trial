#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <ctime>
#include <iostream>
#include <thread>
#include "Hero.h"

class Dragon
{
private:
	int _hp;
	std::thread z_thread;

public:
	sf::SoundBuffer pain;
	sf::Sound getHit;
	sf::SoundBuffer atakasz;
	sf::Sound bite;
	int x;
	int y;
	int _dmg;
	int kierunek_z;
	bool isMoving;
	bool isDead;
	sf::Texture smok;
	sf::Sprite dragon;
	sf::Texture dead;

	Dragon();
	~Dragon();
	void take_dmg(int a, int &b, int &c);
	void move(bool g);
	void makethread(bool g);
	std::string hptext();
	void newgame();
};

