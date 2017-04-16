#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Hero
{
public:
	int potki_zycia;
	int potki_many;
	int money;
	int nr_broni;
	bool isMoving;
	bool up;
	bool down;
	bool left;
	bool right;
	int speed;
	int x;
	int y;
	sf::Texture ziomek;
	sf::Sprite hero;
	sf::Font font;
	sf::Text zyc;
	sf::Text man;
	sf::SoundBuffer krzyk;
	sf::Sound scream;
	sf::SoundBuffer picie;
	sf::Sound drink;
	


	Hero();
	~Hero();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void lifetexty();
	int getlvl();
	void stratamany(int x);
	int stan_many();
	int getManaMax();
	int stan_zycia();
	int getLifeMax();
	void newgame();
	int attack();
	void take_dmga(int a, int &stan);
	void full_health();
	void life_potion();
	void mana_potion();
	void weapon_change();
	int returndmg1();
	int returndmg2();
	
	

private:
	int level;
	int life;
	int damage1;
	int damage2;
	int str;
	int mana;
	int mana_max;
	int life_max;

};

