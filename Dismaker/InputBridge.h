#pragma once
#ifndef INPUT_BRIDGE_H

	#define INPUT_BRIDGE_H
	#include <map>
	#include "Bridge.h"
	#include "Inputs.h"
	#include "InputState.h"
	#include <SFML\System\Time.hpp>

	class InputBridge : public Bridge
	{
		public:
			InputBridge();
			~InputBridge();

			void Update(const sf::Time& deltaTime);

			bool InputPressed(Input::Value input) const;
			virtual bool InputDown(Input::Value input) const = 0;
			bool InputUp(Input::Value input) const;

		protected:
			std::map<Input::Value, InputState::Value> _clickState;

		private:
			int _clickWindow;
	};

#endif // !INPUT_BRIDGE_H
