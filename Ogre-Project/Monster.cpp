#include "Monster.h"
#include "Player.h"
#include "PlayState.h"

int Monster::count = 0;

Monster::Monster(State * _state) : GameObject(_state)
{

}

Monster::~Monster(void)
{

}

void Monster::initial()
{
	Ogre::String entityName = "mon"; entityName += (++count);
	
	mesh.createMesh(getBase(), entityName, "RZR-002.mesh");
	angle = 0;
	mesh.setScale(0.3f, 0.3f, 0.3f);

	reset();
}

void Monster::update(float elapsed)
{
	float x, z;
	x = -sin(angle) * elapsed * 7.0f;
	z = -cos(angle) * elapsed * 7.0f;

	mesh.translate(x, 0, z);
	setX(getX() + x);
	setZ(getZ() + z);
	
	if(getX() > STARTING_X || getX() < -STARTING_X || getZ() > STARTING_Z || getZ() < -STARTING_Z)
		reset();
}

void Monster::destroy()
{
	mesh.release();
}

void Monster::reset()
{
	int location = rand() % 8 / 2;

	float x, z;

	switch(location)
	{
	case 0:
		x = -STARTING_X;
		z = (rand() % (STARTING_Z * 10 * 2)) / 10.0f - STARTING_Z;
		break;
	case 1:
		x = STARTING_X;
		z = (rand() % (STARTING_Z * 10 * 2)) / 10.0f - STARTING_Z;
		break;
	case 2:
		x = (rand() % (STARTING_X * 10 * 2)) / 10.0f - STARTING_X;
		z = -STARTING_Z;
		break;
	case 3:
		x = (rand() % (STARTING_X * 10 * 2)) / 10.0f - STARTING_X;
		z = STARTING_Z;
		break;
	}
	
	float rot = atan2(getX(), getZ()) / 3.141592f * 180;
	mesh.yaw(90 - rot);

	setX(x); setZ(z);
	mesh.setPosition(x, 0, z);
	angle = atan2(getX(), getZ());
	
	rot = atan2(getX(), getZ()) / 3.141592f * 180;
	mesh.yaw(90 - -rot);
}

bool Monster::isCrashed(Player * p)
{
	return ( sqrt(pow(getX() - p->getX(), 2) + pow(getY() - p->getY(), 2) + pow(getZ() - p->getZ(), 2)) <= ((p->getRadius() + mesh.getBoundingRadius()) / 3) );
}