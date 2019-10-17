/*************************************************************
 *
 *  Ogre-Project
 *     LogoState.cpp
 *        Manager : Jae-yeon Jin
 *        Coder   : Jeong-woo Park
 *        2011 - 05 - 14
 *  
 *************************************************************/
#include "LogoState.h"

LogoState::LogoState(OgreProject* game) : State(game)
{

}

LogoState::~LogoState(void)
{

}

void LogoState::initial(void *)
{
	mesh.createMesh(getBase(), "logoMesh", "robot.mesh");
	mesh.yaw(-45.5f);
	mesh.setScale(0.5f, 0.5f, 0.5f);
	mesh.translate(-0.5f, -20.0f, 0);
	logoFont.createSpriteFont(getBase(), "forOurLogo");
}

void LogoState::update(float elapsed)
{

}

void LogoState::destroy()
{
	mesh.release();
	logoFont.release();
}

void LogoState::keyEvent(bool isPress, OIS::KeyCode key)
{
	if(isPress)
	{
		getBase()->getStateBank()->outroState();
		getBase()->getStateBank()->introState("menu", NULL);
	}
}