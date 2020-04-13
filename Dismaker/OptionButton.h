#pragma once
#ifndef OPTION_BUTTON_H

	#define OPTION_BUTTON_H
	#include "Option.h"
	#include "Button.h"
	
	class OptionButton : public Button
	{
		public:
			OptionButton(Option& option, sf::RectangleShape rectangle, GameState::Value gameState);
			~OptionButton();

			void ProcessInput(const InputBridge& inputBridge) override;

		private:
			Option& _option;
	};

#endif // !DIALOG_BUTTON_H
