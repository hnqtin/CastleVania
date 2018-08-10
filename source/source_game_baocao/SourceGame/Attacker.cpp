#include "Attacker.h"
#include"Player.h"
#include"ScoreBar.h"

void Attacker::attackPlayer()
{
	auto player = Player::getInstance();
	if (!player->blinkDelay.isOnTime() && !player->isDead)
	{
		player->blinkDelay.start();
		player->setVy(getGlobalValue("player_hit_vy"));
		if (!player->getIsOnStair())
		{
			player->setAction(SIMON_PLAYER_ACTION_SIMON_INJURED);
			player->setIsOnGround(false);
			player->setDy(0);
			if (player->getX() > obj->getX())
			{
				player->setVx(getGlobalValue("player_hit_vx"));
			}
			else
			{
				player->setVx(-getGlobalValue("player_hit_vx"));
			}
		}

		ScoreBar::getInstance()->increaseHealth(-1);
		if (ScoreBar::getInstance()->getHealth() <= 0)
		{
			player->isDead = true;
			player->deadDelay.start();
		}
	}
}

Attacker::Attacker(BaseObject* obj)
{
	this->obj = obj;
}


Attacker::~Attacker()
{
}
