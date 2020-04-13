#include "Effect.h"
#include "World.h"	

Effect::Effect(World& world) : _world(world)
{
}

Effect::~Effect()
{
}

World& Effect::GetWorld()
{
	return _world;
}