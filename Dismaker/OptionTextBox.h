#pragma once
#ifndef OPTION_TEXT_BOX_H

	#define OPTION_TEXT_BOX_H
	#include "TextBox.h"

	class Option;

	class OptionTextBox : public TextBox
	{
		public:
			OptionTextBox(Option& option, sf::RectangleShape rectangle);
			~OptionTextBox();

			void Select();

			sf::Text* GetLastText();

		private:
			Option& _option;

	};

#endif // !OPTION_TEXT_BOX_H
