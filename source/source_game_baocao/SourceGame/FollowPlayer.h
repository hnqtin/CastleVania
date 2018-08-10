#pragma once
#include"BaseObject.h"
class FollowPlayer
{
	BaseObject* obj;
public:
	FollowPlayer(BaseObject* obj);
	void setDirectionFollowPlayer();
	~FollowPlayer();
};

