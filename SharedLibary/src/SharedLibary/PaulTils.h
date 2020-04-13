#pragma once
#ifndef PAUL_TILS_H

	#define PAUL_TILS_H
	#include <fstream>
	#include <vector>
	#include <map>
	#include <type_traits>

	namespace PaulTils	
	{
		int StringToInt(const char* string);
		double StringToDouble(const char* string);
		float StringToFloat(const char* string);

		std::string ToLower(const char* str);
		bool CaseInsensitiveStringCompare(const char* str1, const char* str2);
		bool CaseInsensitiveStringCompare(std::string str1, std::string str2);

		bool FileExists(const char* fileName);
		bool FileExists(std::string fileName);

		std::string GetCurrentDir();

		template<typename F, typename S> bool mapContains(std::map<F, S> &map, F key)
		{
			return map.find(key) != map.end();
		}

		// Foward Delcation would not work pls help got this error  https://drive.google.com/file/d/0Bzi1UPnyCXttVExhTkptZjZSUkE/view?usp=sharing
		template<typename T> void InsertFrontOfVector(std::vector<T> &vector, T toAdd)
		{
			std::vector<T>::iterator it;

			it = vector.begin();
			it = vector.insert(it, toAdd);
		}

		// Foward Delcation would not work pls help got this error  https://drive.google.com/file/d/0Bzi1UPnyCXttVExhTkptZjZSUkE/view?usp=sharing
		template<typename T> void DeleteClear(std::vector<T> &vector)
		{
			vector.clear();
		}

		template<typename T> void DeleteClear(std::vector<T*> &vector)
		{
			for(auto &it : vector)
			{
				delete it;
			}

			vector.clear();
		}
		
		template<typename F, typename S> void DeleteClear(std::map<F, S> &map)
		{

			if(std::is_pointer<F>::value)
			{
				std::vector<F> firstTypeVector;
				
				for each (auto i in map)
				{
					firstTypeVector.push_back(i.first);
				}
				
				DeleteClear(firstTypeVector);
			}


			if(std::is_pointer<S>::value)
			{
				std::vector<S> secoundTypeVector;

				for each (auto i in map)
				{
					secoundTypeVector.push_back(i.second);
				}

				DeleteClear(secoundTypeVector);
			}

			map.clear();
		}

		template<class T, class U> bool IsInstance(U instance)
		{
			return dynamic_cast<T>(instance) != nullptr;
		}

		template<class T, class U> T Find(std::vector<U> vector)
		{
			for each (U i in vector)
			{
				if(IsInstance<U>(i))
				{
					return dynamic_cast<T>(i);
				}
			}

			return NULL;
		}

		template<class T, class U> bool HasInsatnce(std::vector<U> vector)
		{
			return Find<U>(vector) != NULL;
		}
	}

#endif // !UTILS_H
