#pragma once

class ICameraLimit
{
public:
	virtual int getLeft() { return 0; }
	virtual int getRight() { return 0; }
};