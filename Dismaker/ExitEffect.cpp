#include "ExitEffect.h"
#include <stdlib.h>

ExitEffect::ExitEffect(World& world) : Effect(world)
{
}

ExitEffect::~ExitEffect()
{
}

void ExitEffect::Excute()
{
	exit(-1);
}
