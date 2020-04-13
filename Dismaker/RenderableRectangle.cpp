#include "RenderableRectangle.h"
#include "RenderBridge.h"

RenderableRectangle::RenderableRectangle(const sf::RectangleShape& rectangle, GameState::Value gamestate) : IGUI(gamestate)
{
	_rectangle = rectangle;
}

RenderableRectangle::~RenderableRectangle()
{
}

void RenderableRectangle::InternalRender(RenderBridge* renderer, GameState::Value gameState)
{
	renderer->Render(_rectangle);
}

