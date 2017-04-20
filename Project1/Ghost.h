#pragma once
#include "Zombie.h"
class Ghost :
	public Zombie
{
public:
	int money_get();
	Ghost(int xo, int yo);
	void take_dmga(int a, int &b, int &c);
	void newgame1(int xo, int yo);
	std::string hptexta();
	~Ghost();
private:
	int _hp;
	const int _gold = 300;
	std::thread z_thread;
};

