/*************************************************************
 *
 *  Ogre-Project
 *     MenuState.h
 *        Manager : Jae-yeon Jin
 *        Coder   : Hye-jeong Joo
 *        2011 - 05 - 14
 *  
 *************************************************************/
#pragma once

#include <OgreProject.h>
#include <State.h>
#include <Mesh.h>
#include <SpriteFont.h>

class MenuState : public State
{
	SpriteFont font;
	Mesh mesh;

	float x, y, z;

public:
	MenuState(OgreProject* game);
	~MenuState(void);
	
	virtual void initial(void *);
	virtual void update(float elapsed);
	virtual void destroy();

	virtual void introOther();
	virtual void outroOther();

	virtual void keyEvent(bool isPress, OIS::KeyCode key);
};