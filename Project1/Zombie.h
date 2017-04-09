#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <ctime>
#include <iostream>
#include <thread>
#include "Hero.h"

class Zombie
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
	sf::Texture trup;
	sf::Sprite zombi;
	sf::Texture dead;
	int hajs;
	
	Zombie();
	~Zombie();
	void draw(sf::RenderWindow &window);
	void take_dmg(int a, int &b);
	void attack(Hero &a, bool &x);
	void move(bool g);
	void makethread(bool g);
	std::string hptext();
	int get_money();
	void newgame();
	
};

