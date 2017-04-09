#include "Zombie.h"



Zombie::Zombie()
{

	_hp = 30;
	_dmg = 5;
	x = 500 + (std::rand() % (3500 - 500 + 1));
	y = 600 + (std::rand() % (1850 - 600 + 1));
	isMoving = true;
	isDead = false;
	trup.loadFromFile("src/zombie.png");
	dead.loadFromFile("src/zombie_trup.png");
	zombi.setTexture(trup);
	zombi.setPosition(x, y);
	pain.loadFromFile("src/zombie_pain.wav");
	getHit.setBuffer(pain);
	atakasz.loadFromFile("src/bite.wav");
	bite.setBuffer(atakasz);
	

}

void Zombie::newgame() {
	_hp = 30;
	x = 500 + (std::rand() % (3500 - 500 + 1));
	y = 600 + (std::rand() % (1850 - 600 + 1));
	isMoving = true;
	isDead = false;
}



void Zombie::draw(sf::RenderWindow &window) {
	window.draw(zombi);
}

void Zombie::take_dmg(int a, int &b) {
	_hp -= a;
	getHit.play();
	if (_hp <= 0) {
		isDead = true;
		isMoving = false;
		zombi.setTexture(dead);
		b += get_money();
	}
}

void Zombie::attack(Hero &a, bool &x) {
	while (isMoving == true ) {
		if (x == true) {
			//a.take_dmga(_dmg);
			bite.play();
			std::cout << "atakuje" << std::endl;
			sf::sleep(sf::milliseconds(1000));
		}
	}
}

int Zombie::get_money() {
	hajs = 1 + (std::rand() % (4 - 1 + 1));
	if (hajs == 1) {
		return 10;
	}
	else if (hajs == 2) {
		return 20;
	}
	else if (hajs == 3) {
		return 35;
	}
	else if (hajs == 4) {
		return 0;
	}
	
}

void Zombie::move(bool g) {
	
	while (g == true)
	{
		
		if (isMoving == true) {
			kierunek_z = 1 + (std::rand() % (4 - 1 + 1));
			//lewo
			if (kierunek_z == 1) {
				if (zombi.getPosition().x > 200) {
					int bb = 1 + (std::rand() % (3 - 1 + 1));
					if (isMoving == true && bb == 1) {
						for (int i = 0; i < 5; i++) {
							zombi.move(-4, 0);
							
						}
					}
					if (isMoving == true && bb == 2) {
						for (int i = 0; i < 10; i++) {
							zombi.move(-4, 0);
							
						}

					}
					if (isMoving == true && bb == 3) {
						for (int i = 0; i < 15; i++) {
							zombi.move(-4, 0);
							
						}
					}
				}
				else kierunek_z = 2;
			}

			//prawo
			if (kierunek_z == 2) {
				if (zombi.getPosition().x < 4700) {
					int bb = 1 + (std::rand() % (3 - 1 + 1));
					if (isMoving == true && bb == 1) {
						for (int i = 0; i < 5; i++) {
							zombi.move(4, 0);
							
						}
					}
					if (isMoving == true && bb == 2) {
						for (int i = 0; i < 10; i++) {
							zombi.move(4, 0);
							
						}

					}
					if (isMoving == true && bb == 3) {
						for (int i = 0; i < 15; i++) {
							zombi.move(4, 0);
							
						}
					}
				}
				else kierunek_z = 1;
			}
			//gora	
			if (kierunek_z == 3) {
				if (zombi.getPosition().y > 100) {
					int bb = 1 + (std::rand() % (3 - 1 + 1));
					if (isMoving == true && bb == 1) {
						for (int i = 0; i < 5; i++) {
							zombi.move(0, -4);
							
						}
					}
					if (isMoving == true && bb == 2) {
						for (int i = 0; i < 10; i++) {
							zombi.move(0, -4);
							
						}

					}
					if (isMoving == true && bb == 3) {
						for (int i = 0; i < 15; i++) {
							zombi.move(0, -4);
							
						}
					}
				}
				else kierunek_z = 4;
			}
			//dol	
			if (kierunek_z == 4) {
				if (zombi.getPosition().y < 1880) {
					int bb = 1 + (std::rand() % (3 - 1 + 1));
					if (isMoving == true && bb == 1) {
						for (int i = 0; i < 5; i++) {
							zombi.move(0, 4);
							
						}
					}
					if (isMoving == true && bb == 2) {
						for (int i = 0; i < 10; i++) {
							zombi.move(0, 4);
							
						}

					}
					if (isMoving == true && bb == 3) {
						for (int i = 0; i < 15; i++) {
							zombi.move(0, 4);
							
						}
					}
				}
				else kierunek_z = 3;
			}
		}
		sf::sleep(sf::milliseconds(200));
	}
	
	
}

void Zombie::makethread(bool g) {
	z_thread = std::thread(&Zombie::move, this, g);
	
	
}

std::string Zombie::hptext() {
	return std::to_string(_hp);
}

Zombie::~Zombie()
{
	z_thread.join();
	
}
