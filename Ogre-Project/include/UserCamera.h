/*************************************************************
 *
 *  Ogre-Project Framework
 *     UserCamera.h
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#pragma once

#include <Ogre.h>

class OgreProject;

class UserCamera
{
	friend class OgreProject;
private:
	OgreProject * game;

private:
	UserCamera(OgreProject * game);
	~UserCamera(void);
	
public:
	void setPosition(float x, float y, float z);
	void setDirection(float x, float y, float z);

	void getPosition(float &x, float &y, float &z);

	void moveCamera(float x, float y, float z);

	void pitch(float angle);
	void yaw(float angle);
	void roll(float angle);

	void walk(float unit);
	void strafe(float unit);
};