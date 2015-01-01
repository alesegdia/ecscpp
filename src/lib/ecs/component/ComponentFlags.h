
#pragma once

#include <cstdint>

typedef std::uint32_t ctflags_t;


template <class T>
struct component_flags
{
	static const ctflags_t flags = 0x00000000;
};


