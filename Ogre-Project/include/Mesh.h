/*************************************************************
 *
 *  Ogre-Project Framework
 *     Mesh.h
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#pragma once

#include <OgreMesh.h>

class OgreProject;

class Mesh
{
	OgreProject * game;
	Ogre::String entityName;
	Ogre::String nodeName;
	int ref;

public:
	Mesh(void);
	~Mesh(void);

	Ogre::Entity* createMesh(OgreProject * game, Ogre::String entityName, Ogre::String fileName);
	void release();

	void setPosition(float x, float y, float z);
	void translate(float x, float y, float z);

	void setRotation(float angle, float x, float y, float z);
	void pitch(float angle);
	void yaw(float angle);
	void roll(float angle);

	void setScale(float x, float y, float z);

	void showMode(bool show);

	// For crash check
	float getBoundingRadius();
};