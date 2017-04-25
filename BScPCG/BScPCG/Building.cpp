#include "Building.h"


namespace PCG
{
	Building::Building()
	{
	}


	Building::~Building()
	{
	}

	void Building::getData(DataManager * dataManager)
	{
		dataManager->addData("building", 2.0f);
	}
}

