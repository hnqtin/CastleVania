#include "MermanBullet.h"
#include"Enemy.h"
#include"ScoreBar.h"
MermanBullet::MermanBullet()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID_MERMAN_BULLET);
	setWidth(getSprite()->getFrameWidth(0, 0));
	setHeight(getSprite()->getFrameHeight(0, 0));
	setCollisionType(CT_ENEMY);
	setAy(0);
}


MermanBullet::~MermanBullet()
{
}

void MermanBullet::onIntersect(MovableBox * other)
{
	//xu ly khi enemy cham vao player
	auto player = Player::getInstance();
	if (other == player && !player->blinkDelay.isOnTime() && canAttackPlayer() && !player->isDead)
	{
		ScoreBar::getInstance()->increaseHealth(-1);
		if (ScoreBar::getInstance()->getHealth() <= 0)
		{
			player->isDead = true;
			player->deadDelay.start();
		}

		auto camera = Camera::getInstance();
		player->blinkDelay.start();
		player->setVy(getGlobalValue("player_hit_vy"));
		if (!player->getIsOnStair())
		{
			player->setAction(SIMON_PLAYER_ACTION_SIMON_INJURED);
			player->setIsOnGround(false);
			player->setDy(0);
			if (player->getX() > this->getX())
			{
				player->setVx(getGlobalValue("player_hit_vx"));
			}
			else
			{
				player->setVx(-getGlobalValue("player_hit_vx"));
			}
		}
	}
}

void MermanBullet::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
}
