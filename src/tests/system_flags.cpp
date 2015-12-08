
#include <iostream>
#include <ecs/system/EntitySystem.h>

class C1 : public Component {};
class C2 : public Component {};
class C3 : public Component {};
class C4 : public Component {};
class C5 : public Component {};

class S1 : public EntitySystem
{

public:
    S1() {
        setFlags(ComponentTraits::BuildBits<C1, C2, C4>());
    }

    virtual ~S1() {}

    void process() override {}
    void added(eid_t e) override {}
    void deleted(eid_t e) override {}

protected:
    void addEntity(Entity *e) override {}
    void removeEntity(Entity *e) override {}

};

int main( int argc, char** argv ) {

    S1 s1;
    assert(s1.hasComponent<C1>() && "Incoherent components for system");
    assert(s1.hasComponent<C2>() && "Incoherent components for system");
    assert(!s1.hasComponent<C3>() && "Incoherent components for system");
    assert(s1.hasComponent<C4>() && "Incoherent components for system");
    assert(!s1.hasComponent<C5>() && "Incoherent components for system");

    return 0;
}
