#pragma once
#include"BaseObject.h"

enum MORNINGSTAR_TYPE
{
	MORNINGSTAR_TYPE_1,
	MORNINGSTAR_TYPE_2,
	MORNINGSTAR_TYPE_3,
	MORNINGSTAR_TYPE_COUNT
};

struct RopeLocation
{
	int x, y;
};

class MorningStar 
	: public BaseObject
{
private:
	static MorningStar* instance;
	MORNINGSTAR_TYPE morningStarType;
	GameTime changeColorTime;
	bool canCreateMorningStarAttack;
public:
	void setType(MORNINGSTAR_TYPE morningStarType);
	void increaseType();
	void resetType();
	static MorningStar* getInstance();
	RopeLocation locations[3];
	void update(float dt) override;
	void render() override;
	MorningStar();
	~MorningStar();
};

