/*************************************************************
 *
 *  Ogre-Project Framework
 *     UserCamera.cpp
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#include "UserCamera.h"
#include "OgreProject.h"

UserCamera::UserCamera(OgreProject * _game)
{
	game = _game;
}

UserCamera::~UserCamera(void)
{

}

void UserCamera::setPosition(float x, float y, float z)
{
	game->mCamera->setPosition(x, y, z);
}

void UserCamera::setDirection(float x, float y, float z)
{
	game->mCamera->lookAt(x, y, z);
}

void UserCamera::getPosition(float &x, float &y, float &z)
{
	Ogre::Vector3 v = game->mCamera->getPosition();
	x = v.x; y = v.y; z = v.z;
}

void UserCamera::moveCamera(float x, float y, float z)
{
	game->mCamera->move(Ogre::Vector3(x, y, z));
}

void UserCamera::pitch(float angle)
{
	game->mCamera->pitch(Ogre::Radian(Ogre::Degree(angle)));
}

void UserCamera::yaw(float angle)
{
	game->mCamera->yaw(Ogre::Radian(Ogre::Degree(angle)));
}
	
void UserCamera::roll(float angle)
{
	game->mCamera->roll(Ogre::Radian(Ogre::Degree(angle)));
}

void UserCamera::walk(float unit)
{
	game->mCamera->moveRelative(Ogre::Vector3(0, 0, -unit));
}

void UserCamera::strafe(float unit)
{
	game->mCamera->moveRelative(Ogre::Vector3(unit, 0, 0));
}