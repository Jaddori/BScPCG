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

	struct CityParameters
	{
		int seed;
		int minHeights[MAX_DISTRICTS];
		int maxHeights[MAX_DISTRICTS];
		float densities[MAX_DISTRICTS];
		int blockSizes[MAX_DISTRICTS];
	};

	class Elicras
	{
	public:
		Elicras();
		~Elicras();

		// TODO(Niclas): Generate should take user input
		void generate(const CityParameters& parameters);
		void fullRandom();
		void addBuildingSection(int district, const Section& section, int type);
		void useNoiseGenerator(int generator);

		void setRenderer(Rendering::Renderer* renderer);
		void setDimensions(int width, int height);

		float getStatistic(const std::string& name);

		// TEMP(Niclas): Should be somewhere else
		void loadAssets(Assets::AssetManager* assets);

	private:
		Rendering::Renderer* renderer;
		District district;
		Block block;
		Building building;
		DataManager dataManager;

		//Utilities::Array<Utilities::Array<int>> map;
		Utilities::Array2D<int> map;
		Utilities::Array<Structure> structures;

		PerlinNoise perlinNoise;
		RandomNoise randomNoise;
		int width;
		int height;

		// TEMP(Niclas): Should probably put these somewhere else
		int roadModel;
		int verticalRoadTexture;
		int horizontalRoadTexture;
		int grassTexture;
	};
}