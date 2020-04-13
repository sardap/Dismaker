#pragma once
#ifndef I_RENDERABLE_H

	#define I_RENDERABLE_H
	#include <SFML\Graphics.hpp>
	#include "GameState.h"

	class RenderBridge;

	class Renderable
	{
		public:
			Renderable(GameState::Value gameState  = GameState::Game);
			virtual ~Renderable();

			void Render(RenderBridge* renderer, GameState::Value gameState);

		protected:
			virtual void InternalRender(RenderBridge* renderer, GameState::Value gameState) = 0;
			GameState::Value GetGameState();

		private:
			GameState::Value _gameState;

	};

#endif // !I_RENDERABLE_H
