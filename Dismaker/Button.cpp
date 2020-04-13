#include "Button.h"
#include "Border.h"
#include "RenderableRectangle.h"
#include "TextBox.h"
#include "RenderableComposite.h"
#include "GameUtils.h"

Button::Button(sf::RectangleShape rectangle, GameState::Value gameState) : IGUI(gameState)
{
	_rectangle = rectangle;

	_rendableComposite = new RenderableComposite(gameState);

	_rendableComposite->AddBack(new RenderableRectangle(rectangle, gameState));
}

Button::~Button()
{
	delete _rendableComposite;
}

void Button::AddText(const std::string& text, const sf::Font& font, const sf::Color colour, int _buffer)
{
	//_rendableComposite->AddBack(new TextBox(text, colour, font, _rectangle, _buffer));
}

void Button::AddBorder(const sf::Color colour, float fatness)
{
	_rendableComposite->AddFront(new Border(fatness, _rectangle, colour, GetGameState()));
}

void Button::InternalRender(RenderBridge* renderer, GameState::Value gameState)
{
	_rendableComposite->Render(renderer, gameState);
}