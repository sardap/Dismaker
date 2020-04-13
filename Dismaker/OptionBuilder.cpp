#include "OptionBuilder.h"
#include "Option.h"
#include "Effect.h"
#include "CompositeEffect.h"

OptionBuilder::OptionBuilder()
{
}

OptionBuilder::~OptionBuilder()
{
}

void OptionBuilder::AddEffect(Effect* toAdd)
{
	_effects.push_back(toAdd);
}

void OptionBuilder::AddText(const char* text)
{
	_text = text;
}

void OptionBuilder::SetWorld(World* world)
{
	_world = world;
}


void OptionBuilder::CreateDirevred(void** objPtr)
{
	*objPtr = new Option(_text.c_str(), new CompositeEffect(*_world, _effects));
}