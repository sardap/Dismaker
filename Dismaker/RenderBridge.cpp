#include "RenderBridge.h"
#include "SFMLManager.h"

RenderBridge::RenderBridge()
{
}

RenderBridge::~RenderBridge()
{
}

void RenderBridge::Text(std::string text)
{
	Text(text.c_str());
}


void RenderBridge::Clear()
{
	SFMLManager::GetInstane()->GetRenderWindow()->clear();
}

void RenderBridge::Display()
{
	SFMLManager::GetInstane()->GetRenderWindow()->display();
}


void RenderBridge::Text(const char* text)
{
	// @ToDo Create this
}

void RenderBridge::Text(const sf::Text& text)
{
	Render(text);
}

void RenderBridge::Rectangle(const sf::RectangleShape& rectangle)
{
	Render(rectangle);
}

void RenderBridge::Render(const sf::Drawable& drawable)
{
	SFMLManager::GetInstane()->GetRenderWindow()->draw(drawable, sf::RenderStates());
}

