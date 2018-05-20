#include "TileMap.h"
#include<fstream>
using namespace std;


int TileMap::getStageHeight()
{
	return this->worldHeight;
}

int TileMap::getStageWidth()
{
	return this->worldWidth;
}

TileMap::TileMap()
{
}

void TileMap::init(const char * tilesheetPath, const char * matrixPath)
{
	//khoi tao hinh. mo file tilesheet.png
	tilesheet = new Texture(tilesheetPath, 0);

	//khoi tao ma tran tile trong file matrix.txt
	fstream fs(matrixPath);
	fs >> rowCount >> columnCount >> tileWidth >> tileHeight >> tilesheetColumnCount;
	matrix = new int*[rowCount];
	for (size_t rowIndex = 0; rowIndex < rowCount; rowIndex++)
	{
		matrix[rowIndex] = new int[columnCount];
		for (size_t columnIndex = 0; columnIndex < columnCount; columnIndex++)
		{
			fs >> matrix[rowIndex][columnIndex];
		}
	}

	worldHeight = rowCount * tileHeight;
	worldWidth = columnCount * tileWidth;
}



void TileMap::renderTile(int rowIndex, int columnIndex, Camera * camera)
{
	// tinh toa do tile do tren world
	int xW = columnIndex * tileWidth;
	int yW = worldHeight - rowIndex * tileHeight;
	//tinh toa do tile do tren view
	int xV = 0, yV = 0;
	camera->getStageToViewLocation(xW, yW, xV, yV);

	// tim crop rect tu tileindex
	int tileIndex = matrix[rowIndex][columnIndex];
	RECT cropRectInTilesheet;

	cropRectInTilesheet.left = tileWidth * (tileIndex % tilesheetColumnCount);
	cropRectInTilesheet.top = tileHeight * (tileIndex / tilesheetColumnCount);
	cropRectInTilesheet.right = cropRectInTilesheet.left + tileWidth;
	cropRectInTilesheet.bottom = cropRectInTilesheet.top + tileHeight;

	//ve tilesheet da duoc crop len vi tri view
	tilesheet->RenderTexture(xV, yV, &cropRectInTilesheet);
}

void TileMap::renderTiles(int rowBegin, int rowEnd, int columnBegin, int columnEnd, Camera * camera)
{
	if (rowBegin < 0)
		rowBegin = 0;
	if (rowEnd >= rowCount)
		rowEnd = rowCount - 1;
	if (columnBegin < 0)
		columnBegin = 0;
	if (columnEnd >= columnCount)
		columnEnd = columnCount - 1;

	for (int rowIndex = rowBegin;rowIndex <= rowEnd;rowIndex++)
	{
		for (int columnIndex = columnBegin;columnIndex <= columnEnd;columnIndex++)
		{
			renderTile(rowIndex, columnIndex, camera);
		}

	}
}

void TileMap::render(Camera* camera)
{
	int colBegin = camera->getleft() / tileWidth;
	int colEnd = (camera->getRight() + tileWidth - 1) / tileWidth ;

	int rowBegin = (worldHeight - camera->getTop()) / tileHeight ;
	int rowEnd = ((worldHeight - camera->getBottom()) + tileHeight - 1) / tileHeight ;

	renderTiles(rowBegin, rowEnd, colBegin, colEnd, camera);
}


TileMap::~TileMap()
{
}
