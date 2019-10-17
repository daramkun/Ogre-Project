/*************************************************************
 *
 *  Ogre-Project Framework
 *     Sound.cpp
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#include "Sound.h"

Sound::Sound(void)
{
	player = libZPlay::CreateZPlay();
}

Sound::~Sound(void)
{
	release();
}

void Sound::createSound(std::string filename)
{
	player->OpenFile(filename.c_str(), libZPlay::sfAutodetect);
}

void Sound::release()
{
	player->Release();
}

void Sound::play()
{
	player->Play();
}

void Sound::stop()
{
	player->Stop();
}

void Sound::pause()
{
	player->Pause();
}

int Sound::getPosition()
{
	libZPlay::TStreamTime time;
	player->GetPosition(&time);
	return time.ms;
}