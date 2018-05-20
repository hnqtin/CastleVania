#pragma once
#include"ObjectContainer.h"
#include"Logger.h"


class ConsoleLogger : public Logger
{
public:
   void Log(const int &value);
   void Log(const DWORD &value);
   void Log(const char &value);
   void Log(const char* &value);
   void Log(const double &value);
   void Log(const float &value);
   void Log(const string &value);
   void LogLine(const int &value);
   void LogLine(const DWORD &value);
   void LogLine(const char &value);
   void LogLine(const char* &value);
   void LogLine(const double &value);
   void LogLine(const float &value);
   void LogLine(const string &value);
   ConsoleLogger();
   ~ConsoleLogger();
};

extern ObjectContainer<ConsoleLogger> consoleLogger;
