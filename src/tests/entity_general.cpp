
#include <iostream>
#include <ecs/entity/Entity.h>

int main( int argc, char** argv ) {
	Entity e;
	e.setEID(12345);
	assert(e.getEID() == 12345 && "getEID or setEID is not working");
	std::cout << "getEID and setEID pass!\n";
	return 0;
}
