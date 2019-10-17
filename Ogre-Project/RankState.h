/*************************************************************
 *
 *  Ogre-Project
 *     MenuState.h
 *        Manager : Jae-yeon Jin
 *        Coder   : Jae-yeon Jin
 *        2011 - 06 - 19
 *  
 *************************************************************/
#pragma once

#include <OgreProject.h>
#include <State.h>
#include <SpriteFont.h>

class RankState : public State
{
private:
	SpriteFont font;

public:
	RankState(OgreProject* game);
	~RankState(void);
	
	virtual void initial(void *);
	virtual void update(float elapsed);
	virtual void destroy();

	virtual void keyEvent(bool isPress, OIS::KeyCode key);
};

