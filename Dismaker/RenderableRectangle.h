#pragma once
#ifndef RENDERABLE_RECTANGLE_H

	#define RENDERABLE_RECTANGLE_H
	#include "IGUI.h"

	class RenderableRectangle : public IGUI
	{
		public:
			RenderableRectangle(const sf::RectangleShape& rectangle, GameState::Value gamestate);
			~RenderableRectangle();

		protected:
			void InternalRender(RenderBridge* renderer, GameState::Value gameState) override;


		private:
			sf::RectangleShape _rectangle;
	};

#endif // !RENDERABLE_RECTANGLE_H
