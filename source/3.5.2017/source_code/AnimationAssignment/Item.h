#pragma once
#include "BaseObject.h"
#include"List.h"
class Item :
	public BaseObject
{
	static List<Item*>* items;
public:
	static List<Item*>* getItems();
	void onIntersect(MovableBox* other);
	Item();
	~Item();
};

