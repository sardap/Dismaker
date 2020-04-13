#pragma once
#ifndef KEYBOARD_INPUT_BRIDGE_H

	#define KEYBOARD_INPUT_BRIDGE_H
	#include "InputBridge.h"
	#include <SFML\Graphics.hpp>

	class KeyboardInputBridge : public InputBridge
	{
		public:
			KeyboardInputBridge();
			~KeyboardInputBridge();

			bool InputDown(Input::Value input) const override;

		private:
			sf::Keyboard::Key InputToKey(Input::Value input) const;
	};
	
#endif // !KEYBOARD_INPUT_BRIDGE_H
