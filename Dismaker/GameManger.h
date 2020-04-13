#pragma once
#ifndef GAME_MANAGER_H

	#define GAME_MANAGER_H
	#include <string>	
	#include "World.h"
	#include "Player.h"
	#include "MouseInfo.h"	
	#include <SFML\Graphics.hpp>

	class GameClock;
	class BridgeManager;
	class Configuration;
	class GUIManager;

	class GameManager
	{
		public:
			GameManager();
			~GameManager();

			void Start();

		private:
			GameState::Value _gameState;
			BridgeManager* _bridgeManager;
			Configuration* _config;
			MouseInfo* _mouseInfo;
			GUIManager* _guiManager;

			World* _world;
			Player* _player;
			GameClock* _gameClock;

			bool _exit;

			void GameLoop();

			void CheckExitRequested();
			void ProcessInput();
			void Render();
	};

#endif // !GAME_MANAGER_H
