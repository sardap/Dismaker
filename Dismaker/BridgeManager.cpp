#include "BridgerManager.h"
#include "Bridges.h"
#include <SharedLibary\PaulTils.h>
#include "InputBridge.h"
#include "RenderBridge.h"

BridgeManager::BridgeManager()
{
}

BridgeManager::~BridgeManager()
{
	PaulTils::DeleteClear(_bridges);
}

void BridgeManager::AddBridge(Bridge* toAdd)
{
	_bridges.push_back(toAdd);
}
