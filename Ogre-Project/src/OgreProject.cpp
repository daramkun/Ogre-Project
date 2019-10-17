/*************************************************************
 *
 *  Ogre-Project Framework
 *     OgreProject.cpp
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#include "OgreProject.h"
#include <cstring>

OgreProject::OgreProject(void)
{
	memset(isKeyPressed, 0, sizeof(isKeyPressed));
	userCamera = new UserCamera(this);
}

OgreProject::~OgreProject(void)
{
	delete userCamera;
}

void OgreProject::createScene(void)
{
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));

	light.createLight(this);
	light.setPosition(20, 80, 50);

	overlay = Ogre::OverlayManager::getSingletonPtr();

	if(stateName != "")
	{
		stateBank.introState(stateName, obj);
		stateName = "";
	}
}

void OgreProject::destroyScene(void)
{
	while(stateBank.outroState());
}

bool OgreProject::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
	if(mWindow->isClosed())
		return false;

	if(mShutDown)
		return false;

	mKeyboard->capture();
	stateBank.updateState(evt.timeSinceLastFrame);

	return true;
}

StateBank* OgreProject::getStateBank()
{
	return &stateBank;
}

UserCamera* OgreProject::getCamera()
{
	return userCamera;
}

void OgreProject::go(Ogre::String _stateName, void* _obj)
{
#ifdef _DEBUG
    mResourcesCfg = "resources_d.cfg";
    mPluginsCfg = "plugins_d.cfg";
#else
    mResourcesCfg = "resources.cfg";
    mPluginsCfg = "plugins.cfg";
#endif

	stateName = _stateName; obj = _obj;

    if (!setup())
        return;

    mRoot->startRendering();

    destroyScene();
}

bool OgreProject::isKeyDown(OIS::KeyCode keyCode)
{
	return isKeyPressed[keyCode];
}

bool OgreProject::keyPressed( const OIS::KeyEvent &arg )
{
	isKeyPressed[arg.key] = true;
	stateBank.keyEvent(true, arg.key);
	return true;
}

bool OgreProject::keyReleased( const OIS::KeyEvent &arg )
{
	isKeyPressed[arg.key] = false;
	stateBank.keyEvent(false, arg.key);
	return true;
}