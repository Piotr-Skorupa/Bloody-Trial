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
	
	

public:
	int x;
	int y;
	int kierunek_z;
	bool isMoving;
	bool isDead;
	sf::Texture trup;
	sf::Sprite zombi;
	sf::Texture dead;
	
	Zombie();
	~Zombie();
	void draw(sf::RenderWindow &window);
	void take_dmg(int a);
	int attack();
	void move();
	
};

