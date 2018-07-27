#include "VampireBat.h"
#include"Camera.h"
REGISTER_OBJECT_GAME(VampireBat, SI_VAMPIRE_BAT)

extern int getRandom(int start, int end);

void VampireBat::setBossState(BOSS_STATE bossState)
{
	this->bossState = bossState;
}

void VampireBat::update(float dt)
{
	waitDelay.update();
	switch (bossState)
	{
	case BOSS_STATE_INVISIBLE:
	{
		int distance = player->getX() - getX();
		if (distance > getGlobalValue("boss_distance_activ"))
		{
			setAction(BOSS_ACTION_ACTIV);
			setBossState(BOSS_STATE_WAIT);
			waitDelay.start();
		}
		break;
	}
	case BOSS_STATE_WAIT:
		if (waitDelay.isTerminated())
		{
			setBossState(BOSS_STATE_MOVE_FAST);
			calculateXoYoR();
		}
		break;
	case BOSS_STATE_MOVE_FAST:
	{
		int x2, y2;
		calculateM2(r, xo, yo, getX(), getY(), alpha, x2, y2);
		setX(x2);
		setY(y2);
		break;
	}
	case BOSS_STATE_MOVE_SLOW:
		break;
	default:
		break;
	}
}

void VampireBat::calculateXoYoR()
{
	auto camera = Camera::getInstance();

	int x1, y1, x2, y2, x3, y3;

	x1 = getX();
	y1 = getY();

	int x2Min, x2Max;

	if (getX() > player->getX())
	{
		x2Max = x1 - abs((camera->getX() - x1) / 3.0f);
		x2Min = x2Max - abs((camera->getX() - x1) / 3.0f);
	}
	else
	{
		x2Min = x1 + abs((camera->getX() - x1) / 3.0f);
		x2Max = x2Min+ abs((camera->getX() - x1) / 3.0f);
	}

	x2 = getRandom(x2Min, x2Max);
	y2 = getRandom(camera->getBottom(), getY());

	if (getX() > player->getX())
	{
		x3 = camera->getleft();
	}
	else
	{
		x3 = camera->getRight();
	}

	y3 = getRandom(getY(), camera->getBottom());


	calculateCircleFunction(x1, y1, x2, y2, x3, y3, xo, yo, r);
	calculateAlpha(xo, yo, r, getGlobalValue("vampire_bat_fast_momen"), alpha);
}

void VampireBat::calculateM2(int r, int xo, int yo, int x1, int y1, float alpha, int & x2, int & y2)
{
	//goc beta la goc ho boi tam o va diem M1 (x1 y1)
	float tanBeta = abs((float)(y1 - yo)) / abs(x1 - xo);
	float beta = -abs(atan(tanBeta));
	//goc sumCorner la goc hop boi tam  va diem M2 (x2,y2)
	float sumCorner = alpha + beta;
	// deltaY khoang cach y tu M toi truc hoanh duong trong
	float deltaY = r * sin(sumCorner);
	y2 = deltaY + yo;

	// deltaX khoang cach x tu M toi truc tung duong trong
	float deltaX = r * cos(sumCorner);
	x2 + deltaX + xo;
}

void VampireBat::calculateAlpha(int xo, int yo, int r, int momen, float& alpha)
{
	alpha = -abs(2 * asin(momen / 2 * r));
}

void VampireBat::calculateCircleFunction(int x1, int y1, int x2, int y2, int x3, int y3, int & xo, int & yo, int & r)
{
	int a3, b3, c3, d3, a1, b1, c1, d1, a2, b2, c2, d2;

	a1 = -2 * x1;
	b1 = -2 * y1;
	c1 = 1;
	d1 = x1 * x1 + y1 * y1;

	a2 = -2 * x2;
	b2 = -2 * y2;
	c2 = 1;
	d2 = x2 * x2 + y2 * y2;

	a3 = -2 * x3;
	b3 = -2 * y3;
	c3 = 1;
	d3 = x3 * x3 + y3 * y3;

	D3DXMATRIX matrixInp(a1, a2, a3, 0, b1, b2, b3, 0, c1, c2, c3, 0, d1, d2, d3, 0);
	D3DXMATRIX matrixOut;
	D3DXMatrixTranspose(&matrixOut, &matrixInp);

	xo = matrixOut._14;
	yo = matrixOut._24;
	int c = matrixOut._34;

	r = sqrt(xo*xo + yo * yo - c);

}

VampireBat::VampireBat()
{
	player = Player::getInstance();
	waitDelay.init(getGlobalValue("boss_wait_time"));
}


VampireBat::~VampireBat()
{
}
