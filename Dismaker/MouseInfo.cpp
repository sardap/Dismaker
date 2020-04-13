#include "MouseInfo.h"
#include "GameUtils.h"
#include "GameExpections.h"
#include "Configuration.h"
#include <iostream>
#include "SFMLManager.h"

MouseInfo& MouseInfo::GetInstane()
{
	return *_dialogTree;
}

MouseInfo* MouseInfo::_dialogTree = nullptr;

bool MouseInfo::_singletonCreated = false;

MouseInfo::MouseInfo()
{
	if(!_singletonCreated)
	{
		_singletonCreated = true;
		
		_dialogTree = this;
	}
	else
	{
		throw SINGLETON_CRETED_ALREADY;
	}

	for(size_t i = 0; i != sf::Mouse::Button::ButtonCount; i++)
	{
		_clickState.insert(std::pair<sf::Mouse::Button, int64_t>((sf::Mouse::Button)i, 0));
	}

	_clickWindow = Configuration::GetInstane()->GetClickWindow();
}

MouseInfo::~MouseInfo()
{
}

bool MouseInfo::ButtonClicked(sf::Mouse::Button button)
{
	return _clickState[button] == -1;
}

bool MouseInfo::ShapeClicked(const sf::Shape& shape, sf::Mouse::Button button)
{
	return GameUtils::ShapeContainsPostion(shape, GetMousePostion()) && ButtonClicked(button);
}

void MouseInfo::Update(const sf::Time& deltaTime)
{
	for(size_t i = 0; i != sf::Mouse::Button::ButtonCount; i++)
	{
		sf::Mouse::Button mbi = (sf::Mouse::Button)i;

		if(sf::Mouse::isButtonPressed(mbi))
		{
			_clickState[mbi] += deltaTime.asMicroseconds();
		}
		else
		{
			if(_clickState[mbi] > 0 && _clickState[mbi] < _clickWindow)
			{
				_clickState[mbi] = -1;
			}
			else
			{
				_clickState[mbi] = 0;
			}
		}
	}
}

sf::Vector2f MouseInfo::GetMousePostion()
{
	return static_cast<sf::Vector2f>(sf::Mouse::getPosition(*SFMLManager::GetInstane()->GetWindow()));
}