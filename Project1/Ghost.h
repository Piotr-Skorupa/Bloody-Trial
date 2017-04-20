#pragma once
#include "Zombie.h"
class Ghost :
	public Zombie
{
public:
	int money_get();
	Ghost(int xo, int yo);
	~Ghost();
private:
	int _hp;
	const int _gold = 300;
	std::thread z_thread;
};

