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
		globals->insert(pair<const char*, double>("game_gravity", -750));

		globals->insert(pair<const char*, double>("player_x", 67));
		globals->insert(pair<const char*, double>("player_y", 400));
		globals->insert(pair<const char*, double>("player_width", 16));
		globals->insert(pair<const char*, double>("player_height", 30));
		globals->insert(pair<const char*, double>("player_vx", 320));
		globals->insert(pair<const char*, double>("player_vy_jump", 450));
		globals->insert(pair<const char*, double>("player_jump_height", 23));
		globals->insert(pair<const char*, double>("player_vy_fall_stand", -70));

		globals->insert(pair<const char*, double>("camera_x", 0));
		globals->insert(pair<const char*, double>("camera_y", 430));

		globals->insert(pair<const char*, double>("backbuffer_width", 256));
		globals->insert(pair<const char*, double>("backbuffer_height", 224));//224-176

		globals->insert(pair<const char*, double>("window_width", 256*2));
		globals->insert(pair<const char*, double>("window_height", 224*2));

		globals->insert(pair<const char*, double>("zombie_vx", 60));
		globals->insert(pair<const char*, double>("zombie_distance_to_activ", 100));

		globals->insert(pair<const char*, double>("panther_distance_to_activ", 50));
		globals->insert(pair<const char*, double>("panther_vy_jump", 100));
		globals->insert(pair<const char*, double>("panther_vx", 120));

		globals->insert(pair<const char*, double>("object_animation_interval", 120));

		globals->insert(pair<const char*, double>("explosion_effect_interval", 160));
		
		globals->insert(pair<const char*, double>("weapon_change_color_time", 40));

		globals->insert(pair<const char*, double>("game_fps", 70.0f));

		globals->insert(pair<const char*, double>("morning_star_attack_alive_time", 100));

		globals->insert(pair<const char*, double>("change_state_camera_move", 1));
		globals->insert(pair<const char*, double>("change_state_simon_move", 1));
		
	}
	return globals->at(key);
}