#include "District.h"




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
