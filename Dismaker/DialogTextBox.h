#pragma once
#ifndef DIALOG_TEXT_BOX_H

	#define DIALOG_TEXT_BOX_H
	#include "TextBox.h"
	#include "Dialog.h"
	#include "IProcessInput.h"

	#define DIALOG_TEXT_CONFIG_INFO Configuration::GetInstane()->GetDialogTextBoxConnfigInfo()

	class RenderableComposite;
	class OptionTextBox;

	class DialogTextBox : public TextBox, public IProcessInput
	{
		public:
			DialogTextBox(Dialog& dialog, sf::RectangleShape rectangle, GameState::Value gameState);
			~DialogTextBox();
			
			void SetDialog(Dialog& dialog);
			
			void ProcessInput(const InputBridge& inputBridge) override;

		protected:
			void InternalRender(RenderBridge* renderer, GameState::Value gameState);

		private:
			Dialog& _dialog;
			RenderableComposite* _rendableComposite;
			std::vector<OptionTextBox*> _options;
			size_t _selectedIndex;

			void InitilseText();
			void InitliseOptionBoxes();
	};

#endif // !DIALOG_TEXT_BOX
