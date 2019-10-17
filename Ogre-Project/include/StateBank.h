/*************************************************************
 *
 *  Ogre-Project Framework
 *     StateBank.h
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#pragma once

#include <Ogre.h>

#include "State.h"

#include <map>
#include <stack>

class StateBank
{
	friend class OgreProject;
public:
	StateBank(void);
	~StateBank(void);

public:
	void addState(Ogre::String name, State * state);
	void removeState(Ogre::String name);

	void introState(Ogre::String name, void * obj);
	bool outroState();

private:
	void updateState(float elapsed);
	
	void keyEvent(bool isPress, OIS::KeyCode key);

private:
	std::map<Ogre::String, State*> stateList;
	std::stack<State*> stateStack;
};