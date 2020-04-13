#ifndef DIALOG_HOLDER_BUILDER_H
	
	#define DIALOG_HOLDER_BUILDER_H
	#include <map>
	#include <pugiXML\pugixml.hpp>
	#include <SFML\Graphics.hpp>
	#include "Builder.h"
	#include "DialogHolder.h"

	class World;
	class OptionBuilder;
	class DialogTree;
	class Dialog;
	class Feeling;
	class Effect;
	class GameShape;

	class DialogHolderBuilder : public Builder
	{
		public:
			DialogHolderBuilder();
			~DialogHolderBuilder();

			void SetFileName(const char* fileName);
			void SetWorld(World* world);
			void AddDialogTree(const char* id, DialogTree* tree);

		protected:
			void CreateDirevred(void** objPtr);

		private:
			std::string _fileName;
			World* _world;
			sf::Texture _texture;
			pugi::xml_node _profileNode;
			std::map<std::string, DialogTree*> _dialogTreeMap;
			std::string _id;

			void AddDialogTreeToMap(pugi::xml_node dialogTreeNode);
			Effect* CreateEffectFromXMLNode(pugi::xml_node effectNode);
			Dialog* CreateDialogFromXMLNode(pugi::xml_node dialogNode);
			Feeling CreateFeelingForHolder();
			//  @Bad Fix to use typedef
			std::map<std::string, std::string> CreateTextureLocationMapFromNode(const pugi::xml_node& texturesNode);
			GameShape* CreateBackground(const pugi::xml_node& texturesNode);
			GameShape* CreatePortrait(const pugi::xml_node& texturesNode);
			DialogHolder* CreateDialogHolderFromFile();
	};

#endif // !DIALOG_HOLDER_BUILDER_H
