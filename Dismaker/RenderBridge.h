#pragma once
#ifndef RENDER_BRIDGE_H

	#define RENDER_BRIDGE_H
	#include "Bridge.h"
	#include <string>
	#include <SFML\Graphics.hpp>

	class RenderBridge : public Bridge
	{
		public:
		RenderBridge();
		virtual ~RenderBridge();

		virtual void Clear();
		virtual void Display();

		virtual void Text(const char* text);
		virtual void Text(const sf::Text& text);
		virtual void Rectangle(const sf::RectangleShape& rectangle);
		
		void Render(const sf::Drawable& drawable);

		// Overloaded for convuince
		void Text(std::string text);
	};

#endif // !RENDER_BRIDGE_H
