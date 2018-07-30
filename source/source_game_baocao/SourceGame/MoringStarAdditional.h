#pragma once
#include "AdditionalObject.h"
class MoringStarAdditional :
	public AdditionalObject
{
public:
	MoringStarAdditional();
	void onIntersect(MovableBox* other);
	~MoringStarAdditional();
};

