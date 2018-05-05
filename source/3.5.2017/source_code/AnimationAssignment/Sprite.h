#pragma once
#include "Animation.h"
#include "Texture.h"
#include <fstream>
#include <string>
using namespace std;

class Sprite
{
public:
	// danh sach animation trong sprite. Vi du sprite simon co cac animation nhay, chay
	Animation* anims;
	// so animation
	int animCount;
	// hinh de hien thi animation
	Texture* img;
	Sprite();
	~Sprite();

	// ve animation
	// x : vi tri x
	// y : vi tri y
	// action : hanh dong dang duoc ve
	// frameIndex : frame cua action duoc ve
	void render(int x, int y, int action, int frameIndex);
	// update animation hien tai
	void update(int actionIndex, int &frameIndex);
	// khoi tao sprite bang doc file
	void ReadFromFile(char * infopath, char * imagepath);
	void readInfo(const char* infoPath);
	void initFromSingleFrame(const char* imagePath);

	int getFrameWidth(int actionIndex, int actionFrameIndex);
	int getFrameHeight(int actionIndex, int actionFrameIndex);
};

