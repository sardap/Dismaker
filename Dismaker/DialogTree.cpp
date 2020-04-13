#include "DialogTree.h"
#include "RenderBridge.h"
#include "Dialog.h"
#include "Option.h"
#include <SharedLibary\PaulTils.h>

DialogTree::DialogTree(std::map<std::string, Dialog*> dialogMap, const std::string& entrenceNodeID)
{
	SetData(dialogMap, entrenceNodeID);
}

DialogTree::DialogTree()
{
	_dataSet = false;
}

DialogTree::~DialogTree()
{
	PaulTils::DeleteClear(_dialogMap);
}

void DialogTree::SetData(std::map<std::string, Dialog*> dialogMap, const std::string& entrenceNodeID)
{
	if(_dataSet)
	{
		exit(0);
	}

	_dataSet = true;

	for each (auto i in dialogMap)
	{
		_dialogMap[i.first] = i.second;
	}
	
	ChangeActiveNode(entrenceNodeID);
}

void DialogTree::ProcessInput(const char* input)
{
	_activeNode->ProcessInput(input);
}

Dialog* DialogTree::GetActiveNode()
{
	return _activeNode;
}

void DialogTree::ChangeActiveNode(const std::string& connectionID)
{
	// @Bad i Should not need to do this
	_activeNode = CopyDialog(_dialogMap[connectionID]);
}

Dialog* DialogTree::CopyDialog(Dialog* dialog)
{
	dialog->PlayAudio();
	// @Fucked Hey i think this is leaking fucktard
	return new Dialog(dialog->GetText(), dialog->GetOptions());
}


