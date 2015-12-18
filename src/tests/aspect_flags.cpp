
#include <ecs/component/Aspect.h>
#include <ecs/system/EntitySystem.h>
#include <cassert>

class C1 {};
class C2 {};
class C3 {};
class C4 {};
class C5 {};

class S1 : public EntitySystem
{

public:
	S1() {
		aspect().all<C1, C2, C4>();
	}
};


int main( int argc, char** argv )
{
	{
		S1 s1;
		assert(s1.aspect().hasAll<C1>() && "Incoherent components for system");
		assert(s1.aspect().hasAll<C2>() && "Incoherent components for system");
		assert(!s1.aspect().hasAll<C3>() && "Incoherent components for system");
		assert(s1.aspect().hasAll<C4>() && "Incoherent components for system");
		assert(!s1.aspect().hasAll<C5>() && "Incoherent components for system");

		Aspect a1, a2;

		a1.all<C1, C3>();
		a1.all<C5>();
		a2.all<C3, C5>();
		a2.all<C1>();

		a1.any<C2, C4>();
		a1.any<C1>();
		a2.any<C1, C2>();
		a2.any<C4>();

		a1.none<C1, C4>();
		a1.none<C2>();
		a2.none<C4, C1>();
		a2.none<C2>();

		ctflags_t bits12345 = ComponentTraits::BuildBits<C1, C2, C3, C4, C5>();
		ctflags_t bits135 = ComponentTraits::BuildBits<C1, C3, C5>();
		ctflags_t bits2345 = ComponentTraits::BuildBits<C2, C3, C4, C5>();
		ctflags_t bits3 = ComponentTraits::BuildBits<C3>();
		ctflags_t bits4 = ComponentTraits::BuildBits<C4>();

		// checking aspect 1 (1,3,5)
		assert(a1.all(bits12345));
		assert(!a1.all(bits2345));
		assert(a1.all(bits135));
		assert(!a1.all(bits3));
		assert(!a1.all(bits4));

		assert(a1.any(bits12345));
		assert(a1.any(bits2345));
		assert(a1.any(bits135));
		assert(!a1.any(bits3));
		assert(a1.any(bits4));

		assert(!a1.none(bits12345));
		assert(!a1.none(bits2345));
		assert(!a1.none(bits135));
		assert(a1.none(bits3));
		assert(!a1.none(bits4));

		// checking aspect 2 (same as aspect 1 but changing order of bit set)
		assert(a2.all(bits12345));
		assert(!a2.all(bits2345));
		assert(a2.all(bits135));
		assert(!a2.all(bits3));
	}

	{
		Aspect a1;
		a1.all<C1, C2>();
		a1.any<C3, C4>();
		a1.none<C5>();

		assert(a1.all(ComponentTraits::BuildBits<C1, C2>()));
		assert(!a1.fits(ComponentTraits::BuildBits<C1, C2>()));
		assert(a1.fits(ComponentTraits::BuildBits<C1, C2, C3>()));
		assert(a1.fits(ComponentTraits::BuildBits<C1, C2, C4>()));
		assert(!a1.fits(ComponentTraits::BuildBits<C1, C2, C3, C5>()));
		assert(!a1.fits(ComponentTraits::BuildBits<C1, C2, C5>()));

		Aspect a2;
		assert(a2.all(0));
		assert(a2.any(0));
		assert(a2.none(0));
		assert(a2.fits(0));
	}

	return 0;
}
