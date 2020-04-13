#pragma once
#ifndef DIALOG_TREE_BUILDER_H

	#define DIALOG_TREE_BUILDER_H
	#include <map>
	#include <string>
	#include "Builder.h"

	class Dialog;
	class DialogTree;

	class DialogTreeBuilder : public Builder
	{
		public:
			DialogTreeBuilder();
			~DialogTreeBuilder();

			void AddDialog(std::string, Dialog* dialog);
			void SetEntrance(std::string id);

		protected:
			void CreateDirevred(void** objPtr);

		private:
			DialogTree* _dialogTree;
			std::string _entranceID;
			std::map<std::string, Dialog*> _dialogMap;
	};
	

#endif // !DIALOG_TREE_H
