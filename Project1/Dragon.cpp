#include "Dragon.h"



Dragon::Dragon()
{
	x = 4700;
	y = 900;
	_hp = 200;
	_dmg = 20;
	isMoving = true;
	isDead = false;
	smok.loadFromFile("src/dragon.png");
	dead.loadFromFile("src/deaddragon.png");
	dragon.setTexture(smok);
	dragon.setPosition(x, y);
	pain.loadFromFile("src/zombie_pain.wav");
	getHit.setBuffer(pain);
}

void Dragon::newgame() {
	_hp = 200;
	x = 4700;
	y = 900;
	isMoving = true;
	isDead = false;
	dragon.setTexture(smok);
}

std::string Dragon::hptext() {
	return std::to_string(_hp);
}

void Dragon::take_dmg(int a, int &b, int &c) {
	_hp -= a;
	getHit.play();
	if (_hp <= 0) {
		isDead = true;
		isMoving = false;
		dragon.setTexture(dead);
		b += 500;
		c-=1;
	}
}

Dragon::~Dragon()
{
	z_thread.join();
}

void Dragon::move(bool g) {

	while (g == true)
	{

		if (isMoving == true) {
			kierunek_z = 1 + (std::rand() % (4 - 1 + 1));
			//lewo
			if (kierunek_z == 1) {
				if (dragon.getPosition().x > 200) {
					int bb = 1 + (std::rand() % (3 - 1 + 1));
					if (isMoving == true && bb == 1) {
						for (int i = 0; i < 5; i++) {
							dragon.move(-4, 0);

						}
					}
					if (isMoving == true && bb == 2) {
						for (int i = 0; i < 10; i++) {
							dragon.move(-4, 0);

						}

					}
					if (isMoving == true && bb == 3) {
						for (int i = 0; i < 15; i++) {
							dragon.move(-4, 0);

						}
					}
				}
				else kierunek_z = 2;
			}

			//prawo
			if (kierunek_z == 2) {
				if (dragon.getPosition().x < 4700) {
					int bb = 1 + (std::rand() % (3 - 1 + 1));
					if (isMoving == true && bb == 1) {
						for (int i = 0; i < 5; i++) {
							dragon.move(4, 0);

						}
					}
					if (isMoving == true && bb == 2) {
						for (int i = 0; i < 10; i++) {
							dragon.move(4, 0);

						}

					}
					if (isMoving == true && bb == 3) {
						for (int i = 0; i < 15; i++) {
							dragon.move(4, 0);

						}
					}
				}
				else kierunek_z = 1;
			}
			//gora	
			if (kierunek_z == 3) {
				if (dragon.getPosition().y > 100) {
					int bb = 1 + (std::rand() % (3 - 1 + 1));
					if (isMoving == true && bb == 1) {
						for (int i = 0; i < 5; i++) {
							dragon.move(0, -4);

						}
					}
					if (isMoving == true && bb == 2) {
						for (int i = 0; i < 10; i++) {
							dragon.move(0, -4);

						}

					}
					if (isMoving == true && bb == 3) {
						for (int i = 0; i < 15; i++) {
							dragon.move(0, -4);

						}
					}
				}
				else kierunek_z = 4;
			}
			//dol	
			if (kierunek_z == 4) {
				if (dragon.getPosition().y < 1880) {
					int bb = 1 + (std::rand() % (3 - 1 + 1));
					if (isMoving == true && bb == 1) {
						for (int i = 0; i < 5; i++) {
							dragon.move(0, 4);

						}
					}
					if (isMoving == true && bb == 2) {
						for (int i = 0; i < 10; i++) {
							dragon.move(0, 4);

						}

					}
					if (isMoving == true && bb == 3) {
						for (int i = 0; i < 15; i++) {
							dragon.move(0, 4);

						}
					}
				}
				else kierunek_z = 3;
			}
		}
		sf::sleep(sf::milliseconds(200));
	}


}

void Dragon::makethread(bool g) {
	z_thread = std::thread(&Dragon::move, this, g);


}

