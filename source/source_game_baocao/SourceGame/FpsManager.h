#pragma once
#include"ConsoleLogger.h"
#include"ObjectContainer.h"
class FpsManager
{
   double _Fps;

   double PCFreq_r;
   __int64 CounterStart_r;

public:
   GENERATE_GETTER_SETTER(double, TimePerFrame);
   GENERATE_GETTER_SETTER(double, TimeGame);
   GENERATE_GETTER_SETTER(double, RealFrameCounter);
   FpsManager();
   ~FpsManager();
   bool CanCreateFrame();
   void StartCounter();
   double GetCounter();

   void StartCounter_r();
   double GetCounter_r();

   void CalculateRealFrameCounter();
};

extern FpsManager* _FpsManager;