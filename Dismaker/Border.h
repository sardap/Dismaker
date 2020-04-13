#pragma once
#ifndef BORDER_H

	#define BORDER_H
	#include "IGUI.h"
	#include <vector>

	class RenderableComposite;

	class Border : public IGUI
	{
		public:
			// @Bad fatness is not a good name for how fat the bars of the border are
			Border(int fatness, sf::RectangleShape rectangle, sf::Color colour, GameState::Value gamestate);
			Border(int fatness, sf::RectangleShape rectangle, GameState::Value gamestate);
			~Border();

		protected:
			void InternalRender(RenderBridge* renderer, GameState::Value gameState) override;

		private:
			RenderableComposite* _renderables;
	};

#endif // !BORDER_H
