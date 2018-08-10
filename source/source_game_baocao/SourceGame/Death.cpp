#include "Death.h"
#include"Camera.h"
#include"DeathWeapon.h"
#include"Collision.h"
REGISTER_OBJECT_GAME(Death, SI_DEATH)
extern int getRandom(int start, int end);

void Death::update(float dt)
{
	auto camera = Camera::getInstance();
	auto player = Player::getInstance();
	if (!Collision::AABBCheck(this, camera))
	{
		return;
	}
	if (DeathWeapon::weaponCounter < 4 && createWeaponTime.atTime() && deathState!= DEATH_STATE_INACTIVE)
	{
		auto deathWeapon = new DeathWeapon();
	}
	setDirectionFollowPlayer();
	switch (deathState)
	{
	case DEATH_STATE_INACTIVE:
		setRenderActive(false);
		if (player->getX() < this->getX())
		{
			setRenderActive(true);
			deathState = DEATH_STATE_WAIT;
			waitDelay.start();
		}
		break;
	case DEATH_STATE_WAIT:
		waitDelay.update();
		if (waitDelay.isTerminated())
		{
			deathState = DEATH_STATE_FLY;
			movingDirection = getRandom(0, 1);
			if (movingDirection == 0)
			{
				movingDirection = -1;
			}
			setVy(getGlobalValue("death_vy"));
			setVx(getGlobalValue("death_vx")*movingDirection);
			setDy(0);
			setIsOnGround(false);
		}
		break;
	case DEATH_STATE_FLY:
		Camera::getInstance()->preventMoving = true;
		if (getleft() + getDx() < camera->getleft() && getDx() < 0)
		{
			setVx(getGlobalValue("death_vx"));
		}
		if (getRight() > camera->getRight())
		{
			setVx(-getGlobalValue("death_vx"));
		}

		if (getTop() > camera->getTop())
		{
			setVy(-getVy());
		}

		if (isOnGround())
		{
			deathState = DEATH_STATE_WAIT;
			setVx(0);
			setVy(0);
			waitDelay.start();
		}
		Enemy::update(dt);
		break;
	default:
		break;
	}
}

void Death::setVx(float vx)
{
	Enemy::setVx(vx);
}

void Death::setAlive(bool alive)
{
	if (!alive)
	{
		Camera::getInstance()->preventMoving = false;
		for (int i = 0; i < DeathWeapon::weapons.Count; i++)
		{
			DeathWeapon::weapons[i]->setNeedDelete(true);
		}
	}
	Enemy::setAlive(alive);
}


Death::Death()
{
	waitDelay.init(getGlobalValue("death_wait_delay"));
	createWeaponTime.setTimeDelay(getGlobalValue("death_create_weapon_time"));
	setAy(getGlobalValue("death_ay"));
	deathState = DEATH_STATE::DEATH_STATE_INACTIVE;
}


Death::~Death()
{
}
