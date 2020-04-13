#include "TextBox.h"
#include "RenderBridge.h"
#include "ColorUtils.h"
#include "RenderableRectangle.h"

TextBox::TextBox(const std::string& text, const sf::Color& textColor, sf::Font font, const sf::RectangleShape& rectangle, int size, int buffer, const sf::Color& highlightColor, GameState::Value gameState) : IGUI(gameState)
{ 
	_rectangle = rectangle;
	_textColor = textColor;
	_font = font;
	_size = size;
	_buffer = buffer;
	_highlightColor = highlightColor;

	SetText(text);
}

TextBox::~TextBox()
{
}

void TextBox::SetText(const std::string& text)
{
	_text.clear();

	// @Bad Im not smart enough to do this right

	size_t i = 0;
	sf::Vector2f postion = sf::Vector2f(_rectangle.getPosition().x + _buffer, _rectangle.getPosition().y + _buffer);

	while(i < text.length())
	{
		std::string currentText = "";
		sf::Text endText = sf::Text();
		endText.setPosition(postion);
		endText.setFont(_font);
		endText.setFillColor(_textColor);
		endText.setCharacterSize(_size);

		while(endText.getLocalBounds().width < _rectangle.getSize().x - _buffer && i < text.length())
		{
			currentText.push_back(text[i]);

			i++;

			endText.setString(currentText);
		}

		if(endText.getLocalBounds().width > _rectangle.getSize().x - _buffer)
		{
			i--;

			currentText[ currentText.size() - 1 ] = ' ';

			endText.setString(currentText);
		}

		postion.y += endText.getLocalBounds().height + _buffer;

		_text.push_back(endText);
	}

	_rectangle.setSize(sf::Vector2f(_rectangle.getSize().x, (postion.y + _text.back().getGlobalBounds().height) - _rectangle.getPosition().y));
}


sf::FloatRect TextBox::GetBounds()
{
	return sf::FloatRect(_rectangle.getPosition().x, _rectangle.getPosition().y, _rectangle.getSize().x, _rectangle.getSize().y);
}


void TextBox::InternalRender(RenderBridge* renderer, GameState::Value gameState)
{
	for(size_t i = 0; i < _text.size(); i++)
	{
		_text[i].setFont(_font);
		renderer->Text(_text[i]);
	}
}

void TextBox::Highlight(RenderBridge& renderer)
{
	sf::Vector2f oldPostion = _rectangle.getPosition();
	sf::Vector2f oldSize = _rectangle.getSize();

	_rectangle.setPosition(sf::Vector2f(oldPostion.x + _buffer, oldPostion.y + _buffer));
	_rectangle.setSize(sf::Vector2f(oldSize.x - _buffer, oldSize.y - _buffer));

	_rectangle.setFillColor(_highlightColor);

	RenderableRectangle(_rectangle, GetGameState()).Render(&renderer, GetGameState());

	_rectangle.setFillColor(_textColor);

	_rectangle.setPosition(oldPostion);
	_rectangle.setSize(oldSize);
}

