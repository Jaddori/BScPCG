#include "District.h"



namespace PCG
{
	District::District()
	{
	}


	District::~District()
	{
	}

	void District::getData(DataManager * dataManager)
	{
		dataManager->addData("District", 1.0f);
	}
}