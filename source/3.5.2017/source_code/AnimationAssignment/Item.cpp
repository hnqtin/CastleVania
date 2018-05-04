#include "Item.h"



List<Item*>* Item::items = 0;
List<Item*>* Item::getItems()
{
	if (items == 0)
	{
		items = new List<Item*>();
	}
	return items;
}

void Item::onIntersect(MovableBox * other)
{
	if (other->getCollisionType() == CT_PLAYER)
	{
		this->setAlive(false);
	}
}

Item::Item()
{
	getItems()->_Add(this);
	setCollisionType(CT_ITEM);
}


Item::~Item()
{
}
