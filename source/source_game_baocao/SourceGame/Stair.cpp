#include "Stair.h"
REGISTER_OBJECT_GAME(Stair, SI_STAIR)
#include"Player.h"
#include"KEY.h"

void Stair::onInit(fstream & fs, int worldHeight)
{
	string name;
	int direction;
	fs >> name >> direction;
	setDirection(direction);
}

void Stair::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	//if (ny == 1)
	//{
	//	other->preventMoveWhenCollision(collisionTime, nx, ny);
	//	Player::getInstance()->setIsOnGround(true);
	//	Player::getInstance()->setVy(-10);
	//}
}

void Stair::onIntersect(MovableBox * other)
{
	auto player = Player::getInstance();
	player->isContactStair = true;
	auto key = KEY::getInstance();
	if (other == player)
	{
		if (!player->onGoTo())
		{
			if (key->isUpDown)
			{
				playerMoveUp();
			}
			if (key->isDownDown)
			{
				playerMoveDown();
			}
		}
	}
}

void Stair::update(float dt)
{
	auto player = Player::getInstance();
	auto key = KEY::getInstance();
	if ((getRight() > player->getleft() && getleft() < player->getRight()) && getTop() == player->getBottom())
	{
		if (key->isDownDown)
		{
			playerMoveDown();
		}
	}
}

void Stair::playerMoveUp()
{
	auto player = Player::getInstance();
	if (!player->getIsOnStair())
	{
		if (getDirection() == 1)
		{
			player->setX(getX() - player->getWidth() + 10);
			player->setDirection(Right);
		}
		else
		{
			player->setX(getMidX());
			player->setDirection(Left);
		}
		player->setY(getBottom() + player->getHeight());
		player->setDx(0);
		player->setDy(0);
		player->setIsOnStair(true);
	}
	if (getDirection() == 1)
	{
		player->goToStairUpRight();
	}
	else
	{
		player->goToStairUpLeft();
	}
}

void Stair::playerMoveDown()
{
	auto player = Player::getInstance();
	player->setIsOnGround(false);
	if (!player->getIsOnStair())
	{
		if (getDirection() == 1)
		{
			player->setX(getleft() + 14);
			player->setDirection(Left);
		}
		else
		{
			player->setX(getleft() + 8 - player->getWidth());
			player->setDirection(Right);
		}

		player->setDx(0);
		player->setDy(0);
		player->setIsOnStair(true);
	}
	if (getDirection() == 1)
	{
		player->goToStairDownLeft();
	}
	else
	{
		player->goToStairDownRight();
	}
}

Stair::Stair()
{

}


Stair::~Stair()
{
}
