#include "Torch.h"
REGISTER_OBJECT_GAME(Torch, SI_TORCH)

void Torch::update(float dt)
{
	BaseObject::update(dt);
}

void Torch::render()
{
	BaseObject::render();
}

void Torch::onIntersect(MovableBox * other)
{
	if (other->getCollisionType() == CT_WEAPON)
	{
		this->setAlive(false);
	}
}

void Torch::restoreLocation()
{
}

Torch::Torch()
{
	setSprite(SpriteManager::getSprite(SI_MISC));
	setAction(MISC_SPRITE_ID::MISC_SPRITE_ID_TORCH);
}


Torch::~Torch()
{
}
