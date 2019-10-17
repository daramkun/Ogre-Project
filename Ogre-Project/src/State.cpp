/*************************************************************
 *
 *  Ogre-Project Framework
 *     State.cpp
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#include "State.h"

State::State(OgreProject* game)
{
	this->game = game;
}

State::~State(void)
{

}

OgreProject* State::getBase()
{
	return game;
}

void State::initial(void *)
{

}

void State::introOther()
{

}

void State::outroOther()
{

}

void State::update(float elapsed)
{

}

void State::destroy()
{

}

void State::keyEvent(bool isPress, OIS::KeyCode key)
{

}