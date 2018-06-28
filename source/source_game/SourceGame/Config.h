#pragma once

#include<fstream>
using namespace std;
extern double getGlobalValue(const char* key);

extern void ignoreLineIfstream(ifstream& fs, int lineCount);
#include"List.h"

#pragma region String

#define TITLE_STR "Castle Vania"
#define CVFORM_CLASS_NAME "CastleVania"  

#pragma endregion


#pragma region Size

#define FORM_WIDTH 700
#define FORM_HEIGHT 500

#define BACKBUFFER_WIDTH 256
#define BACKBUFFER_HEIGHT 224

#pragma endregion

#define CREATE_INSTANCE_INSIDE(ClassName) \
private:	\
static ClassName* instance; \
public: \
static ClassName* getInstance(){ \
	if(instance==0) \
	{\
		instance = new ClassName(); \
	}\
	return instance; \
}

#define CREATE_INSTANCE_OUTSIDE(ClassName) \
ClassName* ClassName::instance=0 

typedef void*(*CreateObjectFunct)(int);

List<CreateObjectFunct>* getCreateObjectFuncts();

#define REGISTER_OBJECT_GAME(ObjectType, ObjectId) \
void* CreateFunct##ObjectType(int id) \
{\
	if(id==ObjectId)\
	{\
		return new ObjectType();\
	}\
	return 0;\
}\
int execCreateFunct##ObjectType() {\
	getCreateObjectFuncts()->_Add(CreateFunct##ObjectType);\
	return 0;\
}\
int execCode##ObjectType = execCreateFunct##ObjectType();