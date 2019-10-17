/*************************************************************
 *
 *  Ogre-Project Framework
 *     Light.h
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#pragma once

#include <OgreLight.h>

class OgreProject;

class Light
{
	OgreProject * game;
	Ogre::Light * light;
public:
	Light(void);
	~Light(void);

	void createLight(OgreProject * game);
	void release();

	void setPosition(float x, float y, float z);
	void setDirection(float x, float y, float z);
	void setColor(int r, int g, int b);
};