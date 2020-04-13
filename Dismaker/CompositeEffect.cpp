#include "CompositeEffect.h"
#include <SharedLibary\PaulTils.h>


CompositeEffect::CompositeEffect(World& world, std::vector<Effect*> effects) : Effect(world)
{
	AddEffect(effects);
}

CompositeEffect::~CompositeEffect()
{
	for(size_t i = 0; i < _elements.size(); i++)
	{
		delete _elements[i];
	}
}

void CompositeEffect::Excute()
{
	for each (Effect* i in _elements)
	{
		i->Excute();
	}
}

void CompositeEffect::AddEffect(std::vector<Effect*> toAdd)
{
	for each (Effect* i in toAdd)
	{
		PaulTils::InsertFrontOfVector(_elements, i);
	}
}
