#pragma once
#ifndef IPROCESS_INPUT_H

	#define IPROCESS_INPUT_H
	#include "InputBridge.h"

	class IProcessInput
	{
		public:
			IProcessInput();
			virtual ~IProcessInput() = 0;

			virtual void ProcessInput(const InputBridge& inputBridge) = 0;
	};

#endif // !IPROCESS_INPUT_H
