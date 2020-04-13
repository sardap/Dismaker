#include "SFMLRenderBridge.h"
#include "SFMLManager.h"
#include <iostream>

SFMLRednerBridge::SFMLRednerBridge()
{
}

SFMLRednerBridge::~SFMLRednerBridge()
{
}

void SFMLRednerBridge::Clear()
{
	SFMLManager::GetInstane()->GetRenderWindow()->clear();
}

void SFMLRednerBridge::Display()
{
	SFMLManager::GetInstane()->GetRenderWindow()->display();
}


void SFMLRednerBridge::Text(const char* text)
{
	// @ToDo Create this
}

void SFMLRednerBridge::Text(const sf::Text& text)
{
	Render(text);
}

void SFMLRednerBridge::Rectangle(const sf::RectangleShape& rectangle)
{
	Render(rectangle);
}

void SFMLRednerBridge::Render(const sf::Drawable& drawable)
{
	SFMLManager::GetInstane()->GetRenderWindow()->draw(drawable, sf::RenderStates());
}


