#include "BonePillar.h"
#include"MermanBullet.h"
REGISTER_OBJECT_GAME (BonePillar, SI_BONE_PILLAR)

void BonePillar::update(float dt)
{
	attackDelay.update();
	switch (bonePillaState)
	{
	case BONEPILLAR_STATE_WAIT:
		if (attackDelay.isTerminated())
		{
			bonePillaState = BONEPILLAR_STATE_ATTACK;
			bulletNumberRemaining = 2;
		}
		break;
	case BONEPILLAR_STATE_ATTACK:
		if (attackTime.atTime())
		{
			MermanBullet* bullet = new MermanBullet();
			bullet->setX(getX());
			bullet->setY(getY()-10);
			bullet->followPlayer.setDirectionFollowPlayer();
			bullet->setVx(bullet->getDirection()* getGlobalValue("mermanbullet_vx"));
			bulletNumberRemaining--;
			if (bulletNumberRemaining == 0)
			{
				attackDelay.start();
				bonePillaState = BONEPILLAR_STATE_WAIT;
			}
		}
		break;
	default:
		break;
	}
}

BonePillar::BonePillar()
{
	bonePillaState = BONEPILLAR_STATE::BONEPILLAR_STATE_WAIT;
	attackDelay.init(getGlobalValue("bonepillar_delay"));
	attackTime.setTimeDelay(getGlobalValue("bonepillar_time"));
	attackDelay.start();
	setHealth(4);
}


BonePillar::~BonePillar()
{
}
