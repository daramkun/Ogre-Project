#include "MonsterBank.h"
#include "Player.h"
#include "Monster.h"

MonsterBank::MonsterBank(State * _state) : GameObject(_state)
{

}

MonsterBank::~MonsterBank(void)
{

}

void MonsterBank::addMonster()
{
	for(int i = 0; i < 70; i++)
	{
		Monster * monster = new Monster(getState());
		monster->initial();
		mons.push_back(monster);
	}
}

void MonsterBank::initial()
{
	addMonster();
}

void MonsterBank::update(float elapsed)
{
	for(std::vector<Monster*>::iterator i = mons.begin(); i != mons.end(); i++)
		(*i)->update(elapsed);
}

void MonsterBank::destroy()
{
	for(int i = 0; i < mons.size(); i++) { mons[i]->destroy(); delete mons[i]; }
	mons.clear();
}

bool MonsterBank::checkCrash(Player * p)
{
	for(std::vector<Monster*>::iterator i = mons.begin(); i != mons.end(); i++)
		if((*i)->isCrashed(p)) return true;
	return false;
}