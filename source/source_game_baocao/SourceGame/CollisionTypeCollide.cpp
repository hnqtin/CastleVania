#include "CollisionTypeCollide.h"



CollisionTypeCollide::CollisionTypeCollide(COLLISION_TYPE collisionType1, COLLISION_TYPE collisionType2)
{
	this->collisionType1 = collisionType1;
	this->collisionType2 = collisionType2;
}

COLLISION_TYPE CollisionTypeCollide::getCollisionType1()
{
	return this->collisionType1;
}

COLLISION_TYPE CollisionTypeCollide::getCollisionType2()
{
	return this->collisionType2;
}

CollisionTypeCollide::~CollisionTypeCollide()
{
}
