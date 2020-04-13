#pragma once
#ifndef BRIDGE_MANAGER_H
	
	#define BRIDGE_MANAGER_H
	#include <vector>
	#include <typeinfo>
	#include <string>
	#include <SharedLibary\PaulTils.h>

	class Bridge;	

	class BridgeManager
	{
		public:
			BridgeManager();
			~BridgeManager();

			void AddBridge(Bridge* toAdd);

			template<typename T> T GetBridge()
			{
				for each (Bridge* i in _bridges)
				{
					if(PaulTils::IsInstance<T>(i))
					{
						return (T) i;
					}
				}

				throw "Not Found";
			}

		private:
			std::vector<Bridge*> _bridges;
	};

#endif // !BRIDGE_MANAGER_H
