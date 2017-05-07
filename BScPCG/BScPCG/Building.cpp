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

	void Building::setHeight(int district, int height)
	{
		assert(district >= 0 && district < MAX_DISTRICTS);
		assert(height > 0);

		districtHeights[district] = height;
	}

	void Building::setDensity(int district, float density)
	{
		assert(district >= 0 && district < MAX_DISTRICTS);
		assert(density >= 0.0f && density <= 1.0f);

		districtDensities[district] = density;
	}

	/*Structure Building::generate(int district, int height, const glm::vec2& position)
	{
		assert(district >= 0 && district <= MAX_DISTRICTS);

		float noiseResult = noise->generate(position.x, position.y, width, height);

		Utilities::Array<Section>& botSections = districtSections[district][SECTION_BOTTOM];
		Utilities::Array<Section>& midSections = districtSections[district][SECTION_MIDDLE];
		Utilities::Array<Section>& topSections = districtSections[district][SECTION_TOP];

		const int ARBITRARY_LARGE_NUMBER = 100;
		int sectionOffset = (int)(noiseResult*(float)ARBITRARY_LARGE_NUMBER);
		int botSection = sectionOffset % botSections.getSize();
		int midSection = sectionOffset % midSections.getSize();
		int topSection = sectionOffset % topSections.getSize();
		int structureHeight = (int)(noiseResult * (float)height + 0.5f);

		Structure result =
		{
			botSections[botSection],
			midSections[midSection],
			topSections[topSection],
			structureHeight
		};

		return result;
	}*/

	/*void Building::generate(Array<Array<int>>& map, Array<Structure>& structures)
	{
		const int WIDTH = map.getSize();
		for(int x=0; x<WIDTH; x++)
		{
			const int HEIGHT = map[x].getSize();
			for(int y=0; y<HEIGHT; y++)
			{
				int district = map[x][y];
				if(district >= 0)
				{
					// TODO: This should probably come from a user interface variable?
					const float BUILDING_DENSITY = 0.35f;

					float chanceForBuilding = noise->generate(x*10, y*10, width, height);
					if(chanceForBuilding > BUILDING_DENSITY)
					{
						float noiseResult = noise->generate(x*10, y*10, width, height);

						Utilities::Array<Section>& botSections = districtSections[district][SECTION_BOTTOM];
						Utilities::Array<Section>& midSections = districtSections[district][SECTION_MIDDLE];
						Utilities::Array<Section>& topSections = districtSections[district][SECTION_TOP];
						int districtHeight = districtHeights[district];

						const int ARBITRARY_LARGE_NUMBER = 100;
						int sectionOffset = (int)(noiseResult*(float)ARBITRARY_LARGE_NUMBER);
						int botSection = sectionOffset % botSections.getSize();
						int midSection = sectionOffset % midSections.getSize();
						int topSection = sectionOffset % topSections.getSize();
						int structureHeight = (int)(noiseResult * (float)districtHeight + 0.5f);

						Structure structure =
						{
							botSections[botSection],
							midSections[midSection],
							topSections[topSection],
							structureHeight,
						};

						structures.add(structure);
					}
					else
					{
						map[x][y] = -3;
					}
				}
			}
		}
	}*/

	void Building::generate(Array2D<int>& map, Array<Structure>& structures)
	{
		const int WIDTH = map.getWidth();
		for(int x=0; x<WIDTH; x++)
		{
			const int HEIGHT = map.getHeight();
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
						int districtHeight = districtHeights[district];

						const int ARBITRARY_LARGE_NUMBER = 100;
						int sectionOffset = (int)(noiseResult*(float)ARBITRARY_LARGE_NUMBER);
						int botSection = sectionOffset % botSections.getSize();
						int midSection = sectionOffset % midSections.getSize();
						int topSection = sectionOffset % topSections.getSize();
						int structureHeight = (int)(noiseResult * (float)districtHeight + 0.5f);

						Structure structure =
						{
							botSections[botSection],
							midSections[midSection],
							topSections[topSection],
							structureHeight,
						};

						structures.add(structure);
					}
					else
					{
						map.at(x, y) = -3;
					}
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
		//dataManager->addData("building", 2.0f);

		std::stringstream ss;
		for(int i=0; i<MAX_DISTRICTS; i++)
		{
			for(int j=0; j<MAX_SECTIONS; j++)
			{
				int parts = districtSections[i][j].getSize();

				ss.clear();
				ss << "district" << i << "section" << j << "parts";

				dataManager->addData(ss.str(), parts);
			}
		}
	}
}