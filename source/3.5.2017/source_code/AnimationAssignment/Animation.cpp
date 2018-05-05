#include "Animation.h"

Animation::Animation()
{
}

Animation::~Animation()
{
}
//goi trong phuong thuc cap nhat
void Animation::next(int &index)
{
	index++;
	if (index >= frameCount)
		index = 0;
}
