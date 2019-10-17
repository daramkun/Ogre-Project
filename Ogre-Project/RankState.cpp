#include "RankState.h"
#include <cstdio>

RankState::RankState(OgreProject* game) : State(game)
{

}

RankState::~RankState(void)
{

}

template< typename To, typename From >
const To StringCast(const From& from)
{
	std::stringstream strStream;
	strStream << from;

	To result;
	strStream >> result;

	if ( strStream.fail() && !strStream.eof() ) return 0;

	return result;
}

void RankState::initial(void *)
{
	font.createSpriteFont(getBase(), "rankState");

	float rank[3] = {0, };
	FILE * fp = fopen("ranking.txt", "rt");
	if(!feof(fp))
	{
		for(int i = 0; i < 3; i++)
			fscanf(fp, "%f", &rank[i]);
	}
	fclose(fp);

	Ogre::String text = "1. ";
	text += StringCast<Ogre::String>(rank[0]);
	font.setText(text, "rankState_1st");
	text = "2. ";
	text += StringCast<Ogre::String>(rank[1]);
	font.setText(text, "rankState_2nd");
	text = "3. ";
	text += StringCast<Ogre::String>(rank[2]);
	font.setText(text, "rankState_3rd");
}

void RankState::update(float elapsed)
{

}

void RankState::destroy()
{
	font.release();
}

void RankState::keyEvent(bool isPress, OIS::KeyCode key)
{
	if(!isPress)
	{
		getBase()->getStateBank()->outroState();
	}
}