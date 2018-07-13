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
	enemiesImage->direction = Left;

	sprites = new Sprite*[SI_COUNT];


	sprites[SI_SIMON] = new Sprite();
	sprites[SI_SIMON]->ReadFromFile("Data/Sprites/Simon/info.simple.txt", "Data/Sprites/Simon/image.png");
	sprites[SI_SIMON]->img->direction = Right;

#pragma region Enemies

	sprites[SI_ZOMBIE] = new Sprite();
	sprites[SI_ZOMBIE]->readInfo("Data/Sprites/Enemies/zombie.info.txt");
	sprites[SI_ZOMBIE]->img = enemiesImage;

	sprites[SI_PANTHER] = new Sprite();
	sprites[SI_PANTHER]->readInfo("Data/Sprites/Enemies/panther.info.txt");
	sprites[SI_PANTHER]->img = enemiesImage;

	sprites[SI_MERMAN] = new Sprite();
	sprites[SI_MERMAN]->readInfo("Data/Sprites/Enemies/merman.info.txt");
	sprites[SI_MERMAN]->img = enemiesImage;

	sprites[SI_BAT] = new Sprite();
	sprites[SI_BAT]->readInfo("Data/Sprites/Enemies/bat.info.txt");
	sprites[SI_BAT]->img = enemiesImage;

#pragma endregion




	sprites[SI_EXPLOSION_EFFECT] = new Sprite();
	sprites[SI_EXPLOSION_EFFECT]->readInfo("Data/Sprites/Enemies/explosion.info.txt");
	sprites[SI_EXPLOSION_EFFECT]->img = enemiesImage;

	sprites[SI_WEAPON] = new Sprite();
	sprites[SI_WEAPON]->ReadFromFile("Data/Sprites/SimonWeapon/weapon.info.txt", "Data/Sprites/SimonWeapon/image.png");
	sprites[SI_WEAPON]->img->direction = Right;

	sprites[SI_GATE2] = new Sprite();
	sprites[SI_GATE2]->ReadFromFile("Data/Sprites/Gate2/info.simple.txt", "Data/Sprites/Gate2/image.png");
	sprites[SI_GATE2]->img->direction = Right;

	sprites[SI_MISC] = new Sprite();
	sprites[SI_MISC]->ReadFromFile("Data/Sprites/Misc/misc.info.txt", "Data/Sprites/Misc/misc.png");
	sprites[SI_MISC]->img->direction = Right;
}


SpriteManager::~SpriteManager()
{
}
