
#pragma once

#include <cstdint>

typedef std::uint32_t ctflags_t;


template <class T>
struct component_flags
{
	static const ctflags_t flags = 0x00000000;
};


typedef std::uint32_t ctindex_t;

template <class T>
struct component_index
{
	static const ctindex_t index = 0;
};
