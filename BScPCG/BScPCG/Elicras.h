#pragma once

#include "BaseIncludes.h"
#include "District.h"
#include "Block.h"
#include "Building.h"
#include "PerlinNoise.h"
#include "RandomNoise.h"

namespace PCG
{
	enum
	{
		PERLIN_NOISE = 0,
		RANDOM_NOISE
	};

	class Elicras
	{
	public:
		Elicras();
		~Elicras();

		// TODO(Niclas): Generate should take user input
		void generate();
		void addBuildingSection(int district, const Section& section, int type);
		void useNoiseGenerator(int generator);

		void render(Rendering::Renderer* renderer);

		void setDistrictHeight(int district, int minHeight, int maxHeight);
		void setDimensions(int width, int height);

		// TEMP(Niclas): Should be somewhere else
		void loadAssets(Assets::AssetManager* assets);

	private:
		//District district;
		Block block;
		Building building;

		PerlinNoise perlinNoise;
		RandomNoise randomNoise;

		Utilities::Array<Utilities::Array<int>> map;
		Utilities::Array<Structure> structures;

		int width;
		int height;

		// TEMP(Niclas): Should probably put these somewhere else
		int roadModel;
		int verticalRoadTexture;
		int horizontalRoadTexture;
		int grassTexture;
	};
}