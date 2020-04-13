#include "ColorUtils.h"

sf::Color ColorUtils::Black = ColorUtils::HTMLHexCode(0x000000);
sf::Color ColorUtils::WhiteSmoke = ColorUtils::HTMLHexCode(0xf5f5f5);
sf::Color ColorUtils::DarkGray = ColorUtils::HTMLHexCode(0xA9A9A9);
sf::Color ColorUtils::Red = ColorUtils::HTMLHexCode(0xFF0000);

sf::Color ColorUtils::HTMLHexCode(int rgb)
{
	return sf::Color(rgb / 0x10000, (rgb / 0x100) % 0x100, rgb % 0x100, 255);
}

