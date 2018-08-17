#include "AxeKnightWeapon.h"
#include<math.h>
#include"Player.h"

void AxeKnightWeapon::onIntersect(MovableBox * other)
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

void AxeKnightWeapon::setHealth(int health)
{
	this->health = health;
}

int AxeKnightWeapon::getHealth()
{
	return health;
}

void AxeKnightWeapon::setAlive(bool alive)
{
	BaseObject::setAlive(alive);
}

void AxeKnightWeapon::update(float dt)
{
	if (timeRotation.atTime())
	{
		alpha -= 3.14 / 4;
		if (alpha <=0)
		{
			alpha += 2 * 3.14;
		}
	}

	switch (axeKnightWeaponState)
	{
	case AXEKNIGHTWEAPON_WEAPON_STATE_GO_HEAD:
		setDx(getDirection());
		if (abs(getX() - startX) > getGlobalValue("axeknightweapon_max_distance"))
		{
			axeKnightWeaponState = AXEKNIGHTWEAPON_WEAPON_STATE_GO_RETURN;
		}
		break;
	case AXEKNIGHTWEAPON_WEAPON_STATE_GO_RETURN:
		setDx(-getDirection());
		break;
	default:
		break;
	}

}

void AxeKnightWeapon::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
}

void AxeKnightWeapon::render()
{
	if (!isAlive())
		return;
	if (!getRenderActive())
		return;
	int xV, yV;
	Camera::getInstance()->getWorldToViewLocation(getX(), getY(), xV, yV);
	xV -= (getCurrentFrameWidth() - getWidth()) / 2;
	yV -= (getCurrentFrameHeight() - getHeight()) / 2;



	D3DXMATRIX rotationMatrix;
	D3DXMatrixIdentity(&rotationMatrix);

	auto c = cos(alpha), s = sin(alpha);
	auto xo = xV + getCurrentFrameWidth() / 2;
	auto yo = yV + getCurrentFrameHeight() / 2;

	rotationMatrix._11 = c;
	rotationMatrix._21 = -s;
	rotationMatrix._41 = -c * xo + s * yo + xo;
	rotationMatrix._12 = s;
	rotationMatrix._22 = c;
	rotationMatrix._42 = -s * xo - c * yo + yo;
	DirectXTool::getInstance()->GetSprite()->SetTransform(&rotationMatrix);


	this->getSprite()->render(xV, yV, getAction(), 0);
	D3DXMatrixIdentity(&rotationMatrix);
	DirectXTool::getInstance()->GetSprite()->SetTransform(&rotationMatrix);

}

AxeKnightWeapon::AxeKnightWeapon() :
	attacker(this),
	playerWeaponVictim(dynamic_cast<IPlayerWeaponVictim*>(this))
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID_ITEM_AXE);
	setWidth(getCurrentFrameWidth());
	setHeight(getCurrentFrameHeight());
	setPhysicsEnable(false);
	setCollisionType(CT_ENEMY);
	timeRotation.setTimeDelay(50);
	alpha = 2 * 3.14;
	axeKnightWeaponState = AXEKNIGHTWEAPON_WEAPON_STATE_GO_HEAD;
	setHealth(1);
}


AxeKnightWeapon::~AxeKnightWeapon()
{
}
