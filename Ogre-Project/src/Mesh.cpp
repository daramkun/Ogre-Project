/*************************************************************
 *
 *  Ogre-Project Framework
 *     Mesh.cpp
 *        Written by Jae-yeon Jin
 *        2011 - 05 - 14
 *  
 *************************************************************/
#include "Mesh.h"
#include "OgreProject.h"

Mesh::Mesh(void)
{
	game = NULL;
}

Mesh::~Mesh(void)
{

}

Ogre::Entity* Mesh::createMesh(OgreProject * _game, Ogre::String _entityName, Ogre::String fileName)
{
	game = _game;
	entityName = nodeName = _entityName;

	Ogre::Entity * entity;
	try { entity = game->mSceneMgr->getEntity(entityName); }
	catch(Ogre::Exception & e) { entity = game->mSceneMgr->createEntity(entityName, fileName); }
	
    Ogre::SceneNode* node = game->mSceneMgr->getRootSceneNode()->createChildSceneNode(nodeName);
    node->attachObject(entity);

	ref = 0;

	return entity;
}

void Mesh::release()
{
	game->mSceneMgr->getSceneNode(nodeName)->detachObject(entityName);

	game->mSceneMgr->destroySceneNode(nodeName);
}

void Mesh::setPosition(float x, float y, float z)
{
	game->mSceneMgr->getSceneNode(nodeName)->setPosition(x, y, z);
}

void Mesh::translate(float x, float y, float z)
{
	game->mSceneMgr->getSceneNode(nodeName)->translate(x, y, z);
}

void Mesh::setRotation(float angle, float x, float y, float z)
{
	game->mSceneMgr->getSceneNode(nodeName)->rotate(Ogre::Vector3(x, y, z), Ogre::Radian(Ogre::Degree(angle)));
}

void Mesh::pitch(float angle)
{
	game->mSceneMgr->getSceneNode(nodeName)->pitch(Ogre::Radian(Ogre::Degree(angle)));
}

void Mesh::yaw(float angle)
{
	game->mSceneMgr->getSceneNode(nodeName)->yaw(Ogre::Radian(Ogre::Degree(angle)));
}

void Mesh::roll(float angle)
{
	game->mSceneMgr->getSceneNode(nodeName)->roll(Ogre::Radian(Ogre::Degree(angle)));
}

void Mesh::setScale(float x, float y, float z)
{
	game->mSceneMgr->getSceneNode(nodeName)->scale(x, y, z);
}

float Mesh::getBoundingRadius()
{
	return game->mSceneMgr->getEntity(entityName)->getBoundingRadius();
}

void Mesh::showMode(bool show)
{
	game->mSceneMgr->getEntity(entityName)->setVisible(show);
}