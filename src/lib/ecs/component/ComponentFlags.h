
#pragma once


typedef std::uint32_t ctflags_t;

template <class T>
struct component_flags
{
	static const ctflags_t flags = 0x00000000;
};

template <class... Ts>
struct construct_flags;

template <class First, class... Rest>
struct construct_flags<First, Rest...>
{
	static const ctflags_t flags =
		component_flags<First>::flags |
		construct_flags<Rest...>::flags;
};

template <class T>
struct construct_flags<T>
{ static const ctflags_t flags = component_flags<T>::flags; };


