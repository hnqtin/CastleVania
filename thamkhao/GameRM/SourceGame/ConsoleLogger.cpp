#include "ConsoleLogger.h"
#include"ObjectContainer.h"
#include<Windows.h>

ObjectContainer<ConsoleLogger> consoleLogger = new ConsoleLogger();

void ConsoleLogger::Log(const int & value)
{
   OutputDebugStringA(("Logger:" + std::to_string(value)).c_str());
}

void ConsoleLogger::Log(const DWORD & value)
{
	OutputDebugStringA(("Logger:" + std::to_string(value)).c_str());
}

void ConsoleLogger::Log(const char & value)
{
   OutputDebugStringA(("Logger:" + std::to_string(value)).c_str());
}

void ConsoleLogger::Log(const char *& value)
{
   OutputDebugStringA(((string)("Logger:") + value).c_str());
}

void ConsoleLogger::Log(const double & value)
{
   OutputDebugStringA(("Logger:" + std::to_string(value)).c_str());
}

void ConsoleLogger::Log(const float & value)
{
   OutputDebugStringA(std::to_string(value).c_str());
}

void ConsoleLogger::Log(const string & value)
{
   OutputDebugStringA(("Logger:" + value).c_str());
}

void ConsoleLogger::LogLine(const int & value)
{
   OutputDebugStringA("\n");
   Log(value);
   OutputDebugStringA("\n");
}

void ConsoleLogger::LogLine(const DWORD & value)
{
	OutputDebugStringA("\n");
	Log(value);
	OutputDebugStringA("\n");
}

void ConsoleLogger::LogLine(const char & value)
{
   OutputDebugStringA("\n");
   Log(value);
   OutputDebugStringA("\n");
}

void ConsoleLogger::LogLine(const char *& value)
{
   OutputDebugStringA("\n");
   Log(value);
   OutputDebugStringA("\n");
}

void ConsoleLogger::LogLine(const double & value)
{
   OutputDebugStringA("\n");
   Log(value);
   OutputDebugStringA("\n");
}

void ConsoleLogger::LogLine(const float & value)
{
   OutputDebugStringA("\n");
   Log(value);
   OutputDebugStringA("\n");
}

void ConsoleLogger::LogLine(const string & value)
{
   OutputDebugStringA("\n");
   Log(value);
   OutputDebugStringA("\n");
}

ConsoleLogger::ConsoleLogger()
{
}


ConsoleLogger::~ConsoleLogger()
{
}
