#include"List.h"
#include"Config.h"

List<CreateObjectFunct>* createObjectFuncts = 0;

List<CreateObjectFunct>* getCreateObjectFuncts()
{
	if (createObjectFuncts == 0)
		createObjectFuncts = new List<CreateObjectFunct>();
	return createObjectFuncts;
}
