#pragma once
#include "BaseIncludes.h"
#include "DataHolder.h"
#include "DataManager.h"
#include "Noise.h"
#include "Renderer.h"

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

		void addSection(int district, const Section& section, int type);
		void setHeight(int district, int height);
		//Structure Building::generate(int district, int height, const glm::vec2& position)
		void generate(Utilities::Array<Utilities::Array<int>>& map, Utilities::Array<Structure>& structures);

		void setNoiseGenerator(Noise* noise);
		void setDimensions(float width, float height);

		void getData(DataManager* dataManager) override;

	private:
		Noise* noise;
		float width;
		float height;

		Utilities::Array<Section> districtSections[MAX_DISTRICTS][MAX_SECTIONS];
		int districtHeights[MAX_DISTRICTS];
	};
}