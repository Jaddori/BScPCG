#include "Building.h"
using namespace Utilities;

namespace PCG
{
	Building::Building()
		: noise(nullptr), width(0.0f), height(0.0f)
	{
	}

	Building::~Building()
	{
	}

	void Building::addSection(int district, const Section& section, int type)
	{
		assert(district >= 0 && district < MAX_DISTRICTS);
		assert(type >= SECTION_BOTTOM && type <= SECTION_TOP);

		districtSections[district][type].add(section);
	}

	void Building::setHeight(int district, int minHeight, int maxHeight)
	{
		assert(district >= 0 && district < MAX_DISTRICTS);
		assert(height > 0);

		districtMinHeights[district] = minHeight;
		districtMaxHeights[district] = maxHeight;
	}

	void Building::setDensity(int district, float density)
	{
		assert(district >= 0 && district < MAX_DISTRICTS);
		assert(density >= 0.0f && density <= 1.0f);

		districtDensities[district] = density;
	}

	void Building::generate(Array2D<int>& map, Array<Structure>& structures)
	{
		// reset counters
		for(int i=0; i<MAX_DISTRICTS; i++)
		{
			buildings[i] = 0;
			grassTiles[i] = 0;
		}

		// generate buildings
		const int WIDTH = map.getWidth();
		const int HEIGHT = map.getHeight();

		for(int x=0; x<WIDTH; x++)
		{
			for(int y=0; y<HEIGHT; y++)
			{
				int district = map.at(x, y);
				if(district >= 0)
				{
					const float BUILDING_DENSITY = districtDensities[district];

					float chanceForBuilding = noise->generate(x*10, y*10, width, height);
					if(chanceForBuilding < BUILDING_DENSITY)
					{
						float noiseResult = noise->generate(x*10, y*10, width, height);

						Utilities::Array<Section>& botSections = districtSections[district][SECTION_BOTTOM];
						Utilities::Array<Section>& midSections = districtSections[district][SECTION_MIDDLE];
						Utilities::Array<Section>& topSections = districtSections[district][SECTION_TOP];
						
						const int MIN_HEIGHT = districtMinHeights[district];
						const int MAX_HEIGHT = districtMaxHeights[district];
						const int HEIGHT_DIF = MAX_HEIGHT - MIN_HEIGHT;

						const int ARBITRARY_LARGE_NUMBER = 100;
						int sectionOffset = (int)(noiseResult*(float)ARBITRARY_LARGE_NUMBER);
						int botSection = sectionOffset % botSections.getSize();
						int midSection = sectionOffset % midSections.getSize();
						int topSection = sectionOffset % topSections.getSize();
						int structureHeight = (int)(noiseResult * (float)(HEIGHT_DIF+0.5f))+MIN_HEIGHT;

						Structure structure =
						{
							botSections[botSection],
							midSections[midSection],
							topSections[topSection],
							structureHeight,
						};

						structures.add(structure);
						buildings[district]++;
					}
					else
					{
						map.at(x, y) = -3;
						grassTiles[district]++;
					}
				}
			}
		}
	}

	void Building::fullRandom(Array2D<int>& map, Array<Structure>& structures)
	{
		const int WIDTH = map.getWidth();
		const int HEIGHT = map.getHeight();

		for(int x=0; x<WIDTH; x++)
		{
			for(int y=0; y<HEIGHT; y++)
			{
				int district = map.at(x, y);
				if(district >= 0)
				{
					Utilities::Array<Section>& botSections = districtSections[district][SECTION_BOTTOM];
					Utilities::Array<Section>& midSections = districtSections[district][SECTION_MIDDLE];
					Utilities::Array<Section>& topSections = districtSections[district][SECTION_TOP];

					int botSection = rand() % botSections.getSize();
					int midSection = rand() % midSections.getSize();
					int topSection = rand() % topSections.getSize();
					int structureHeight = rand() % 10;

					Structure structure =
					{
						botSections[botSection],
						midSections[midSection],
						topSections[topSection],
						structureHeight,
					};

					structures.add(structure);
				}
			}
		}
	}

	void Building::setNoiseGenerator(Noise* n)
	{
		noise = n;
	}

	void Building::setDimensions(float w, float h)
	{
		width = w;
		height = h;
	}

	void Building::getData(DataManager * dataManager)
	{
		dataManager->addData("district1Buildings", buildings[0]);
		dataManager->addData("district2Buildings", buildings[1]);
		dataManager->addData("district3Buildings", buildings[2]);
		dataManager->addData("totalBuildings", buildings[0]+buildings[1]+buildings[2]);

		dataManager->addData("district1Grass", grassTiles[0]);
		dataManager->addData("district2Grass", grassTiles[1]);
		dataManager->addData("district3Grass", grassTiles[2]);
		dataManager->addData("totalGrass", grassTiles[0]+grassTiles[1]+grassTiles[2]);
	}
}