#ifndef __ASSETHOLDER_H__
#define __ASSETHOLDER_H__

#include <stdinc.h>
#include <core/util/StringSplit.h>
#include <core/assets/LoadCallbacks.h>

template<typename AssetType>
class AssetHolder
{
public:
	AssetHolder()
	{

	}

	virtual ~AssetHolder()
	{

	}

	AssetType* get(const char* nameChar)
	{
		std::string name(nameChar);
		//std::cout << "@getted: " << _assets[name] << "\n";
		return _assets[name];
	}
	void add(const char* pathChar)
	{
		std::string path(pathChar);
		std::vector<std::string> v;
		split(path, '/', v);
		std::string name(v.back());

		// si casca el new T(), crearlo en el LoadCallback
		AssetType* asset = new AssetType();
		DoLoad<AssetType>::load(path, asset);
		//std::cout << "@orig: " << asset << "\n";
		_assets[name] = asset;
		//std::cout << "@dst: " << _assets[name] << "\n";
		std::cout << _assets.size();
	}

	void debugMap()
	{
		std::cout << "\nDEBUGING MAP\n";
		for(auto it : _assets)
		{
			std::cout << it.first << std::endl;
		}
		std::cout << "END!\n";
	}

	//void loadCallback(const std::string& path, AssetType* asset)

private:
	std::unordered_map<std::string, AssetType*> _assets;
};

typedef AssetHolder<sf::Image> ImageHolder;

#endif
