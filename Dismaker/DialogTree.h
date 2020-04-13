#pragma once
#ifndef DIALOG_TREE_H

	#define DIALOG_TREE_H
	#include <string>
	#include <map>
	#include "Dialog.h"

	class RenderBridge;

	class DialogTree
	{
		public:
			DialogTree(std::map<std::string, Dialog*> dialogMap, const std::string& entrenceNodeID);
			DialogTree();
			~DialogTree();

			void SetData(std::map<std::string, Dialog*> dialogMap, const std::string& entrenceNodeID);

			void ProcessInput(const char* input);

			Dialog* GetActiveNode();
			void ChangeActiveNode(const std::string& connectionID);

		private:
			bool _dataSet;
			std::map<std::string, Dialog*> _dialogMap;
			Dialog* _activeNode;

			Dialog* CopyDialog(Dialog* dialog);

	};

#endif // !DIALOG_TREE_H
