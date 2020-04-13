#pragma once
#ifndef NOT_IMPLMENTED_EXPECTION_H
	#define NOT_IMPLMENTED_EXPECTION_H
	#include <exception>
	
	class NotImplmentedExpection : public std::exception
	{
		public:
			virtual const char* Trigger() const throw();
	};

#endif // !EXPECTIONS_H