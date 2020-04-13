#include "InputBridge.h"
#include "Configuration.h"

InputBridge::InputBridge()
{

	for(size_t i = 0; i != Input::Value::Count; i++)
	{
		_clickState[(Input::Value)i] = InputState::Released;
	}

	_clickWindow = Configuration::GetInstane()->GetClickWindow();
}

InputBridge::~InputBridge()
{
}

void InputBridge::Update(const sf::Time& deltaTime)
{
	for(size_t i = 0; i != Input::Count; i++)
	{
		Input::Value inputI = (Input::Value)i;

		if(_clickState[inputI] == InputState::Released)
		{
			if(InputDown(inputI))
			{
				_clickState[ inputI ] = InputState::Down;
			}
		}
		else if(_clickState[inputI] == InputState::Down)
		{
			if(InputUp(inputI))
			{
				_clickState[inputI] = InputState::Pressed;
			}
		}
		else if(_clickState[inputI] == InputState::Pressed)
		{
			_clickState[inputI] = InputState::Released;
		}
	}
}

bool InputBridge::InputPressed(Input::Value input) const
{
	return _clickState.at(input) == InputState::Pressed;
}

bool InputBridge::InputUp(Input::Value input) const
{
	return !InputDown(input);
}
