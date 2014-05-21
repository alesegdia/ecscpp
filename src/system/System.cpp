#include "System.h"
#include "ComponentFlags.h"

System::System()
{
	// _flags = construct_flags<RenderComponent>;
}

System::~System()
{
}

void System::process()
{
	std::cout << "System::process()\n";
}
