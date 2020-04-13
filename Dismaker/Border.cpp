#include "Border.h"
#include "RenderBridge.h"
#include "ColorUtils.h"
#include "RenderableRectangle.h"
#include "RenderableComposite.h"
#include <SharedLibary\PaulTils.h>

Border::Border(int fatness, sf::RectangleShape rectangle, sf::Color colour, GameState::Value gamestate) : IGUI(gamestate)
{
	std::vector<sf::RectangleShape> tempVector;

	sf::RectangleShape temp;
	
	// | <-
	temp.setPosition(sf::Vector2f(rectangle.getPosition().x - fatness, rectangle.getPosition().y - fatness));
	temp.setSize(sf::Vector2f(fatness, rectangle.getSize().y + fatness));
	tempVector.push_back(temp);
	
	// - ^
	temp.setPosition(temp.getPosition());
	temp.setSize(sf::Vector2f(rectangle.getSize().x + fatness, fatness));
	tempVector.push_back(temp);

	// | ->
	temp.setPosition(sf::Vector2f(rectangle.getPosition().x + rectangle.getSize().x, rectangle.getPosition().y - fatness));
	temp.setSize(sf::Vector2f(fatness, rectangle.getSize().y + fatness));
	tempVector.push_back(temp);

	// - Bot
	temp.setPosition(sf::Vector2f(rectangle.getPosition().x - fatness, rectangle.getPosition().y + rectangle.getSize().y));
	temp.setSize(sf::Vector2f(tempVector[1].getSize().x + fatness, fatness));
	tempVector.push_back(temp);

	for(size_t i = 0; i < tempVector.size(); i++)
	{
		tempVector[i].setFillColor(colour);
	}

	_renderables = new RenderableComposite(gamestate);

	for(size_t i = 0; i < tempVector.size(); i++)
	{
		_renderables->AddBack(new RenderableRectangle(tempVector[i], gamestate));
	}

	/*
	for each (auto i in tempVector)
	{
		_renderables->AddBack(new RenderableRectangle(i, gamestate));
	}
	*/
}

Border::Border(int fatness, sf::RectangleShape rectangle, GameState::Value gamestate) : Border(fatness, rectangle, rectangle.getFillColor(), gamestate)
{
}

Border::~Border()
{
	delete _renderables;
}

void Border::InternalRender(RenderBridge* renderer, GameState::Value gameState)
{
	_renderables->Render(renderer, gameState);
}