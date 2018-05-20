#pragma once
#include"Texture.h"
#include"Camera.h"
class TileMap
{
	Texture* tilesheet;
	int** matrix;
	int rowCount;
	int columnCount;
	int tilesheetColumnCount;
	int tileWidth;
	int tileHeight;
	int worldHeight;
	int worldWidth;
public:
	int getStageHeight();
	int getStageWidth();
	TileMap();
	void init(const char* tilesheetPath, const char* matrixPath);
	void renderTile(int rowIndex, int columnIndex, Camera* camera);
	void renderTiles(int rowBegin, int rowEnd, int columnBegin, int columnEnd, Camera* camera);
	virtual void render(Camera* camera);
	~TileMap();
};

