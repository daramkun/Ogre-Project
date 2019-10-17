/*************************************************************
 *
 *  Ogre-Project Framework
 *     ElapsedTimer.h
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#pragma once

class ElapsedTimer
{
private:
	float delay;
	float elapsed;

public:
	ElapsedTimer(void);
	~ElapsedTimer(void);

	// Set delay time(Unit: sec, ex: 1.02f)
	void setDelay(float delay);
	void reset();

	bool checkTime();
	void updateTimer(float elapsed);
};