#include "ChangePortiratEffect.h"
#include "World.h"
#include "DialogHolder.h"

ChangePortiratEffect::ChangePortiratEffect(World& world, std::string holderID, std::string portraitID) : Effect(world)
{
	_holderID = holderID;
	_portraitID = portraitID;
}

ChangePortiratEffect::~ChangePortiratEffect()
{
}

void ChangePortiratEffect::Excute()
{
	GetWorld().GetHolder(_holderID)->SetPortrait(_portraitID);
}