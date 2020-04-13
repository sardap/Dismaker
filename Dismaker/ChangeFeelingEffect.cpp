#include "ChangeFeelingEffect.h"
#include "DialogHolder.h"
#include "World.h"

ChangeFeelingEffect::ChangeFeelingEffect(World& world, const std::string& dialogHolderId, const std::string& feelingName, int value) : Effect(world)
{
	_holder = dialogHolderId;
	_feelingName = feelingName;
	_value = value;
}

ChangeFeelingEffect::~ChangeFeelingEffect()
{
}

void ChangeFeelingEffect::Excute()
{
	GetWorld().GetHolder(_holder)->GetFeeling()->AddToFeeling(_feelingName, _value);
}
