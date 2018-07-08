#include "ReadFileManager.h"



ReadFileManager::ReadFileManager(const char* filePath)
{
	fs = new fstream(filePath);
}


ReadFileManager::~ReadFileManager()
{
}

int ReadFileManager::nextInt()
{
	int value;
	*fs >> value;
	return value;
}

float ReadFileManager::nextFloat()
{
	float value;
	*fs >> value;
	return value;
}

int ReadFileManager::linesCount()
{

	int aNumOfLines = 0;
	string aLineStr;
	fs->clear();
	fs->seekg(0, ios::beg);
	while (getline(*fs, aLineStr))
	{
		if (!aLineStr.empty())
			aNumOfLines++;
	}

	fs->clear();
	fs->seekg(0, ios::beg);
	return aNumOfLines;
}

void ReadFileManager::ignoreLines(int linesIgnore)
{
	string s;
	for (int i = 0; i < linesIgnore; i++)
	{
		getline(*fs, s);
	}
}
