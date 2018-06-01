#include "Bat.h"
#include"Collision.h"
REGISTER_OBJECT_GAME(Bat, SI_BAT)

bool Bat::isActivity = false;

void Bat::onInit(fstream & fs)
{
	int x, y, width, height, direction;
	string name;
	fs >> name >> x >> name >> y >> name >> width >> name >> height >> name >> direction;
	discoverSpace.set(x, y, width, height);
	discoverDirection = (Direction)direction;
	invisibleDelay.init(getGlobalValue("bat_invisible_delay"));
}

void Bat::setBatState(BAT_STATE batState)
{
	this->batState = batState;
}

void Bat::update()
{
	switch (batState)
	{
	case BAT_STATE_INVISIBLE:
		setRenderActive(false);
		// dieu kien de no qua trang thai doi
		if (Collision::AABBCheck(&discoverSpace, Player::getInstance())
			&& !isActivity
			&& Player::getInstance()->getDirection() == discoverDirection
			)
		{
			// bat dau tinh thoi gian doi
			invisibleDelay.start();
			setBatState(BAT_STATE_WAIT);
			// de ngan can con khac hien
			isActivity = true;
		}
		break;
	case BAT_STATE_WAIT:
		invisibleDelay.update();

		if (invisibleDelay.isTerminated())
		{
			setBatState(BAT_STATE_VISIBLE);
			setDx(-discoverDirection * getGlobalValue("bat_dx"));
			setDirection(-discoverDirection);
			setRenderActive(true);
		}
		break;
	case BAT_STATE_VISIBLE:
	{
		int d = getGlobalValue("bat_bankinh");
		alpha += 1;
		if (alpha >= 360)
		{
			alpha -= 360;
		}
		setY(getInitBox()->getY() + d * sin(alpha * 0.1));
		Enemy::update();
		if (!Collision::AABBCheck(this, Camera::getInstance()))
		{
			setBatState(BAT_STATE_INVISIBLE);
			setDx(0);
			isActivity = false;
			auto initBox = getInitBox();
			setLocation(initBox->getX(), initBox->getY());
			setRenderActive(false);
		}
		break;
	}
	default:
		break;
	}

}
void Bat::onCollision(MovableBox * other, int nx, int ny, float collisionTime)
{
	Enemy::onCollision(other, nx, ny, collisionTime);
}

void Bat::restoreLocation()
{
	BaseObject::restoreLocation();
	int direction = getDirection();
	if (direction == -1)
	{
		setBatState(BAT_STATE::BAT_STATE_VISIBLE);
	}
	else
	{
		setBatState(BAT_STATE::BAT_STATE_INVISIBLE);
	}
	setPhysicsEnable(false);
	alpha = 0;
	setAction(1);
	setDx(-0.5);

}

Bat::Bat()
{
	setPhysicsEnable(false);
	alpha = 0;
	setAction(BAT_ACTION_FLY);
	setBatState(BAT_STATE::BAT_STATE_INVISIBLE);
	//setDx(-0.5);
	setDirection(Left);
}

Bat::~Bat()
{
}
