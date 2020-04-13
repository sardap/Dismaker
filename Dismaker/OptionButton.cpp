#include "OptionButton.h"
#include "Configuration.h"
#include "ColorUtils.h"
#include <SFML\Window.hpp>
#include "MouseInfo.h"

#define TEXT_INFO Configuration::GetInstane()->GetOptionButtonConfigInfo().textInfo
#define BORDER_INFO Configuration::GetInstane()->GetOptionButtonConfigInfo().borderInfo
#define RECTANGLE_INFO Configuration::GetInstane()->GetOptionButtonConfigInfo().rectangleInfo

OptionButton::OptionButton(Option& option, sf::RectangleShape rectangle, GameState::Value gameState) : Button(rectangle, gameState), _option(option)
{
	rectangle.setFillColor(RECTANGLE_INFO.fillColor);
	AddBorder(BORDER_INFO.fillColor, BORDER_INFO.borderFatness);
	AddText(_option.GetText(), TEXT_INFO.font, TEXT_INFO.textColor, TEXT_INFO._buffer);
}

OptionButton::~OptionButton()
{
}

void OptionButton::ProcessInput(const InputBridge& inputBridge)
{
	if(MouseInfo::GetInstane().ShapeClicked(_rectangle, sf::Mouse::Button::Left))
	{
		_option.Select();
	}
}
