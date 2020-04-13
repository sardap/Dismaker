#include "KeyBoardInputBridge.h"

KeyboardInputBridge::KeyboardInputBridge() : InputBridge()
{

}

KeyboardInputBridge::~KeyboardInputBridge()
{
}

bool KeyboardInputBridge::InputDown(Input::Value input) const
{
	return sf::Keyboard::isKeyPressed(InputToKey(input));
}

sf::Keyboard::Key KeyboardInputBridge::InputToKey(Input::Value input) const
{
	switch(input)
	{
		case Input::Up:
			return sf::Keyboard::Up;

		case Input::Down:
			return sf::Keyboard::Down;

		case Input::Left:
			return sf::Keyboard::Left;

		case Input::Right:
			return sf::Keyboard::Right;

		case Input::Enter:
			return sf::Keyboard::Return;

		case Input::Escape:
			return sf::Keyboard::Escape;

		default:
			throw "Input Not found";
	}
}
