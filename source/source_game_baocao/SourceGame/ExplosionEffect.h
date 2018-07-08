#pragma once
#include "AdditionalObject.h"
class ExplosionEffect :
	public AdditionalObject
{
public:
	void update(float dt) override;
	ExplosionEffect();
	~ExplosionEffect();
};

