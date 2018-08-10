#include "Sprite.h"
#include "GameTime.h"
#include"Function.h"

Sprite::Sprite()
{
}


Sprite::~Sprite()
{
}

void Sprite::render(int x, int y, int actionIndex, int frameIndex)
{
	img->RenderTexture(x, y, &anims[actionIndex].frames[frameIndex]);
}

void Sprite::update(int actionIndex, int &frameIndex)
{
	anims[actionIndex].next(frameIndex);
}

void Sprite::ReadFromFile(const char * infopath, const char * imagepath)
{
	int r, g, b;

	ifstream fs(infopath);
	ignoreLineIfstream(fs, 1);
	fs >> r >> g >> b;

	ignoreLineIfstream(fs, 2);
	fs >> animCount;

	int frameCount;
	float x, y, w, h;
	anims = new Animation[animCount];
	ignoreLineIfstream(fs, 3);
	for (int i = 0; i < animCount; i++)
	{
		ignoreLineIfstream(fs, 4);
		fs >> frameCount;
		anims[i].frameCount = frameCount;
		anims[i].frames = new RECT[frameCount];
		ignoreLineIfstream(fs, 4);
		for (int j = 0; j < frameCount; j++)
		{
			fs >> x >> y >> w >> h;
			anims[i].frames[j].left = x;
			anims[i].frames[j].top = y;
			anims[i].frames[j].right = x + w;
			anims[i].frames[j].bottom = y + h;
		}

		ignoreLineIfstream(fs, 3);
	}

	img = new Texture();
	img->Init(imagepath, D3DCOLOR_XRGB(r, g, b));
}

void Sprite::readInfo(const char * infoPath)
{

	int r, g, b;

	ifstream fs(infoPath);
	ignoreLineIfstream(fs, 1);
	fs >> r >> g >> b;

	ignoreLineIfstream(fs, 2);
	fs >> animCount;

	int frameCount;
	float x, y, w, h;
	anims = new Animation[animCount];
	ignoreLineIfstream(fs, 3);
	for (int i = 0; i < animCount; i++)
	{
		ignoreLineIfstream(fs, 4);
		fs >> frameCount;
		anims[i].frameCount = frameCount;
		anims[i].frames = new RECT[frameCount];
		ignoreLineIfstream(fs, 4);
		for (int j = 0; j < frameCount; j++)
		{
			fs >> x >> y >> w >> h;
			anims[i].frames[j].left = x;
			anims[i].frames[j].top = y;
			anims[i].frames[j].right = x + w;
			anims[i].frames[j].bottom = y + h;
		}

		ignoreLineIfstream(fs, 3);
	}
}

void Sprite::initFromSingleFrame(const char * imagePath)
{
	img = new Texture();
	img->Init(imagePath, D3DCOLOR_ARGB(0, 0, 0, 0));
	animCount = 1;
	anims = new Animation[animCount];
	anims[0].frameCount = 1;
	anims[0].frames = new RECT[anims[0].frameCount];
	anims[0].frames[0].left = 0;
	anims[0].frames[0].top = 0;
	anims[0].frames[0].right = img->Width;
	anims[0].frames[0].bottom = img->Height;

}

int Sprite::getFrameWidth(int actionIndex, int actionFrameIndex)
{
	RECT frame = anims[actionIndex].frames[actionFrameIndex];
	return frame.right - frame.left;
}

int Sprite::getFrameHeight(int actionIndex, int actionFrameIndex)
{
	RECT frame = anims[actionIndex].frames[actionFrameIndex];
	return frame.bottom - frame.top;
}
