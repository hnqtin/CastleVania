#include "IgorEnemy.h"

REGISTER_OBJECT_GAME(IgorEnemy,SI_IGOR)

void IgorEnemy::update()
{
}

IgorEnemy::IgorEnemy()
{
	setPhysicsEnable(false);
	setDy(-1);
}


IgorEnemy::~IgorEnemy()
{
}
