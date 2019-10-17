#include <OgreProject.h>
#include <Windows.h>

#include "LogoState.h"
#include "MenuState.h"
#include "PlayState.h"
#include "RankState.h"

INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
{
	OgreProject app;

	LogoState logoState(&app);
	MenuState menuState(&app);
	PlayState playState(&app);
	RankState rankState(&app);

	app.getStateBank()->addState("logo", &logoState);
	app.getStateBank()->addState("menu", &menuState);
	app.getStateBank()->addState("play", &playState);
	app.getStateBank()->addState("rank", &rankState);

	try
	{
		app.go("logo", NULL);
	}
	catch( Ogre::Exception& e ) { MessageBox(NULL, e.getDescription().c_str(), NULL, NULL); }

	return 0;
}