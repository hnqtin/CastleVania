#pragma once
#include "EnemyObject.h"
class EagleEnemy :
	public EnemyObject
{
public:
	void update();
	bool canCollision();
	EagleEnemy();
	~EagleEnemy();
};

