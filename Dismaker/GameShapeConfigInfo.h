#pragma once
#ifndef GAME_SHAPE_CONFIG_INFO

	#define GAME_SHAPE_CONFIG_INFO
	#include <map>

	typedef std::map<std::string, std::string> TextureLocationMap;

	struct GameShapeConfigInfo
	{
		TextureLocationMap textureLocationMap;
		std::string entranceID;
	}; 

#endif // !BACKGROUND_CONFIG_INFO
