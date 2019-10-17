/*************************************************************
 *
 *  Ogre-Project Framework
 *     OgreProject.h
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/

#pragma once

#include "BaseApplication.h"
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include "../res/resource.h"
#endif

#include "StateBank.h"
#include "UserCamera.h"
#include "Light.h"

class OgreProject : public BaseApplication
{
	friend class Mesh;
	friend class Light;
	friend class UserCamera;
	friend class SpriteFont;
	
private:
	Ogre::OverlayManager * overlay;
	StateBank stateBank;
	UserCamera * userCamera;	// 3D Camera Wrapped class
	Light light;

	bool isKeyPressed[256];		// For key input state

	Ogre::String stateName;
	void * obj;

public:
    OgreProject(void);
    virtual ~OgreProject(void);

	// Get state bank's pointer
	StateBank* getStateBank();
	// Get user camera's pointer
	UserCamera* getCamera();
	// Check a key state
	bool isKeyDown(OIS::KeyCode keyCode);

	void go(Ogre::String stateName, void* obj);

protected:
    virtual void createScene(void);
	virtual void destroyScene(void);

	virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);
	
    virtual bool keyPressed( const OIS::KeyEvent &arg );
    virtual bool keyReleased( const OIS::KeyEvent &arg );
};