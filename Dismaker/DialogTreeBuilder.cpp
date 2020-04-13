#include "DialogTreeBuilder.h"
#include "Dialog.h"
#include "DialogTree.h"

DialogTreeBuilder::DialogTreeBuilder()
{
	_dialogTree = new DialogTree();
}

DialogTreeBuilder::~DialogTreeBuilder()
{
}

void DialogTreeBuilder::AddDialog(std::string id, Dialog* dialog)
{
	_dialogMap[id] = dialog;
}

void DialogTreeBuilder::SetEntrance(std::string id)
{
	_entranceID = id;
}

void DialogTreeBuilder::CreateDirevred(void** objPtr)
{
	_dialogTree->SetData(_dialogMap, _entranceID);

	*objPtr = _dialogTree;
}
