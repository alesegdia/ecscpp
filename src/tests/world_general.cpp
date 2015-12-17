#include <ecs/component/Component.h>
#include <ecs/entity/Entity.h>
#include <ecs/system/EntityProcessingSystem.h>
#include <ecs/world/GameWorld.h>
#include <rztl/pool.h>

int s1i, s2i, s3i, s4i;

class S1 : public EntityProcessingSystem { void process(Entity *e) override { s1i++; } };
class S2 : public EntityProcessingSystem { void process(Entity *e) override { s2i++; } };
class S3 : public EntityProcessingSystem { void process(Entity *e) override { s3i++; } };
class S4 : public EntityProcessingSystem { void process(Entity *e) override { s4i++; } };

class C1 : public Component {};
class C2 : public Component {};
class C3 : public Component {};
class C4 : public Component {};

int s11i, s22i, s33i, s44i;

class S11 : public EntityProcessingSystem {
public:
	S11() {	aspect().all<C1, C2>(); }
	void process(Entity *e) { s11i++; }
};

class S22 : public EntityProcessingSystem {
public:
	S22() {	aspect().all<C3>(); }
	void process(Entity *e) { s22i++; }
};

class S33 : public EntityProcessingSystem {
public:
	S33() {	aspect().all<C1, C4>(); }
	void process(Entity *e) { s33i++; }
};

class S44 : public EntityProcessingSystem {
public:
	S44() {	aspect().all<C2, C4>(); }
	void process(Entity *e) { s44i++; }
};


int main( int argc, char** argv )
{
	s1i		= s2i	= s3i	= s4i	=
	s11i	= s22i	= s33i	= s44i	= 0;

	GameWorld gw;

	S1 s1; S11 s11;
	S2 s2; S22 s22;
	S3 s3; S33 s33;
	S4 s4; S44 s44;

	C1 c1[100];
	C2 c2[100];
	C3 c3[100];
	C4 c4[100];

	Entity e1, e2, e3, e4;
	e1.attachComponent(c1);
	e1.attachComponent(c2);
	e1.attachComponent(c3);
	e1.attachComponent(c4);

	e2.attachComponent(c2 + 1);
	e2.attachComponent(c4 + 1);

	e3.attachComponent(c3 + 2);

	assert(s11.aspect().fits(e1.getFlags()));

	gw.addSystem(&s1); gw.addSystem(&s11);
	gw.addSystem(&s2); gw.addSystem(&s22);
	gw.addSystem(&s3); gw.addSystem(&s33);
	gw.addSystem(&s4); gw.addSystem(&s44);

	gw.addEntity(&e1);
	gw.addEntity(&e2);
	gw.addEntity(&e3);
	gw.addEntity(&e4);

	gw.process();

	assert(s1i == 4);
	assert(s2i == 4);
	assert(s3i == 4);
	assert(s4i == 4);

	assert(s11i == 1);
	assert(s22i == 2);
	assert(s33i == 1);
	assert(s44i == 2);

	return 0;
}
