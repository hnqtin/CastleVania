#include "Merman.h"
#include "Player.h"
#include"MermanBullet.h"

REGISTER_OBJECT_GAME(Merman, SI_MERMAN)



void Merman::setMermanState(MERMAN_STATE mermanState)
{
	this->mermanState = mermanState;
}

MERMAN_STATE Merman::getMermanState()
{
	return this->mermanState;
}


void Merman::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	if (ny != -1)
	{
		Enemy::onCollision(other, nx, ny, collisionTime);
	}
	if (nx != 0)
	{
		setDirection((Direction)nx);
	}
}

void Merman::restoreLocation()
{
	mermanState = MERMAN_STATE_INVISIBLE;
	setRenderActive(false);
	setDx(0);
	setVx(0);
	Enemy::restoreLocation();
}

void Merman::update(float dt)
{
	int d = getGlobalValue("merman_distance_to_activ");
	switch (mermanState)
	{
	case MERMAN_STATE_INVISIBLE:
		setVx(0);
		if (abs(Player::getInstance()->getMidX() - getMidX()) < d)
		{
			setVy(getGlobalValue("merman_vy_jump"));
			setPhysicsEnable(true);
			setRenderActive(true);
			setMermanState(MERMAN_STATE_JUMP);
		}
		break;
	case MERMAN_STATE_JUMP:
		setVx(0);
		if (isOnGround())
		{
			setAction(MERMAN_ACTION::MERMAN_ACTION_RUN);
			setDirectionFollowPlayer();
			setMermanState(MERMAN_STATE_RUN);
			runDelay.start();
		}
		Enemy::update(dt);
		break;
	case MERMAN_STATE_RUN:
		runDelay.update();
		setVx(getGlobalValue("merman_vx")*getDirection());
		Enemy::update(dt);
		if (runDelay.isTerminated())
		{
			setDirectionFollowPlayer();
			setMermanState(MERMAN_STATE_ATTACK);
			attackDelay.start();
			MermanBullet* bullet = new MermanBullet();
			bullet->setX(getX());
			bullet->setY(getY());
			bullet->setDirection(getDirection());
			bullet->setVx(getDirection()* getGlobalValue("mermanbullet_vx"));
		}
		break;
	case MERMAN_STATE_ATTACK:
		setVx(0);
		attackDelay.update();
		Enemy::update(dt);
		
		if (attackDelay.isTerminated())
		{
			setDirectionFollowPlayer();
			setMermanState(MERMAN_STATE_RUN);
			runDelay.start();
		}
		break;
	default:
		break;
	}
}

Merman::Merman()
{
	setMermanState(MERMAN_STATE::MERMAN_STATE_INVISIBLE);
	setRenderActive(false);
	setPhysicsEnable(false);
	runDelay.init(getGlobalValue("merman_run_delay"));
	attackDelay.init(getGlobalValue("merman_attack_delay"));
}


Merman::~Merman()
{
}
