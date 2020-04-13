#pragma once
#ifndef BUTTON_H

	#define BUTTON_H
	#include "IGUI.h"
	#include "IProcessInput.h"

	class RenderableComposite;

	class Button : public IGUI, public IProcessInput
	{
		public:
			Button(sf::RectangleShape rectangle, GameState::Value gameState);
			~Button();

			void AddText(const std::string& text, const sf::Font& font, const sf::Color colour = sf::Color(), int _buffer = 3);
			void AddBorder(const sf::Color colour, float fatness);
			
		protected:
			sf::RectangleShape _rectangle;
			
			void InternalRender(RenderBridge* renderer, GameState::Value gameState) override;

		private:
			RenderableComposite* _rendableComposite;
	};

#endif // !BUTTON_H
