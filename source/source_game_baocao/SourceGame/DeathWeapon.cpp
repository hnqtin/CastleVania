#include "DeathWeapon.h"
#include"SpriteManager.h"
#include"Camera.h"
#include"Player.h"


extern int getRandom(int start, int end);

int DeathWeapon::weaponCounter = 0;

List<DeathWeapon*> DeathWeapon::weapons;

void DeathWeapon::update(float dt)
{
	waitDelay.update();
	continueRunDelay.update();
	switch (state)
	{
	case DEATH_WEAPON_STATE_WAIT:
		setDx(0);
		setDy(0);
		if (waitDelay.isTerminated())
		{
			auto player = Player::getInstance();
			targetX = player->getX();
			targetY = player->getY();
			if (abs(targetX - getX()) < 10)
			{
				waitDelay.start();
				return;
			}
			state = DEATH_WEAPON_STATE_RUN;
			followPlayer.setDirectionFollowPlayer();
			float dx = getGlobalValue("dead_weapon_dx")*getDirection();
			float dy = (targetY - getY())*dx / (targetX - getX());
			setDx(dx);
			setDy(dy);
		}
		break;
	case DEATH_WEAPON_STATE_RUN:

		if ((getDx() > 0 && (getX() + getDx() > targetX)) ||
			(getDx() < 0 && (getX() + getDx() < targetX)))
		{
			continueRunDelay.start();
			state = DEATH_WEAPON_STATE_CONTINUE_RUN;
		}
		break;
	case DEATH_WEAPON_STATE_CONTINUE_RUN:
		if (continueRunDelay.isTerminated())
		{
			waitDelay.start();
			state = DEATH_WEAPON_STATE_WAIT;
		}
		break;
	default:
		break;
	}
	//AdditionalObject::update(dt);
}

void DeathWeapon::onIntersect(MovableBox * other)
{
	if (other == Player::getInstance())
	{
		attacker.attackPlayer();
	}
	if (other->getCollisionType() == CT_WEAPON)
	{
		playerWeaponVictim.onWeaponAttack();
	}
}

void DeathWeapon::setHealth(int health)
{
	this->health = health;
}


int DeathWeapon::getHealth()
{
	return health;
}

void DeathWeapon::setAlive(bool alive)
{
	if (!alive)
	{
		setNeedDelete(true);
	}
}

DeathWeapon::DeathWeapon() :
	followPlayer(this),
	attacker(this), 
	playerWeaponVictim(dynamic_cast<IPlayerWeaponVictim*>(this))
{
	auto camera = Camera::getInstance();
	setSprite(SpriteManager::getSprite(SI_DEATH_WEAPON));
	setAction(0);
	waitDelay.init(getGlobalValue("deathweapon_wait_delay"));
	continueRunDelay.init(getGlobalValue("deathweapon_continue_run_delay"));
	waitDelay.start();
	state = DEATH_WEAPON_STATE_WAIT;
	int x = getRandom(camera->getleft(), camera->getRight());
	int y = getRandom(camera->getTop() - 32, camera->getBottom());
	setX(x);
	setY(y);
	setCollisionType(CT_ENEMY);
	setHealth(1);
	setWidth(getCurrentFrameWidth());
	setHeight(getCurrentFrameHeight());
	weaponCounter++;
	weapons._Add(this);
}


DeathWeapon::~DeathWeapon()
{
	weapons._Remove(this);
	weaponCounter--;
}
