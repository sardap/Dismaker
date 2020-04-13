#pragma once
#ifndef DIALOG_HOLDER_H

	#define DIALOG_HOLDER_H
	#include <map>
	#include <string>
	#include "Feeling.h"
	#include <SFML\Graphics.hpp>
	#include "Renderable.h"

	class DialogTree;
	class Dialog;
	class RenderBridge;
	class GameShape;

	typedef std::map<std::string, DialogTree*> DialogTreeMap;

	class DialogHolder : public Renderable
	{
		public:
			DialogHolder
			(
				std::string name, 
				std::string description, 
				Feeling feeling, 
				DialogTreeMap dialogTreeMap, 
				std::string activeTreeID, 
				GameShape* portrait, 
				GameShape* backGround
			);
			~DialogHolder();

			void ProcessInput(const char* input);
			
			bool AreYou(std::string name);

			void SetPortrait(const std::string& portraitID);

			DialogTree* GetActiveTree();
			void SetActiveDialogTree(const char* dialogTreeID);
			Feeling* GetFeeling();

		protected:
			void InternalRender(RenderBridge* renderer, GameState::Value gameState) override;

		private:
			std::string _name;
			std::string _description;
			Feeling _feeling;

			DialogTreeMap _dialogTreeMap;
			std::string _activeTreeID;
			GameShape* _portrait;
			GameShape* _backGround;
	};

#endif // !DIALOG_HOLDER
