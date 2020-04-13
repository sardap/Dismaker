#include "GameUtils.h"
#include "GameExpections.h"
#include "SFMLManager.h"
#include <map>

using namespace GameUtils;

void GameUtils::FitText(sf::Text& text, const sf::RectangleShape& rectangle)
{
	/*
	text_length = 100 chars
	lines = 5
	font_width = 10px
	font_height = 20px
	spacing_height = 10px (space between 2 lines)
	Original bubble image size (red rectangle)

	height = 300px
	width = 500px
	Original bubble image textarea size (green rectangle)

	height = 200px
	width = 400px
	*/

	/*
	Step 1: calculate required text space

	height = (5 * 20px) + ((5-1) * 10px) = 100px + 40px = 140px
	width = 100 / 5 * 10px = 200px
	Step 2 : calculate scaling

	Height scale = required_height / original_height = 140 / 200 = 0.7 = 70%
	Width scale = required_width / original_width = 200 / 400 = 0.5 = 50%

	*/

	if(text.getLocalBounds().width > rectangle.getSize().x)
	{
		text.setCharacterSize
		(
			static_cast<unsigned int>((rectangle.getSize().y * rectangle.getSize().x) / text.getLocalBounds().width)
		);
	}
}

sf::Color GameUtils::StringToColor(const std::string& string)
{
	return HTMLHexCode(PaulTils::StringToInt(string.c_str()));
}

sf::Color GameUtils::HTMLHexCode(int rgb)
{
	unsigned char r = rgb / 0x10000;
	unsigned char g = (rgb / 0x100) % 0x100;
	unsigned char b = rgb % 0x100;

	return sf::Color(r, g, b, 255);
}

bool GameUtils::ShapeContainsPostion(const sf::Shape& shape, sf::Vector2f postion)
{
	return shape.getGlobalBounds().contains(postion);
}


double GameUtils::GetScreenWidth()
{
	return SFMLManager::GetInstane()->GetWindow()->getSize().x;
}

double GameUtils::GetScreenHieght()
{
	return SFMLManager::GetInstane()->GetWindow()->getSize().y;
}

sf::Font GameUtils::BuildFont(const std::string& string)
{
	sf::Font newfont;

	if(!newfont.loadFromFile(string))
	{
		throw FONT_UNABLE_TO_LOAD;
	}
	
	return newfont;

}