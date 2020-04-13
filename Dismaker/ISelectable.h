#pragma once
#ifndef I_SELECTABLE_H

	#define I_SELECTABLE_H
	
	class World;	

	class ISelectable
	{
		public:
			ISelectable(World world);
			virtual ~ISelectable() = 0;
	};

#endif // !I_SELECTABLE_H
