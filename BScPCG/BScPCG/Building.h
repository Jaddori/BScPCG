#pragma once
#include "BaseIncludes.h"
#include "DataHolder.h"
#include "DataManager.h"
#include "NoiseGenerator.h"

namespace PCG
{
	enum
	{
		SECTION_BOTTOM = 0,
		SECTION_MIDDLE,
		SECTION_TOP,
		MAX_SECTIONS
	};

	struct Section
	{
		int model;
		int texture;
	};

	struct Structure
	{
		Section bottom;
		Section middle;
		Section top;
		int height;
	};

	class Building : public DataHolder
	{
	public:
		Building();
		~Building();

		void addSection(int district, Section section, int type);
		Structure generate(int district, int height, const glm::vec2& position);

		void setNoiseGenerator(NoiseGenerator* noise);
		void setDimensions(float width, float height);

		void getData(DataManager* dataManager) override;

	private:
		NoiseGenerator* noise;
		float width;
		float height;

		Utilities::Array<Section> districtSections[MAX_DISTRICTS][MAX_SECTIONS];
	};
}