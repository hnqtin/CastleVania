#pragma once
#include "Animation.h"
#include "Texture.h"
#include <fstream>
#include <string>
using namespace std;

class Sprite
{
public:
	Animation* anims;
	int animCount;
	Texture* img;
	Sprite();
	~Sprite();
	void render(int x, int y, int action, int frameIndex);
	void update(int actionIndex, int &frameIndex);
	void ReadFromFile(char * infopath, char * imagepath);
	void readInfo(const char* infoPath);
	void initFromSingleFrame(const char* imagePath);

	int getFrameWidth(int actionIndex, int actionFrameIndex);
	int getFrameHeight(int actionIndex, int actionFrameIndex);
};

