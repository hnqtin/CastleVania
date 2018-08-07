#include "SkeletonWeapon.h"
#include<math.h>
#include"Player.h"
#include"ScoreBar.h"
void SkeletonWeapon::update(float dt)
{
	if (timeRotation.atTime())
	{
		alpha += 3.14/4;
		if (alpha >= 2 * 3.14)
		{
			alpha = 0;
		}
	}
	MovableObject::update(dt);
	
}

void SkeletonWeapon::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
}

void SkeletonWeapon::onIntersect(MovableBox * other)
{
	////xu ly khi enemy cham vao player
	//auto player = Player::getInstance();
	//if (other == player && !player->blinkDelay.isOnTime() && !player->isDead)
	//{
	//	ScoreBar::getInstance()->increaseHealth(-1);
	//	if (ScoreBar::getInstance()->getHealth() <= 0)
	//	{
	//		player->isDead = true;
	//		player->deadDelay.start();
	//	}
	//	player->blinkDelay.start();
	//	player->setVy(getGlobalValue("player_hit_vy"));
	//	if (!player->getIsOnStair())
	//	{
	//		player->setAction(SIMON_PLAYER_ACTION_SIMON_INJURED);
	//		player->setIsOnGround(false);
	//		player->setDy(0);
	//		if (player->getX() > this->getX())
	//		{
	//			player->setVx(getGlobalValue("player_hit_vx"));
	//		}
	//		else
	//		{
	//			player->setVx(-getGlobalValue("player_hit_vx"));
	//		}
	//	}
	//}
}

void SkeletonWeapon::render()
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


	this->getSprite()->render(xV, yV, 0, 0);
	D3DXMatrixIdentity(&rotationMatrix);
	DirectXTool::getInstance()->GetSprite()->SetTransform(&rotationMatrix);

	//if (direction != sprite->img->direction)
	//{
	//	D3DXMATRIX identityMatrix;
	//	D3DXMatrixIdentity(&identityMatrix);
	//	DirectXTool::getInstance()->GetSprite()->SetTransform(&identityMatrix);
	//}
}

SkeletonWeapon::SkeletonWeapon()
{
	setSprite(SpriteManager::getSprite(SI_SKELETON_WEAPON));
	setWidth(getCurrentFrameWidth());
	setHeight(getCurrentFrameHeight());
	timeRotation.setTimeDelay(20);
	setCollisionType(CT_ENEMY);
}


SkeletonWeapon::~SkeletonWeapon()
{
}
