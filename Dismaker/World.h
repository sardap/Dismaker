#pragma once		
#ifndef WORLD_H

	#define WORLD_H
	#define CHARATERS_FILENAME "..\\Resources\\Charaters.xml"
	#include <vector>
	#include <string>
	#include <map>
	#include "pugixml/pugixml.hpp"
	#include "GameState.h"

	class RenderBridge;
	class DialogHolder;
	class Dialog;
	class Feeling;
	class Effect;

	class World
	{
		public:
			World(const char* dialogHoldersInfoFileName);
			World();
			~World();

			void Render(RenderBridge* renderer, GameState::Value gameState);

			void AddHolder(DialogHolder* holder);
			DialogHolder* GetHolder(std::string name);

			void SetActiveHolder(std::string name);

		private:
			std::vector<DialogHolder*> _holders;
			DialogHolder* _activeHolder;

			void PopulateDialogHolders(const char* fileName);
	};

#endif 
