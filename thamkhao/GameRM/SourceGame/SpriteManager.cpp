#include "SpriteManager.h"



SpriteManager * SpriteManager::instance = 0;
SpriteManager * SpriteManager::getInstance()
{
	if (instance == 0)
		instance = new SpriteManager();
	return instance;
}

Sprite ** SpriteManager::getSprites()
{
	return sprites;
}

Sprite * SpriteManager::getSprite(SPRITE_INFO si)
{
	return getInstance()->sprites[si];
}

SpriteManager::SpriteManager()
{
	Texture* enemiesImage = new Texture();
	enemiesImage->Init("Data/Sprites/Enemies/image.png", 0);
	enemiesImage->direction = DIR_LEFT;

	sprites = new Sprite*[SI_COUNT];

	sprites[SI_ROCKMAN] = new Sprite();
	sprites[SI_ROCKMAN]->ReadFromFile("Data/Sprites/rockman/info.simple.txt", "Data/Sprites/rockman/image.png");
	sprites[SI_ROCKMAN]->img->direction = DIR_RIGHT;

	sprites[SI_SIMON] = new Sprite();
	sprites[SI_SIMON]->ReadFromFile("Data/Sprites/simon/info.simple.txt", "Data/Sprites/simon/image.png");
	sprites[SI_SIMON]->img->direction = DIR_RIGHT;

	sprites[SI_LINHNHAY] = new Sprite();
	sprites[SI_LINHNHAY]->ReadFromFile("Data/Sprites/linhnhay/info.simple.txt", "Data/Sprites/linhnhay/image.png");
	sprites[SI_LINHNHAY]->img->direction = DIR_RIGHT;
}


SpriteManager::~SpriteManager()
{
}
