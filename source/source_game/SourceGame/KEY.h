#pragma once
#include"Keyboard.h"
class KEY
{
public:
	bool	isLeftDown,
		isRightDown,
		isPDown,
			isJumpDown,
			isPreviousJumpDown,
			isJumpPress,
			isUpDown,
			isPreviousUpDown,
			isUpPress,
			isDownDown,
			isPreviousDownDown,
			isDownPress,
			isMoveDown,
			isAttackDown,
			isPreviousAttackDown,
			isAttackPress;

	static KEY* instance;
	static KEY* getInstance();

	void update();
	
	KEY();
	~KEY();
};

