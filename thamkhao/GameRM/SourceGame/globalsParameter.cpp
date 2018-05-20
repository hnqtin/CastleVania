#include"List.h"
#include"Config.h"
#include<map>
using namespace std;

List<CreateObjectFunct>* createObjectFuncts = 0;

List<CreateObjectFunct>* getCreateObjectFuncts()
{
	if (createObjectFuncts == 0)
		createObjectFuncts = new List<CreateObjectFunct>();
	return createObjectFuncts;
}

map<const char*, double>* globals = 0;
double getGlobalValue(const char* key)
{
	if (globals == 0)
	{
		globals = new map<const char*, double>();
		globals->insert(pair<const char*, long>("backbuffer_width", 256));
		globals->insert(pair<const char*, long>("backbuffer_height", 224));
		globals->insert(pair<const char*, long>("player_normal_width", 21));
		globals->insert(pair<const char*, long>("player_normal_height", 24));
		globals->insert(pair<const char*, long>("default_gravity", -600));

		globals->insert(pair<const char*, long>("player_vy_jump", 250));
		globals->insert(pair<const char*, long>("player_ax_normal", 350));
		globals->insert(pair<const char*, long>("player_max_vx", 130));
	}
	return globals->at(key);
}