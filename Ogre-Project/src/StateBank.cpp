/*************************************************************
 *
 *  Ogre-Project Framework
 *     StateBank.cpp
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#include "StateBank.h"

StateBank::StateBank(void)
{

}

StateBank::~StateBank(void)
{
	while(stateStack.size() != 0)
	{
		outroState();
	}
}

void StateBank::addState(Ogre::String name, State * state)
{
	stateList.insert(std::pair<Ogre::String, State*>(name, state));
}

void StateBank::removeState(Ogre::String name)
{
	stateList.erase(name);
}

void StateBank::introState(Ogre::String name, void * obj)
{
	if(stateStack.size() != 0) stateStack.top()->introOther();
	stateStack.push(stateList.at(name));
	stateStack.top()->initial(obj);
}

bool StateBank::outroState()
{
	if(stateStack.size() == 0) return false;
	stateStack.top()->destroy();
	stateStack.pop();
	if(stateStack.size() != 0) stateStack.top()->outroOther();
	return true;
}

void StateBank::updateState(float elapsed)
{
	if(stateStack.size() == 0) return;
	stateStack.top()->update(elapsed);
}

void StateBank::keyEvent(bool isPress, OIS::KeyCode key)
{
	if(stateStack.size() == 0) return;
	stateStack.top()->keyEvent(isPress, key);
}