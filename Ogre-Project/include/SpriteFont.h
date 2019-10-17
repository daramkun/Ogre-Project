#pragma once

#include <OgreOverlay.h>

class OgreProject;

class SpriteFont
{
	OgreProject * prj;
	Ogre::String panelName;
	Ogre::Overlay * box;

public:
	SpriteFont(void);
	~SpriteFont(void);

	void createSpriteFont(OgreProject * _prj, Ogre::String panelName);
	void release();
	
	void setText(Ogre::String text, Ogre::String target = "");

	void showMode(bool show);
};