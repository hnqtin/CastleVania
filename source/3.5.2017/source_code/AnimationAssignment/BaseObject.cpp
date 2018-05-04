#include "BaseObject.h"
#include"SpriteManager.h"


void BaseObject::update()
{
	if (sprite == 0)
		return;
	if (!isAlive())
		return;
	if (animationDelay->atTime())
	{
		this->sprite->update(actionIndex, actionFrameIndex);
		if (actionFrameIndex == 0)
		{
			onLastFrameAnimation();
		}
	}
	PhysicsBox::update();
}

void BaseObject::performUpdate()
{
	updateLocation();
	update();
}

void BaseObject::render()
{
	if (sprite == 0)
		return;
	if (!isAlive())
		return;
	int xV, yV;
	Camera::getInstance()->getWorldToViewLocation(getX(), getY(), xV, yV);
	xV -= (getCurrentFrameWidth() - getWidth()) / 2;
	yV -= (getCurrentFrameHeight() - getHeight()) / 2;

	if (direction != sprite->img->direction)
	{
		D3DXMATRIX flipMatrix;
		D3DXMatrixIdentity(&flipMatrix);
		flipMatrix._11 = -1;
		flipMatrix._41 = 2 * (xV + getCurrentFrameWidth() / 2);
		DirectXTool::getInstance()->GetSprite()->SetTransform(&flipMatrix);
	}

	this->sprite->render(xV, yV, actionIndex, actionFrameIndex);
	if (direction != sprite->img->direction)
	{
		D3DXMATRIX identityMatrix;
		D3DXMatrixIdentity(&identityMatrix);
		DirectXTool::getInstance()->GetSprite()->SetTransform(&identityMatrix);
	}
}

void BaseObject::onLastFrameAnimation()
{
}


BaseObject::BaseObject()
{
	sprite = 0;
	actionIndex = 0;
	actionFrameIndex = 0;
	animationDelay = new GameTime();
	setInterval(100);
	setAlive(true);
}


BaseObject::~BaseObject()
{
}

Sprite* BaseObject::getSprite()
{
	return this->sprite;
}

void BaseObject::setSprite(Sprite* sprite)
{
	this->sprite = sprite;
}

int BaseObject::getAction()
{
	return actionIndex;
}

int BaseObject::getActionFrameIndex()
{
	return actionFrameIndex;
}

int BaseObject::getCurrentFrameWidth()
{
	return getSprite()->getFrameWidth(actionIndex, actionFrameIndex);
}

int BaseObject::getCurrentFrameHeight()
{
	return  getSprite()->getFrameHeight(actionIndex, actionFrameIndex);
}

void BaseObject::setAction(int actionIndex)
{
	if (this->actionIndex != actionIndex)
	{
		this->actionIndex = actionIndex;
		this->actionFrameIndex = 0;
	}
}

void BaseObject::setActionFrameIndex(int actionFrameIndex)
{
	this->actionFrameIndex = actionFrameIndex;
}

void BaseObject::setInterval(int interval)
{
	this->animationDelay->setTickPerFrame(interval);
}

int BaseObject::getInterval()
{
	return this->animationDelay->getTickPerFrame();
}

Rect * BaseObject::getInitBox()
{
	return initBox;
}

void BaseObject::setInitBox(Rect * initBox)
{
	this->initBox = initBox;
}

void BaseObject::restoreLocation()
{
	set(initBox->getX(), initBox->getY(), initBox->getWidth(), initBox->getHeight());
}





void BaseObject::setPauseAnimation(bool pauseAnimation)
{
	this->pauseAnimation = pauseAnimation;
}

bool BaseObject::isPauseAnimation()
{
	return pauseAnimation;
}

bool BaseObject::isAlive()
{
	return alive;
}

void BaseObject::setAlive(bool alive)
{
	this->alive = alive;
}

bool BaseObject::canCollision()
{
	return isAlive();
}

Direction BaseObject::getDirection()
{
	return direction;
}

void BaseObject::setDirection(Direction direction)
{
	this->direction = direction;
}

void BaseObject::onInit(fstream & fs)
{
}

void BaseObject::setSpriteId(int spriteId)
{
	this->spriteId = spriteId;
	if (spriteId < 0)
	{
		sprite = 0;
	}
	else
	{
		sprite = SpriteManager::getInstance()->getSprites()[spriteId];
	}

}
