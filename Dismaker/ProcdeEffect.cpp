#include "ProcedeEffect.h"
#include "World.h"
#include "DialogTree.h"
#include "DialogHolder.h"

ProcedeEffect::ProcedeEffect(World& world, std::string ownerID, const char* id) : Effect(world)
{
	_ownerID = ownerID;
	_connectionID = id;
}

ProcedeEffect::~ProcedeEffect()
{
}

void ProcedeEffect::Excute()
{
	GetWorld().GetHolder(_ownerID)->GetActiveTree()->ChangeActiveNode(_connectionID.c_str());
}
