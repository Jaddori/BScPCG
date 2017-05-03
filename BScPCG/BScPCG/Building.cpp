#include "Building.h"

namespace PCG
{
	Building::Building()
		: noise(nullptr), width(0.0f), height(0.0f)
	{
	}

	Building::~Building()
	{
	}

	void Building::addSection(int district, Section section, int type)
	{
		assert(district >= 0 && district <= MAX_DISTRICTS);
		assert(type >= SECTION_BOTTOM && type <= SECTION_TOP);

		districtSections[district][type].add(section);
	}

	Structure Building::generate(int district, int height, const glm::vec2& position)
	{
		assert(district >= 0 && district <= MAX_DISTRICTS);

		float noiseResult = noise->generate(position.x, position.y, width, height);

		Utilities::Array<Section>& botSections = districtSections[district][SECTION_BOTTOM];
		Utilities::Array<Section>& midSections = districtSections[district][SECTION_MIDDLE];
		Utilities::Array<Section>& topSections = districtSections[district][SECTION_TOP];

		int botSection = noiseResult * botSections.getSize();
		int midSection = noiseResult * midSections.getSize();
		int topSection = noiseResult * topSections.getSize();
		int structureHeight = noiseResult * height;

		Structure result =
		{
			botSections[botSection],
			midSections[midSection],
			topSections[topSection],
			structureHeight
		};

		return result;
	}

	void Building::setNoiseGenerator(NoiseGenerator* n)
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
		dataManager->addData("building", 2.0f);
	}
}