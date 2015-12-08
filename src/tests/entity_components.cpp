
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

	e.attachComponent(c2);
	e.attachComponent(c4);
	e.attachComponent(c5);

	assert(!e.hasComponent<C1>() && "Incoherent flag for C1");
	assert(e.hasComponent<C2>() && "Incoherent flag for C2");
	assert(!e.hasComponent<C3>() && "Incoherent flag for C3");
	assert(e.hasComponent<C4>() && "Incoherent flag for C4");
	assert(e.hasComponent<C5>() && "Incoherent flag for C5");

    ctflags_t badbits1 = ComponentTraits::BuildBits<C1, C2, C3>();
    ctflags_t badbits2 = ComponentTraits::BuildBits<C5>();
    ctflags_t badbits3 = ComponentTraits::BuildBits<C2, C4>();

    ctflags_t goodbits = ComponentTraits::BuildBits<C2, C4, C5>();

    assert(!e.all(badbits1) && "Incoherent bits for C1, C2, C3");
    assert(!e.all(badbits2) && "Incoherent bits for C5");
    assert(!e.all(badbits3) && "Incoherent bits for C2, C4");

    assert(e.all(goodbits) && "Should validate flags for C2, C4, C5");

	return 0;
}
