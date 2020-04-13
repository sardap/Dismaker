#pragma once
#ifndef GUI_MANAGER_H

	#define GUI_MANAGER_H
	#include <vector>
	#include <map>
	#include "IProcessInput.h"
	#include "GameState.h"

	class RenderBridge;
	class World;
	class Renderable;

	class GUIManager : public IProcessInput
	{
		public:
			GUIManager(World& world, GameState::Value& gameState);
			~GUIManager();

			void Update(const sf::Time& deltaTime);

			void Render(RenderBridge& renderer, GameState::Value gameState);
			void ProcessInput(const InputBridge& inputBridge) override;

		private:
			std::vector<Renderable*> _guiElements;
			World& _world;
			GameState::Value& _gameState;

			// @Bad this name
			void UniversalInputs(const InputBridge& inputBridge);
	};

#endif // !GUI_MANAGER_H
