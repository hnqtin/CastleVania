#pragma once
#include<string>
#include<Windows.h>
using namespace std;
class Logger
{
public:
	virtual void Log(const int &value) {}
	virtual void Log(const DWORD &value) {}
	virtual void Log(const char &value) {}
	virtual void Log(const char* &value) {}
	virtual void Log(const double &value) {}
	virtual void Log(const float &value) {}
	virtual void Log(const string &value) {}
	virtual void LogLine(const int &value) {}
	virtual void LogLine(const char &value) {}
	virtual void LogLine(const char* &value) {}
	virtual void LogLine(const double &value) {}
	virtual void LogLine(const DWORD &value) {}
	virtual void LogLine(const float &value) {}
	virtual void LogLine(const string &value) {}
	Logger();
	~Logger();
};

