#pragma once

#include <GameObject.h>
#include <vector>

class Monster;
class Player;

class MonsterBank : public GameObject
{
private:
	std::vector<Monster*> mons;

public:
	MonsterBank(State * state);
	~MonsterBank(void);

	void initial();
	void update(float elapsed);
	void destroy();
	
	bool checkCrash(Player * p);

private:
	void addMonster();
};