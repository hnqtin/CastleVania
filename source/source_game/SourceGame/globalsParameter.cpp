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
		globals->insert(pair<const char*, double>("game_gravity", -450));

		globals->insert(pair<const char*, double>("player_x", 1350));
		globals->insert(pair<const char*, double>("player_y", 94));
		globals->insert(pair<const char*, double>("player_width", 16));
		globals->insert(pair<const char*, double>("player_height", 30));
		globals->insert(pair<const char*, double>("player_vx", 120));
		globals->insert(pair<const char*, double>("player_vy_jump", 180));
		globals->insert(pair<const char*, double>("player_jump_height", 23));
		globals->insert(pair<const char*, double>("player_vy_fall_stand", -70));

		globals->insert(pair<const char*, double>("camera_x", 1300));
		globals->insert(pair<const char*, double>("camera_y", 222));

		globals->insert(pair<const char*, double>("ghost_vx", 60));
		globals->insert(pair<const char*, double>("ghost_distance_to_activ", 100));

		globals->insert(pair<const char*, double>("meo_distance_to_activ", 50));
		globals->insert(pair<const char*, double>("meo_vy_jump", 180));
		globals->insert(pair<const char*, double>("meo_vx", 120));






	}
	return globals->at(key);
}
