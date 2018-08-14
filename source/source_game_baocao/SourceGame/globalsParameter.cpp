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
		globals->insert(pair<const char*, double>("player_vx", 100));
		globals->insert(pair<const char*, double>("player_vy_jump", 250));
		globals->insert(pair<const char*, double>("player_jump_height", 23));
		globals->insert(pair<const char*, double>("player_vy_fall_stand", -70));
		globals->insert(pair<const char*, double>("player_hit_vx", 130));
		globals->insert(pair<const char*, double>("player_hit_vy", 100));
		globals->insert(pair<const char*, double>("player_blink_time", 10));
		globals->insert(pair<const char*, double>("player_blink_delay", 1000));
		globals->insert(pair<const char*, double>("player_goto_stair_time", 200));
		globals->insert(pair<const char*, double>("player_dead_delay", 2000));
		globals->insert(pair<const char*, double>("player_obtain_moning_star_delay", 500));

		globals->insert(pair<const char*, double>("camera_x", 0));
		globals->insert(pair<const char*, double>("camera_y", 430));

		globals->insert(pair<const char*, double>("backbuffer_width", 256));
		globals->insert(pair<const char*, double>("backbuffer_height", 224));//256 -184

		globals->insert(pair<const char*, double>("window_width", 256*2));
		globals->insert(pair<const char*, double>("window_height", 224*2));

		globals->insert(pair<const char*, double>("zombie_vx", 60));
		globals->insert(pair<const char*, double>("zombie_distance_to_activ", 100));

		globals->insert(pair<const char*, double>("panther_distance_to_activ", 50));
		globals->insert(pair<const char*, double>("panther_vy_jump", 100));
		globals->insert(pair<const char*, double>("panther_vx", 140));

		globals->insert(pair<const char*, double>("object_animation_interval", 120));

		globals->insert(pair<const char*, double>("explosion_effect_interval", 160));
		
		globals->insert(pair<const char*, double>("weapon_change_color_time", 40));

		globals->insert(pair<const char*, double>("game_fps", 70.0f));

		globals->insert(pair<const char*, double>("morning_star_attack_alive_time", 100));

		globals->insert(pair<const char*, double>("change_state_camera_move", 1));
		globals->insert(pair<const char*, double>("change_state_simon_move", 1));

		globals->insert(pair<const char*, double>("merman_distance_to_activ", 50));
		globals->insert(pair<const char*, double>("merman_vy_jump", 450));
		globals->insert(pair<const char*, double>("merman_vx", 50));
		globals->insert(pair<const char*, double>("merman_run_delay", 1500));
		globals->insert(pair<const char*, double>("merman_attack_delay", 500));

		globals->insert(pair<const char*, double>("mermanbullet_vx", 150));

		globals->insert(pair<const char*, double>("bat_r", 20));
		globals->insert(pair<const char*, double>("bat_invisible_delay", 1000));
		globals->insert(pair<const char*, double>("bat_dx", 1));

		globals->insert(pair<const char*, double>("water_vy", 200));
		globals->insert(pair<const char*, double>("water_vx", 40));

		globals->insert(pair<const char*, double>("boss_distance_activ", 50));
		globals->insert(pair<const char*, double>("boss_wait_time", 1000));
		globals->insert(pair<const char*, double>("boss_move_fast_time_min", 1000));
		globals->insert(pair<const char*, double>("boss_move_fast_time_max", 2000));
		globals->insert(pair<const char*, double>("boss_move_slow_time_min", 1000));
		globals->insert(pair<const char*, double>("boss_move_slow_time_max", 2000));
		globals->insert(pair<const char*, double>("boss_ay", 100));

		globals->insert(pair<const char*, double>("vampire_bat_fast_momen", 150));
		globals->insert(pair<const char*, double>("vampire_bat_slow_momen", 90));

		globals->insert(pair<const char*, double>("fleaman_wait_delay", 2000));
		globals->insert(pair<const char*, double>("fleaman_vx_run", 140));
		globals->insert(pair<const char*, double>("fleaman_vy_run", 120));
		globals->insert(pair<const char*, double>("fleaman_vx_jump", 100));
		globals->insert(pair<const char*, double>("fleaman_vy_jump", 280));

		globals->insert(pair<const char*, double>("skeleton_player_distance", 50));
		globals->insert(pair<const char*, double>("skeleton_activity_distance", 50));
		globals->insert(pair<const char*, double>("skeleton_attack_delay_min", 1000));
		globals->insert(pair<const char*, double>("skeleton_attack_delay_max", 3000));
		globals->insert(pair<const char*, double>("skeleton_attack_time", 200));
		globals->insert(pair<const char*, double>("skeleton_run_delay", 200));
		globals->insert(pair<const char*, double>("skeleton_vx", 60));
		globals->insert(pair<const char*, double>("skeleton_vy_jump", 280));
		globals->insert(pair<const char*, double>("skeleton_vx_jump", 60));

		globals->insert(pair<const char*, double>("redskeleton_distance", 30));
		globals->insert(pair<const char*, double>("redskeleton_vx", 60));
		globals->insert(pair<const char*, double>("redskeleton_die_delay", 2000));

		globals->insert(pair<const char*, double>("skeletonweapon_vx", 60));
		globals->insert(pair<const char*, double>("skeletonweapon_vy", 200));

		globals->insert(pair<const char*, double>("boomerang_vx", 2));
		globals->insert(pair<const char*, double>("boomerang_distance", 100));

		globals->insert(pair<const char*, double>("medusahead_r", 30));
		globals->insert(pair<const char*, double>("medusahead_dx", 1));

		globals->insert(pair<const char*, double>("death_wait_delay", 2000));
		globals->insert(pair<const char*, double>("death_vy", 40));
		globals->insert(pair<const char*, double>("death_vx", 40));
		globals->insert(pair<const char*, double>("death_ay", 0));
		globals->insert(pair<const char*, double>("death_create_weapon_time", 2000));

		globals->insert(pair<const char*, double>("deathweapon_wait_delay", 200));
		globals->insert(pair<const char*, double>("dead_weapon_dx", 1));
		globals->insert(pair<const char*, double>("dead_weapon_moment", 1));
		globals->insert(pair<const char*, double>("deathweapon_continue_run_delay", 100));

		globals->insert(pair<const char*, double>("dagger_dx", 3));

		globals->insert(pair<const char*, double>("bonepillar_delay", 2000));
		globals->insert(pair<const char*, double>("bonepillar_time", 500));
	}
	return globals->at(key);
}
