
#pragma once

#include <rapidjson/rapidjson.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/document.h>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Spritesheet.h"

class AssetParser {

public:

	AssetParser () {}
	virtual ~AssetParser () {

		for( auto it : textures ) delete it.second;
		for( auto it : spritesheets ) delete it.second;
		for( auto it : animations ) delete it.second;

	}

	void LoadFromFile( const char* path )
	{
		FILE* fp = fopen(path, "r");

		char readBuffer[65536];
		rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));

		d.ParseStream(is);
		fclose(fp);

		rapidjson::Value& jsonTextures = d["textures"];
		rapidjson::Value& jsonSpritesheets = d["spritesheets"];
		rapidjson::Value& jsonAnimations = d["animations"];

		for( auto it = jsonTextures.MemberBegin(); it != jsonTextures.MemberEnd(); ++it )
		{
			sf::Texture* tex = new sf::Texture();
			auto& jsonval = it->value;
			tex->loadFromFile( jsonval["path"].GetString() );
			textures.insert( std::make_pair( it->name.GetString(), tex ));
		}

		for( auto it = jsonSpritesheets.MemberBegin(); it != jsonSpritesheets.MemberEnd(); ++it )
		{
			Spritesheet* sheet = new Spritesheet();
			auto& jsonval = it->value;
			auto& size = jsonval["size"];
			sheet->Prepare( textures[jsonval["texture"].GetString()], sf::Vector2i( size[0].GetInt(), size[1].GetInt() ));
		}

	}

	sf::Texture* GetTexture( const std::string& str )
	{
		return textures[str];
	}

private:

	rapidjson::Document d;

	std::map<std::string, sf::Texture*> textures;
	std::map<std::string, Spritesheet*> spritesheets;
	std::map<std::string, Animation*> animations;


};

