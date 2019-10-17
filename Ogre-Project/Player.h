#pragma once

#include <GameObject.h>
#include <Mesh.h>

#define CRASHING_X 55
#define CRASHING_Z 45

class Player : public GameObject
{
private:
	Mesh ogreHead;
	float angle;

public:
	Player(State * state);
	~Player(void);

	void initial();
	void update(float elapsed);
	void destroy();

	float getRadius();
};