#include "gtest\gtest.h"
#include "DataManager.h"
#include "District.h"
#include "Building.h"

using namespace PCG;

int main( int argc, char** argv )
{
	::testing::InitGoogleTest( &argc, argv );

	DataManager* dataManager = new DataManager();
	District* district = new District();
	Building* building = new Building();

	dataManager->addDataHolder(district);
	dataManager->addDataHolder(building);

	dataManager->collectData();
	dataManager->collectData();
	dataManager->collectData();
	dataManager->showData();
	float t1 = dataManager->getData("building");
	int derp;
	std::cin >> derp;
	return RUN_ALL_TESTS( );
}