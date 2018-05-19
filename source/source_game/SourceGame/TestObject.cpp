#include "TestObject.h"
REGISTER_OBJECT_GAME(TestObject, SI_MERMAN)
TestObject::TestObject()
{
	setPhysicsEnable(false);
}
TestObject::~TestObject()
{
}
