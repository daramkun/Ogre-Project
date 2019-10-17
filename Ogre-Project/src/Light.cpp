/*************************************************************
 *
 *  Ogre-Project Framework
 *     Light.cpp
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#include "Light.h"
#include "OgreProject.h"

Light::Light(void)
{

}

Light::~Light(void)
{

}

void Light::createLight(OgreProject * _game)
{
	game = _game;
	light = game->mSceneMgr->createLight("MainLight");
}

void Light::release()
{
	light->detachFromParent();
}

void Light::setPosition(float x, float y, float z)
{
	light->setPosition(x, y, z);
}

void Light::setDirection(float x, float y, float z)
{
	light->setDirection(x, y, z);
}

void Light::setColor(int r, int g, int b)
{
	light->setDiffuseColour(r / 255.0f, g / 255.0f, b / 255.0f);
	light->setSpecularColour(r / 255.0f, g / 255.0f, b / 255.0f);
}