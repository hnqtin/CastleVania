#include "TestObject.h"
REGISTER_OBJECT_GAME(TestObject, -2)
TestObject::TestObject()
{
	setPhysicsEnable(false);
}
TestObject::~TestObject()
{
}
