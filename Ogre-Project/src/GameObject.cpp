#include "GameObject.h"

GameObject::GameObject(State * _state)
{
	state = _state;
	x = y = z = 0;
	initial();
}

GameObject::~GameObject(void)
{
	destroy();
}

void GameObject::initial()
{

}

void GameObject::update(float elapsed)
{

}

void GameObject::destroy()
{

}

OgreProject* GameObject::getBase()
{
	return state->getBase();
}

State* GameObject::getState()
{
	return state;
}

float GameObject::getX()
{
	return x;
}

float GameObject::getY()
{
	return y;
}

float GameObject::getZ()
{
	return z;
}

void GameObject::setX(float _x)
{
	x = _x;
}

void GameObject::setY(float _y)
{
	y = _y;
}

void GameObject::setZ(float _z)
{
	z = _z;
}

void GameObject::keyEvent(bool isPress, OIS::KeyCode key)
{

}