#pragma once
#include<fstream>
#include<string>
using namespace std;
class ReadFileManager
{
	fstream* fs;
public:
	ReadFileManager(const char* filePath);
	~ReadFileManager();
	int nextInt();
	float nextFloat();
	int linesCount();
	void ignoreLines(int linesIgnore);
};

