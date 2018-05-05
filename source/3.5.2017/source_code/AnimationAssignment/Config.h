#pragma once
#include<map>
using namespace std;

#pragma region String

#define TITLE_STR "Castle Vania"
#define CVFORM_CLASS_NAME "CastleVania"  

extern map<const char*, double> params;

#pragma endregion


#pragma region Size

#define FORM_WIDTH 700
#define FORM_HEIGHT 600

#define BACKBUFFER_WIDTH 256
#define BACKBUFFER_HEIGHT 190

#pragma endregion

#pragma region Constants

extern int STAIR_DELTA;
extern int STAIR_DY;
extern int DISTANCE_OUT_STAIR;
extern float RM_VY_JUMP;
extern float RM_V_RUN;
extern float RM_VX_STAND;

extern float ALD_VY_JUMP;
extern float ALD_V_RUN;
extern float ALD_VX_STAND;
extern int CAMERA_CHANGEMAPVIEW_DY;
extern float ALADIN_CHANGEMAPVIEW_DY;

extern int CAMERA_CHANGESTAGEVIEW_DY;
extern float ROCKMAN_CHANGESTAGEVIEW_DY;
extern float TIME_BLINK_OPEN;
extern float TIME_BLINK_CLOSE;
extern float TIME_BEAK_CLOSED;
extern float TIME_BEAK_SHOOTING;
extern float TIME_BEAK_CHANGE_STATE;
extern int BLADER_FIND_ROCKMAN_DISTANCE;
extern float BLADER_ATTACK_DY;
extern int RM_BULLET_WAITING_DELAYTIME;
extern int RM_SHOOTING_DELAYTIME;
#pragma endregion