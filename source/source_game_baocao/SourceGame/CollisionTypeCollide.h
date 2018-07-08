#pragma once
#include"MovableBox.h"
class CollisionTypeCollide
{
	COLLISION_TYPE collisionType1;
	COLLISION_TYPE collisionType2;
public:
	CollisionTypeCollide(COLLISION_TYPE collisionType1, COLLISION_TYPE collisionType2);
	COLLISION_TYPE getCollisionType1();
	COLLISION_TYPE getCollisionType2();
	~CollisionTypeCollide();
};

