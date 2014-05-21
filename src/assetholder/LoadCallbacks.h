#ifndef __LOADCALLBACKS_H__
#define __LOADCALLBACKS_H__

#include <SFML/Graphics.hpp>
#include "AssetHolder.h"
#include "stdinc.h"

template<typename AssetType>
struct DoLoad
{
	static void load(const std::string &path, AssetType* asset)
	{
	}
};

template<>
struct DoLoad<sf::Image>
{
	static void load(const std::string &path, sf::Image* im)
	{
		im->loadFromFile(path);
	}
};

#endif
