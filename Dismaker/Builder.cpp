#include "Builder.h"

Builder::Builder()
{

}

Builder::~Builder()
{
}

void Builder::Create(void** objPtr)
{
	CreateDirevred(objPtr);
}

void* Builder::Create()
{
	void* objPtr;

	Create(&objPtr);

	return objPtr;
}

