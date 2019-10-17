/*************************************************************
 *
 *  Ogre-Project Framework
 *     State.h
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#pragma once

#include <OIS.h>

class OgreProject;

class State
{
	friend class StateBank;
public:
	State(OgreProject* game);
	~State(void);

	OgreProject* getBase();

protected:
	virtual void initial(void *);
	virtual void introOther();
	virtual void outroOther();
	virtual void update(float elapsed);
	virtual void destroy();

	virtual void keyEvent(bool isPress, OIS::KeyCode key);

private:
	OgreProject* game;
};