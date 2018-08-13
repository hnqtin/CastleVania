#include "ExitStair.h"
REGISTER_OBJECT_GAME(ExitStair, SI_EXIT_STAIR)
#include"Player.h"
#include"Collision.h"

void ExitStair::onInit(fstream & fs, int worldHeight)
{
	string name1, name2;
	bool value1, value2;
	fs >> name1 >> value1 >> name2 >> value2;
	if (strcmp(name1.c_str(), "isMoveUp") == 0)
	{
		isMoveUp = value1;
		isUpRightStair = value2;
	}
	else
	{
		isMoveUp = value2;
		isUpRightStair = value1;
	}
}

void ExitStair::update(float dt)
{


}

void ExitStair::onIntersect(MovableBox * other)
{
	auto key = KEY::getInstance();
	auto player = Player::getInstance();
	if (key->isUpDown && !player->getIsOnStair() && this->isMoveUp)
	{
		player->setIsOnStair(true);
		player->setDx(0);
		player->setDy(0);
		player->setVy(0);
		player->setVx(0);
		if (isUpRightStair)
		{
			player->setX(getRight() - player->getWidth());
		}
		else
		{
			player->setX(getX());
		}
		//player->setY(getBottom() + player->getHeight());
		player->setisUpRightStair(isUpRightStair);
		player->moveUpStair(player->getDt());
	}

	if (key->isDownDown && !player->getIsOnStair() && !this->isMoveUp)
	{
		player->setIsOnStair(true);
		player->setDx(0);
		player->setDy(0);
		player->setVy(0);
		player->setVx(0);
		if (isUpRightStair)
		{
			player->setX(getX() + 8 - player->getWidth());
		}
		else
		{
			player->setX(getRight() + 8 - player->getWidth());
		}

		player->setisUpRightStair(isUpRightStair);
		player->moveDownStair(player->getDt());
	}
	if (player->getIsOnStair())
	{
		player->setHeight(getGlobalValue("player_height"));
		if ((player->getDy() < 0 && this->isMoveUp && getBottom() < player->getBottom())
			|| (player->getDy() > 0 && !this->isMoveUp && getBottom() > player->getBottom()))
		{
			player->setIsLastGoToStair(true);
		}
	}
}

ExitStair::ExitStair()
{
}


ExitStair::~ExitStair()
{
}
