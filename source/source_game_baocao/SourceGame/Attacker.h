#pragma once
#include"BaseObject.h"
class Attacker
{
	BaseObject* obj;
public:
	void attackPlayer();
	Attacker(BaseObject* obj);
	~Attacker();
};

