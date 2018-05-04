#include "QuadTreeNode.h"
#include"Collision.h"


QuadTreeNode * QuadTreeNode::topLeftNode()
{
	return TL;
}

QuadTreeNode * QuadTreeNode::topRightNode()
{
	return TR;
}

QuadTreeNode * QuadTreeNode::bottomLeftNode()
{
	return BL;
}

QuadTreeNode * QuadTreeNode::bottomRightNode()
{
	return BR;
}

void QuadTreeNode::setTopLeftNode(QuadTreeNode * tl)
{
	TL = tl;
}

void QuadTreeNode::setTopRightNode(QuadTreeNode * tr)
{
	TR = tr;
}

void QuadTreeNode::setBottomLeftNode(QuadTreeNode * bl)
{
	BL = bl;
}

void QuadTreeNode::setBottomRightNode(QuadTreeNode * br)
{
	BR = br;
}

int QuadTreeNode::getObjectsCount()
{
	return objectsCount;
}

void QuadTreeNode::setObjectsCount(int objectsCount)
{
	this->objectsCount = objectsCount;
}

BaseObject ** QuadTreeNode::getObjects()
{
	return objects;
}

void QuadTreeNode::setObjects(BaseObject ** objects)
{
	this->objects = objects;
}

void QuadTreeNode::fillObject(CollisionsObjectCollection * collection, Rect * viewport)
{
	if (!Collision::AABBCheck(this, viewport))
		return;
	if (TL != NULL)
	{
		TL->fillObject(collection, viewport);
		TR->fillObject(collection, viewport);
		BL->fillObject(collection, viewport);
		BR->fillObject(collection, viewport);
		return;
	}
	BaseObject* obj;
	for (size_t i = 0; i < objectsCount; i++)
	{
		obj = objects[i];
		collection->addObject(obj);
	}
}

int QuadTreeNode::getId()
{
	return id;
}

void QuadTreeNode::setId(int id)
{
	this->id = id;
}

QuadTreeNode::QuadTreeNode()
{
	TL = TR = BL = BR = NULL;
	objects = 0;
}


QuadTreeNode::~QuadTreeNode()
{
}
