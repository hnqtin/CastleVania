#include "ExitStair.h"
REGISTER_OBJECT_GAME(ExitStair, SI_EXIT_STAIR)
#include"Player.h"
#include"Collision.h"

void ExitStair::onInit(fstream & fs, int worldHeight)
{
	string name;
	fs >> name >> isMoveUp >> name >> isUpRightStair;
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
		player->setIsOnStair(true);
		player->setisUpRightStair(isUpRightStair);
		player->moveUpStair(player->getDt());
	}

	if (key->isDownDown && !player->getIsOnStair() && !this->isMoveUp)
	{
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
		player->moveY(4);
		//player->setY(getBottom() + player->getHeight() );
		player->setIsOnStair(true);
		player->setisUpRightStair(isUpRightStair);
		player->moveDownStair(player->getDt());
	}

	if (player->getIsOnStair())
	{
		if ((player->getDy() < 0 && this->isMoveUp) || (player->getDy() > 0 && !this->isMoveUp))
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
