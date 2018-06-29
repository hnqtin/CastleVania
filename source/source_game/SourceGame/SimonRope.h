#pragma once
#include"BaseObject.h"

enum SIMON_ROPE_TYPE
{
	SIMON_ROPE_TYPE_1,
	SIMON_ROPE_TYPE_2,
	SIMON_ROPE_TYPE_3
};

struct RopeLocation
{
	int x, y;
};

class SimonRope 
	: public BaseObject
{
private:
	static SimonRope* instance;
	SIMON_ROPE_TYPE simonRopeType;
	GameTime changeColorTime;
public:
	static SimonRope* getInstance();
	RopeLocation locations[3];
	void update() override;
	void render() override;
	SimonRope();
	~SimonRope();
};

