#include "MedusaHead.h"

REGISTER_OBJECT_GAME (MedusaHead,SI_MEDUSA_HEAD)

void MedusaHead::update(float dt)
{
	alpha -= 0.05;
	if (alpha < 0)
	{
		alpha = 2*3.14;
	}

	setY(getGlobalValue("medusahead_r")* sin(alpha) + getInitBox()->getY());
	setDx(getDirection()*getGlobalValue("medusahead_dx"));
}

void MedusaHead::onInit(fstream & fs, int worldHeight)
{
	setDirectionFollowPlayer();
}

MedusaHead::MedusaHead()
{
	
}


MedusaHead::~MedusaHead()
{
}
