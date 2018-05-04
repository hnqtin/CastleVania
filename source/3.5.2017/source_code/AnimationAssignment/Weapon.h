#pragma once
#include "BaseObject.h"
#include"List.h"
#include"DelayTime.h"
class Weapon :
	public BaseObject
{
	static List<Weapon*>* weapons;
	DelayTime aliveDelay;
public:
	static List<Weapon*>* getWeapons();
	void update();
	Weapon();
	~Weapon();
	void onIntersect(MovableBox* other);

};

