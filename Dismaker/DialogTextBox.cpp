#include "DialogTextBox.h"
#include "Configuration.h"
#include "RenderBridge.h"
#include "Border.h"
#include "RenderableComposite.h"
#include "ColorUtils.h"
#include "Border.h"
#include "RenderableRectangle.h"
#include "Option.h"
#include "OptionTextBox.h"
#include <SharedLibary\PaulTils.h>
#include <unordered_set>

DialogTextBox::DialogTextBox(Dialog& dialog, sf::RectangleShape rectangle, GameState::Value gameState) :
TextBox
(
	dialog.GetText(), 
	DIALOG_TEXT_CONFIG_INFO.textInfo.textColor, 
	DIALOG_TEXT_CONFIG_INFO.textInfo.font, 
	rectangle,
	DIALOG_TEXT_CONFIG_INFO.textInfo.size,
	DIALOG_TEXT_CONFIG_INFO.textInfo._buffer,
	sf::Color(27, 161, 226, 127),
	gameState
), _dialog(dialog)
{
	_rectangle = rectangle;
	_rectangle.setFillColor(DIALOG_TEXT_CONFIG_INFO.rectangleInfo.fillColor);

	_rendableComposite = new RenderableComposite(gameState);

	_rendableComposite->AddBack(new RenderableRectangle(_rectangle, gameState));
	_rendableComposite->AddFront
	(
		new Border
		(
			DIALOG_TEXT_CONFIG_INFO.borderInfo.borderFatness, 
			_rectangle, 
			DIALOG_TEXT_CONFIG_INFO.borderInfo.fillColor, 
			gameState
		)
	);

	InitilseText();
	InitliseOptionBoxes();
}

DialogTextBox::~DialogTextBox()
{
	delete _rendableComposite;
	PaulTils::DeleteClear(_options);
}

void DialogTextBox::SetDialog(Dialog& dialog)
{
	if(dialog.GetText() != _dialog.GetText() && dialog.GetOptions() != _dialog.GetOptions())
	{
		_selectedIndex = 0;

		_dialog = dialog;

		InitilseText();
		InitliseOptionBoxes();
	}
}

void DialogTextBox::InternalRender(RenderBridge* renderer, GameState::Value gameState)
{
	_rendableComposite->Render(renderer, gameState);
	TextBox::InternalRender(renderer, gameState);

	for each (OptionTextBox* i in _options)
	{
		i->Render(renderer, gameState);
	}

	_options[_selectedIndex]->Highlight(*renderer);
}


void DialogTextBox::ProcessInput(const InputBridge& inputBridge)
{
	if(inputBridge.InputPressed(Input::Enter))
	{
		_options[_selectedIndex]->Select();
	}
	else if(inputBridge.InputPressed(Input::Up))
	{
		if(_selectedIndex - 1 != std::numeric_limits<size_t>::max())
		{
			_selectedIndex--;
		}
	}
	else if(inputBridge.InputPressed(Input::Down))
	{
		if(_selectedIndex + 1 < _options.size())
		{
			_selectedIndex++;
		}
	}
}

void DialogTextBox::InitilseText()
{
	SetText(_dialog.GetText());
}

void DialogTextBox::InitliseOptionBoxes()
{
	PaulTils::DeleteClear(_options);

	sf::FloatRect lastRect = GetBounds();

	for each (Option* option in _dialog.GetOptions())
	{
		sf::RectangleShape rectangle = sf::RectangleShape();

		rectangle.setPosition
		(
			_rectangle.getPosition().x,
			lastRect.top + lastRect.height
		);

		rectangle.setSize
		(
			sf::Vector2f
			(
				_rectangle.getSize().x,
				_rectangle.getSize().y - (rectangle.getPosition().y)
			)
		);

		_options.push_back
		(
			new OptionTextBox
			(
				*option,
				rectangle
			)
		);

		lastRect = _options.back()->GetBounds();
	}
}