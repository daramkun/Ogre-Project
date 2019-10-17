#pragma once

#include <GameObject.h>
#include <Mesh.h>

#define STARTING_X 65
#define STARTING_Z 55

class Player;

class Monster : public GameObject
{
private:
	static int count;

	Mesh mesh;
	float angle;

public:
	Monster(State * state);
	~Monster(void);

	void initial();
	void update(float elapsed);
	void destroy();

	bool isCrashed(Player * p);

private:
	void reset();
};