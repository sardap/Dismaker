#pragma once
#ifndef DIALOG_H
	#define DIALOG_H
	#include <vector>
	#include <string>
	
	class Option;

	class Dialog
	{
		public:
			Dialog(std::string text, std::vector<Option*> options, std::string fileLocation = "");
			Dialog(std::string text, Option* option, std::string fileLocation = "");
			Dialog(std::string text, std::string fileLocation = "");
			Dialog();
			~Dialog();
			
			std::string GetText() const;

			std::vector<Option*> GetOptions();
			void AddOption(Option* option);

			void PlayAudio();
			void ProcessInput(const char* input);

		private:
			std::string _text;
			std::string _fileLocation;
			std::vector<Option*> _options;
	};

#endif // !DIALOG_H
