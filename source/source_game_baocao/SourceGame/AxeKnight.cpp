#include "AxeKnight.h"
#include"Player.h"
#include"AxeKnightWeapon.h"
#include<math.h>
#include"Collision.h"
extern int getRandom(int start, int end);
REGISTER_OBJECT_GAME(AxeKnight, SI_AXE_KNIGHT)


void AxeKnight::update(float dt)
{
		if (throwTime.atTime())
	{
		auto weapon = new AxeKnightWeapon();
		weapon->setDirection(getDirection());
		weapon->setX(getX());
		weapon->startX = getX();
		weapons._Add(weapon);
		int selection = getRandom(1, 2);
		if (selection == 1)
		{
			weapon->setY(getY());
		}
		else
		{
			weapon->setY(getBottom() + weapon->getHeight()+5);
		}
	}

	for (size_t i = 0; i < weapons.Count; i++)
	{
		if (Collision::AABBCheck(this, weapons[i]) && weapons[i]->axeKnightWeaponState== AXEKNIGHTWEAPON_WEAPON_STATE_GO_RETURN)
		{
			auto weapon = weapons[i];
			weapon->setNeedDelete(true);
			weapons._Remove(weapon);
			i--;
		}
	}

	setDirectionFollowPlayer();
	auto player = Player::getInstance();
	int currentDistance = abs(getMidX() - player->getMidX());
	int distanceMin = getGlobalValue("axeknight_distance_min");
	int distanceMax = getGlobalValue("axeknight_distance_max");
	//chay lui
	if (getDx()*getDirection() < 0)
	{
		if (currentDistance > distanceMax)
		{
			setDx(getDirection()*getGlobalValue("axeknight_dx"));
		}
	}
	else
	{
		if (currentDistance < distanceMin)
		{
			setDx(-getDirection()*getGlobalValue("axeknight_dx"));
		}
	}
	setVy(getVy() + getAy()*dt);
	setDy(getVy()*dt);
}

void AxeKnight::updateLocation()
{
	setX(getX() + getDx());
	setY(getY() + getDy());
}

void AxeKnight::restoreLocation()
{
	Enemy::restoreLocation();
}

void AxeKnight::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	Enemy::onCollision(other, nx, ny, collisionTime);
	if (nx != 0)
	{
		setDx(nx*getGlobalValue("axeknight_dx"));
	}
}

AxeKnight::AxeKnight()
{
	setDx(getGlobalValue("axeknight_dx"));
	throwTime.setTimeDelay(getGlobalValue("axeknight_throw_time"));
	setDirection(Left);
	setHealth(4);
}


AxeKnight::~AxeKnight()
{
}
