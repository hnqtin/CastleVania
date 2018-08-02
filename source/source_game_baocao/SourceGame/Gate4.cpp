#include "Gate4.h"
#include"ScoreBar.h"
REGISTER_OBJECT_GAME(Gate4, SI_GATE_4);

void Gate4::onIntersect(MovableBox * other)
{
	if (ScoreBar::getInstance()->getBossHealth() <= 0)
	{
		intf->changeLevel(1, 0);
	}
}

Gate4::Gate4()
{
}


Gate4::~Gate4()
{
}
