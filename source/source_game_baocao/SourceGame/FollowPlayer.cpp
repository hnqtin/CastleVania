#include "FollowPlayer.h"
#include"Player.h"

FollowPlayer::FollowPlayer(BaseObject * obj)
{
	this->obj = obj;
}

void FollowPlayer::setDirectionFollowPlayer()
{
	if (Player::getInstance()->getMidX() - obj->getMidX() < 0)
	{
		obj->setDirection(Left);
	}
	else
	{
		obj->setDirection(Right);
	}
}

FollowPlayer::~FollowPlayer()
{
}
