#include "SpriteFont.h"
#include "OgreProject.h"

SpriteFont::SpriteFont(void)
{
}


SpriteFont::~SpriteFont(void)
{
}

void SpriteFont::createSpriteFont(OgreProject * _prj, Ogre::String _panelName)
{
	prj = _prj;
	panelName = _panelName;

	box = prj->overlay->getByName(panelName);
	
	box->show();
}

void SpriteFont::release()
{
	box->hide();
}

void SpriteFont::setText(Ogre::String text, Ogre::String target)
{
	prj->overlay->getOverlayElement((target == "") ? panelName : target)->setCaption(text);
}

void SpriteFont::showMode(bool show)
{
	if(show) box->show();
	else box->hide();
}