#pragma once
#ifndef COLOR_UTILS_H

	#define COLOR_UTILS_H
	#include "SFML\Graphics.hpp"

	class ColorUtils
	{
		public:
			static sf::Color Black;
			static sf::Color WhiteSmoke;
			static sf::Color DarkGray;
			static sf::Color Red;

		private: 
			static sf::Color HTMLHexCode(int rgb);
	};

#endif // !
