#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Zombie
{
private:
	int _hp;
	int _dmg;
	int x;
	int y;
	

public:
	bool isMoving;
	sf::Texture trup;
	sf::Sprite zombi;
	Zombie();
	~Zombie();
};

