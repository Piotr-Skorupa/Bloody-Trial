#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <ctime>

class Zombie
{
private:
	int _hp;
	int _dmg;
	int x;
	int y;
	

public:
	bool isMoving;
	bool isDead;
	sf::Texture trup;
	sf::Sprite zombi;
	sf::Texture dead;
	
	Zombie();
	~Zombie();
	void draw(sf::RenderWindow &window);
	void take_dmg(int& a);
	int attack(void);
};

