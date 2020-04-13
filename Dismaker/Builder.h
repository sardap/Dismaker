#pragma once
#ifndef BUILDER_H

	#define BUILDER_H

	class Builder // Abstract
	{
		public:
			Builder();
			virtual ~Builder() = 0;

			virtual void Create(void** objPtr);
			virtual void* Create();

		protected:
			virtual void CreateDirevred(void** objPtr) = 0;
	};

#endif // !BUILDER_H
