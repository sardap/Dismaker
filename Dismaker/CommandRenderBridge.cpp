#include "CommandRenderBridge.h"
#include <iostream>

CommandRenderBridge::CommandRenderBridge() : RenderBridge()
{
}

CommandRenderBridge::~CommandRenderBridge()
{
}

void CommandRenderBridge::Clear()
{
	system("cls");
}

void CommandRenderBridge::Display()
{
	// Nothing
}

void CommandRenderBridge::Text(const char* text)
{
	std::cout << text;
}

void CommandRenderBridge::Text(const sf::Text& text)
{
	//Text(text.getString().toWideString().c_str());
}

void CommandRenderBridge::Rectangle(const sf::RectangleShape& rectangle)
{
	// Nothing
}
