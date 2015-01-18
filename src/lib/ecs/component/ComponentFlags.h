
#pragma once

#include <cstdint>

typedef std::uint32_t ctflags_t;


template <class T>
struct component_flags
{
	static const ctflags_t flags = 0x00000000;
};

class ActiveComponent {};
class AliveComponent {};

template <>
struct component_flags<ActiveComponent>
{ static const ctflags_t flags = 0x00000000; };

template <>
struct component_flags<AliveComponent>
{ static const ctflags_t flags = 0x00000000; };


