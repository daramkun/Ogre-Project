/*************************************************************
 *
 *  Ogre-Project
 *     PlayState.h
 *        Manager : Jae-yeon Jin
 *        Coder   : Jae-yeon Jin, Se-jin Jang
 *        2011 - 05 - 14
 *  
 *************************************************************/
#pragma once

#include <State.h>
#include <OgreProject.h>
#include <ElapsedTimer.h>
#include <SpriteFont.h>

#include "Player.h"
#include "MonsterBank.h"

class PlayState : public State
{
	friend class Monster;
private:
	Player player;
	MonsterBank monBank;

	ElapsedTimer elapsTimer;
	float time;
	SpriteFont font;

	bool isGameOver;

public:
	PlayState(OgreProject* game);
	~PlayState(void);
	
	virtual void initial(void *);
	virtual void update(float elapsed);
	virtual void destroy();

	virtual void keyEvent(bool isPress, OIS::KeyCode key);
};