#include "DeathWeapon.h"
#include"SpriteManager.h"
#include"Camera.h"
#include"Player.h"


extern int getRandom(int start, int end);

int DeathWeapon::weaponCounter = 0;

List<DeathWeapon*> DeathWeapon::weapons;

void DeathWeapon::update(float dt)
{
	auto camera = Camera::getInstance();
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
			if (abs(targetX - getX()) < 2)
			{
				setDx(0);
				setDy(0);
				waitDelay.start();
				return;
			}
			state = DEATH_WEAPON_STATE_RUN;
			followPlayer.setDirectionFollowPlayer();
			float moment = getGlobalValue("dead_weapon_moment");
			float v = (targetY - getY()) / (targetX - getX());
			float dx = sqrt(moment*moment / (v*v + 1))* getDirection();
			float dy = abs(v*dx);
			if (getMidY() > player->getMidY())
			{
				dy = -dy;
			}
			setDx(dx);
			setDy(dy);
		}
		break;
	case DEATH_WEAPON_STATE_RUN:
		if (getleft() < camera->getleft() || getRight() > camera->getRight() || getTop() > camera->getTop() || getBottom() < camera->getBottom())
		{
			waitDelay.start();
			state = DEATH_WEAPON_STATE_WAIT;
		}
		if ((getDx() > 0 && (getX() + getDx() > targetX)) ||
			(getDx() < 0 && (getX() + getDx() < targetX)))
		{
			continueRunDelay.start();
			state = DEATH_WEAPON_STATE_CONTINUE_RUN;
		}
		break;
	case DEATH_WEAPON_STATE_CONTINUE_RUN:
		if (getleft() < camera->getleft() || getRight() > camera->getRight() || getTop() > camera->getTop() - 32 || getBottom() < camera->getBottom())
		{
			waitDelay.start();
			state = DEATH_WEAPON_STATE_WAIT;
		}
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
	if (other->getCollisionType() == CT_WEAPON || other->getCollisionType() == CT_SUB_WEAPON)
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

void DeathWeapon::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
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
	int x = getRandom(camera->getleft(), camera->getRight()- getWidth());
	int y = getRandom(camera->getTop() - 32, camera->getBottom()+getHeight());
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
