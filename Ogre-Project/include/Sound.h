/*************************************************************
 *
 *  Ogre-Project Framework
 *     Sound.h
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#pragma once

#include <string>
#include <libzplay.h>

class Sound
{
private:
	libZPlay::ZPlay *player;

public:
	Sound(void);
	~Sound(void);

	// Load sound file(Not Ogre3D resource)
	void createSound(std::string filename);
	// Release loaded sound
	void release();

	void play();
	void stop();
	void pause();

	int getPosition();
};