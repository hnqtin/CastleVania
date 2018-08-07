#include "RedSkeleton.h"

REGISTER_OBJECT_GAME(RedSkeleton, SI_RED_SKELETON)
//
//void RedSkeleton::update(float dt)
//{
//	switch (redskeletonState)
//	{
//	case RED_SKELETION_STATE_RUN:
//		break;
//	case RED_SKELETION_STATE_DIE:
//		break;
//	default:
//		break;
//	}
//}


RedSkeleton::RedSkeleton()
{
	setDx(-5);
}


RedSkeleton::~RedSkeleton()
{
}
