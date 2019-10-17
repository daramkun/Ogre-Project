#include "Player.h"
#include "OgreProject.h"

Player::Player(State * _state) : GameObject(_state)
{

}

Player::~Player(void)
{

}

void Player::initial()
{
	ogreHead.createMesh(getBase(), "Head", "ogrehead.mesh");
	ogreHead.setScale(0.1f, 0.1f, 0.1f);
	angle = 0;
	setX(0); setZ(0);
}

void Player::update(float elapsed)
{
	float x = sin(angle) * elapsed * 10.0f,
		  z = cos(angle) * elapsed * 10.0f;

	if(getBase()->isKeyDown(OIS::KC_UP))
	{
		if(!(getX() + x > CRASHING_X || getX() + x < -CRASHING_X || getZ() + z > CRASHING_Z || getZ() + z < -CRASHING_Z))
		{
			ogreHead.translate(x, 0, z);
			setX(getX() + x); setZ(getZ() + z);
		}
	}
	
	if(getBase()->isKeyDown(OIS::KC_DOWN))
	{
		if(!(getX() - x > CRASHING_X || getX() - x < -CRASHING_X || getZ() - z > CRASHING_Z || getZ() - z < -CRASHING_Z))
		{
			ogreHead.translate(-x, 0, -z);
			setX(getX() - x); setZ(getZ() - z);
		}
	}
	
	if(getBase()->isKeyDown(OIS::KC_LEFT))
	{
		angle += (60 * elapsed) / 180 * 3.14f;
		ogreHead.yaw(60 * elapsed);
	}
	
	if(getBase()->isKeyDown(OIS::KC_RIGHT))
	{
		angle += (-60 * elapsed) / 180 * 3.14f;
		ogreHead.yaw(-60 * elapsed);
	}
}

void Player::destroy()
{
	ogreHead.release();
}

float Player::getRadius()
{
	return ogreHead.getBoundingRadius();
}