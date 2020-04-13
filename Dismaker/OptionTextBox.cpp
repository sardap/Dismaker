#include "OptionTextBox.h"
#include "Option.h"
#include "Configuration.h"
#include "DialogTextBox.h"

OptionTextBox::OptionTextBox(Option& option, sf::RectangleShape rectangle) :
TextBox
(
	option.GetText(),
	DIALOG_TEXT_CONFIG_INFO.textInfo.textColor,
	DIALOG_TEXT_CONFIG_INFO.textInfo.font,
	rectangle,
	DIALOG_TEXT_CONFIG_INFO.textInfo.size,
	DIALOG_TEXT_CONFIG_INFO.textInfo._buffer
), _option(option)
{
}

OptionTextBox::~OptionTextBox()
{
}

void OptionTextBox::Select()
{
	_option.Select();
}

sf::Text* OptionTextBox::GetLastText()
{
	return &_text.back();
}

