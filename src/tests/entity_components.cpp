
#include <iostream>
#include <ecs/component/ComponentTraits.h>
#include <ecs/component/Component.h>
#include <ecs/entity/Entity.h>

class C1: public Component {};
class C2: public Component {};
class C3: public Component {};
class C4: public Component {};
class C5: public Component {};

int main( int argc, char** argv ) {
	Entity e;
	C1  c1[100];
	C2  c2[100];
	C3  c3[100];
	C4  c4[100];
	C5  c5[100];

	e.AttachComponent(c2);
	e.AttachComponent(c4);
	e.AttachComponent(c5);

	assert(!e.IsFlagActive<C1>() && "Incoherent flag for C1");
	assert(e.IsFlagActive<C2>() && "Incoherent flag for C2");
	assert(!e.IsFlagActive<C3>() && "Incoherent flag for C3");
	assert(e.IsFlagActive<C4>() && "Incoherent flag for C4");
	assert(e.IsFlagActive<C5>() && "Incoherent flag for C5");


	return 0;
}
