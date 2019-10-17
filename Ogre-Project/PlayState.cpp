#include "PlayState.h"
#include <sstream>
#include <cstdio>
#include <algorithm>

PlayState::PlayState(OgreProject* game) : State(game), monBank(this), player(this)
{

}

PlayState::~PlayState(void)
{

}

void PlayState::initial(void *)
{
	isGameOver = false;

	getBase()->getCamera()->setPosition(0, 100.0f, 25.0f);
	getBase()->getCamera()->setDirection(0, 0, 0);

	player.initial();
	monBank.initial();

	time = 0;
	elapsTimer.setDelay(100);
	font.createSpriteFont(getBase(), "elapsTime");
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

void PlayState::update(float elapsed)
{
	if(!isGameOver)
	{
		elapsTimer.updateTimer(elapsed);
		if(elapsTimer.checkTime())
		{
			time += 0.1f;
			Ogre::String text = "Elapsed time : ";
			text += StringCast<Ogre::String>(time);
			font.setText(text);
			elapsTimer.reset();
		}

		player.update(elapsed);
		monBank.update(elapsed);

		if(monBank.checkCrash(&player))
			isGameOver = true;
	}
}

void PlayState::destroy()
{
	font.release();
	player.destroy();
	monBank.destroy();
}

void PlayState::keyEvent(bool isPress, OIS::KeyCode key)
{
	if(isGameOver)
	{
		if(!isPress)
		{
			if(key == OIS::KC_RETURN || key == OIS::KC_SPACE)
			{
				float rank[4] = {0, };

				FILE * fp = fopen("ranking.txt", "rt");
				if(!feof(fp))
				{
					for(int i = 0; i < 3; i++)
						fscanf(fp, "%f", &rank[i]);
				}
				fclose(fp);

				rank[3] = time;
				
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						if(rank[j] < rank[j + 1])
						{
							float temp = rank[j];
							rank[j] = rank[j + 1];
							rank[j + 1] = temp;
						}
					}
				}
				
				fp = fopen("ranking.txt", "wt");
				for(int i = 0; i < 3; i++)
					fprintf(fp, "%f\n", rank[i]);
				fclose(fp);

				getBase()->getStateBank()->outroState();
			}
		}
	}
}