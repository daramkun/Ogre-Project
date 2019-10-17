/*************************************************************
 *
 *  Ogre-Project
 *     LogoState.h
 *        Manager : Jae-yeon Jin
 *        Coder   : Jeong-woo Park
 *        2011 - 05 - 14
 *  
 *************************************************************/

#pragma once

#include <OgreProject.h>
#include <State.h>
#include <Mesh.h>
#include <SpriteFont.h>

class LogoState : public State
{
private:
	Mesh mesh;
	SpriteFont logoFont;

public:
	LogoState(OgreProject* game);
	~LogoState(void);
	
	virtual void initial(void *);
	virtual void update(float elapsed);
	virtual void destroy();

	virtual void keyEvent(bool isPress, OIS::KeyCode key);
};