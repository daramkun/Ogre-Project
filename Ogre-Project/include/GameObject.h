#pragma once

#include "State.h"

class GameObject
{
private:
	State * state;

	float x, y, z;

public:
	GameObject(State * state);
	virtual ~GameObject(void);

	virtual void initial();
	virtual void update(float elapsed);
	virtual void destroy();

	virtual void keyEvent(bool isPress, OIS::KeyCode key);

	OgreProject* getBase();
	State* getState();

	float getX();
	float getY();
	float getZ();

	void setX(float x);
	void setY(float y);
	void setZ(float z);
};