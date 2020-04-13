#pragma once
#ifndef GAME_UTILS_H

	#define GAME_UTILS_H
	#include <SFML\Graphics.hpp>
	#include <SharedLibary\PaulTils.h>

	namespace GameUtils
	{
		void FitText(sf::Text& text, const sf::RectangleShape& rectangle);

		sf::Color StringToColor(const std::string& string);
		sf::Color HTMLHexCode(int rgb);

		sf::Vector2f MousePostion();

		bool ShapeContainsPostion(const sf::Shape& shape, sf::Vector2f postion);

		template<typename T> void CenterRectangeInRectangle(sf::RectangleShape& rectangle, const sf::Rect<T>& containtor)
		{
			rectangle.setPosition(sf::Vector2f(containtor.width / 2 - rectangle.getSize().x, containtor.height / 2 - rectangle.getSize().y));
		}

		double GetScreenWidth();
		double GetScreenHieght();

		sf::Font BuildFont(const std::string& string);
	}

#endif // !GAME_UTILS_H
