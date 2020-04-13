#include "Player.h"
#include "Configuration.h"
#include "RenderBridge.h"

Player::Player(const char* name)
{
	_name = name;
}

Player::Player() : Player(Configuration::GetInstane()->GetPlayerName().c_str())
{
}

Player::~Player()
{
}

void Player::RenderGreeting(RenderBridge* renderer)
{
	renderer->Text("Hi " + _name + "\n");
}