#include "KEY.h"

DWORD getKeyChar(char keyChar)
{
	return ((int)keyChar - 'a') + 0x41;
}

KEY * KEY::instance = 0;
KEY * KEY::getInstance()
{
	if (instance == 0)
		instance = new KEY();
	return instance;
}

void KEY::update()
{
	isUpDown = GetAsyncKeyState(VK_UP);
	isPDown = GetAsyncKeyState(VK_DOWN);
	isUpPress = isUpDown && !isPreviousUpDown;
	isPreviousUpDown = isUpDown;

	isDownDown = GetAsyncKeyState(VK_DOWN);
	isDownPress = isDownDown && !isPreviousDownDown;
	isPreviousDownDown = isDownDown;

	isLeftDown = GetAsyncKeyState(VK_LEFT);
	isRightDown = GetAsyncKeyState(VK_RIGHT); 

	isJumpDown = GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(getKeyChar('x'));
	isJumpPress = isJumpDown && !isPreviousJumpDown;
	isPreviousJumpDown = isJumpDown;

	isAttackDown = GetAsyncKeyState(getKeyChar('z'));
	isAttackPress = isAttackDown && !isPreviousAttackDown;
	isPreviousAttackDown = isAttackDown;

	isMoveDown = isLeftDown || isRightDown;

}

KEY::KEY()
{
	isPreviousJumpDown = isPreviousAttackDown = false;
}


KEY::~KEY()
{
}
