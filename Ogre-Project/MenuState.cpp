/*************************************************************
 *
 *  Ogre-Project
 *     MenuState.cpp
 *        Manager : Jae-yeon Jin
 *        Coder   : Hye-jeong Joo
 *        2011 - 05 - 14
 *  
 *************************************************************/
#include "MenuState.h"

MenuState::MenuState(OgreProject* game) : State(game)
{

}

MenuState::~MenuState(void)
{

}

void MenuState::initial(void *)
{
	font.createSpriteFont(getBase(), "menuState");
	mesh.createMesh(getBase(), "MenuHead", "ogrehead.mesh");
	getBase()->getCamera()->getPosition(x, y, z);
}

void MenuState::update(float elapsed)
{
	mesh.yaw(elapsed);
}

void MenuState::destroy()
{
	mesh.release();
	font.release();
}

void MenuState::introOther()
{
	mesh.showMode(false);
	font.showMode(false);
}

void MenuState::outroOther()
{
	getBase()->getCamera()->setPosition(x, y, z);
	getBase()->getCamera()->setDirection(0, 0, 0);
	mesh.showMode(true);
	font.showMode(true);
}

void MenuState::keyEvent(bool isPress, OIS::KeyCode key)
{
	if(!isPress)
	{
		switch(key)
		{
		case OIS::KC_1:
			getBase()->getStateBank()->introState("play", NULL);
			break;
		case OIS::KC_2:
			getBase()->getStateBank()->introState("rank", NULL);
			break;
		}
	}
}