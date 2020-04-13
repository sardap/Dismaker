#pragma once
#ifndef TEXT_CONFIG_INFO_H

	#define TEXT_CONFIG_INFO_H
	#include <SFML\Graphics.hpp>

	struct TextConfigInfo
	{
		sf::Color textColor;
		sf::Font font;
		unsigned int size;
		float _buffer;
	};

#endif // !DIALOG_TEXT_INFO_H
