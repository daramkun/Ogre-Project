/*************************************************************
 *
 *  Ogre-Project Framework
 *     ElapsedTimer.cpp
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#include "ElapsedTimer.h"

ElapsedTimer::ElapsedTimer(void)
{
	delay = elapsed = 0;
}

ElapsedTimer::~ElapsedTimer(void)
{

}

void ElapsedTimer::setDelay(float _delay)
{
	delay = _delay;
}

void ElapsedTimer::reset()
{
	elapsed = 0;
}

bool ElapsedTimer::checkTime()
{
	return (delay <= elapsed);
}

void ElapsedTimer::updateTimer(float _elapsed)
{
	elapsed += (_elapsed * 1000);
}