#pragma once
#ifndef TEXT_BOX_H

	#define TEXT_BOX_H
	#include "IGUI.h"
	#include <SFML\Graphics.hpp>
	#include "Configuration.h"
	#include "GameUtils.h"

	class TextBox : public IGUI
	{
		public:
			TextBox
			(
				const std::string& text, 
				const sf::Color& textColor, 
				sf::Font font, 
				const sf::RectangleShape& rectangle,
				int size,
				int _buffer, 
				const sf::Color& highlightColor = sf::Color(27, 161, 226, 127),
				GameState::Value gameState = GameState::Game
			);
			~TextBox();
			
			void SetText(const std::string& text);
			sf::FloatRect GetBounds();

			void Highlight(RenderBridge& renderer);

		protected:
			std::vector<sf::Text> _text;
			sf::RectangleShape _rectangle;

			void InternalRender(RenderBridge* renderer, GameState::Value gameState) override;

		private:
			sf::Color _textColor;
			sf::Font _font;
			int _size;
			int _buffer;
			sf::Color _highlightColor;
	};

#endif // !TEXT_BOX_H
