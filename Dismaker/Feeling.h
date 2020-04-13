#pragma once
#ifndef FEELINGS_H

	#define FEELINGS_H
	#include <map>
	#include <vector>
	#include <string>

	typedef std::map<std::string, int> FeelingMap;
	
	class Feeling
	{
		public:
			Feeling();
			~Feeling();

			void AddFeeling(const std::string& name, int startingValue);
			void AddToFeeling(const std::string& name, int startingValue);
			
			int GetFeeling(const std::string& name);


		private:
			FeelingMap _feelings;
	};

#endif // !FEELINGS_H
