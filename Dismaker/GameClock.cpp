#include "GameClock.h"

GameClock::GameClock()
{
	_clock.restart();
}

GameClock::~GameClock()
{
}

void GameClock::LoopStart()
{
	_lastTime = _clock.getElapsedTime();
	_clock.restart();
}

const sf::Time& GameClock::GetDeltaTime()
{
	return _lastTime - _clock.getElapsedTime();
}