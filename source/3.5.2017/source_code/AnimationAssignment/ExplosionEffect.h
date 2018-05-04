#pragma once
#include"List.h"
#include"BaseObject.h"
#include"DelayTime.h"
class ExplosionEffect :
	public BaseObject
{
	DelayTime timeToLive;
	static List<ExplosionEffect*>* explosionEffects;
public:
	static List<ExplosionEffect*>* getExplosionEffects();
	void update();
	void render();
	ExplosionEffect();
	~ExplosionEffect();
};

