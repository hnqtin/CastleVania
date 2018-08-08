#pragma once
#include "Enemy.h"
class MedusaHead :
	public Enemy
{
	float alpha;
public:
	void update(float dt);
	void onInit(fstream& fs, int worldHeight) override;
	MedusaHead();
	~MedusaHead();
};

