#include "Elicras.h"
using namespace Rendering;

namespace PCG
{
	Elicras::Elicras()
	{
		dataManager.addDataHolder(&district);
		dataManager.addDataHolder(&block);
		dataManager.addDataHolder(&building);
		dataManager.addDataHolder(&perlinNoise);

		useNoiseGenerator(PERLIN_NOISE);
	}

	Elicras::~Elicras()
	{
	}

	void Elicras::generate(const CityParameters& parameters)
	{
		assert(renderer != nullptr);

		// clear the map
		map.fill(-3);
		structures.clear();

		// set settings
		for(int i=0; i<MAX_DISTRICTS; i++)
		{
			building.setHeight(i, parameters.minHeights[i], parameters.maxHeights[i]);
			building.setDensity(i, parameters.densities[i]);
			block.setBlockSize(i, parameters.blockSizes[i]);
		}

		// seed the noise generators
		perlinNoise.seed(parameters.seed);
		randomNoise.seed(parameters.seed);

		// generate everything
		district.generate(map, width, height);
		block.generate(map);
		building.generate(map, structures);

		// add structures to render queue
		renderer->begin();
		// TODO(Niclas): Remove all the magic numbers
		int curStructure = 0;
		for(int x=0; x<width; x++)
		{
			for(int y=0; y<height; y++)
			{
				int cellValue = map.at(x, y);
				if(cellValue >= 0)
				{
					const int NUM_STRUCTURES = structures.getSize();
					Structure& s = structures[curStructure];
					curStructure++;

					glm::vec3 position(x*2, 0.0f, y*2);

					// render bottom section
					renderer->addElement(s.bottom.model, s.bottom.texture, position);
					position.y += 0.7f;

					// render middle sections
					for(int i=0; i<s.height; i++)
					{
						renderer->addElement(s.middle.model, s.middle.texture, position);
						position.y += 2.0f;
					}

					// render top section
					renderer->addElement(s.top.model, s.top.texture, position);
				}
				else
				{
					int texture = verticalRoadTexture;
					if(cellValue == -2)
					{
						texture = horizontalRoadTexture;
					}
					else if(cellValue == -3)
					{
						texture = grassTexture;
					}

					renderer->addElement(roadModel, texture, glm::vec3(x*2, 0, y*2));
				}
			}
		}
		renderer->end();

		// collect statistics
		dataManager.collectData();
	}

	void Elicras::fullRandom()
	{
		assert(renderer != nullptr);

		// clear the map
		map.fill(-3);
		structures.clear();

		// generate everything
		for(int x=0; x<map.getWidth(); x++)
		{
			for(int y=0; y<map.getHeight(); y++)
			{
				int val = (rand() % 6)-3;
				map.at(x, y) = val;
			}
		}
		building.fullRandom(map, structures);

		// add structures to render queue
		renderer->begin();
		// TODO(Niclas): Remove all the magic numbers
		int curStructure = 0;
		for(int x=0; x<width; x++)
		{
			for(int y=0; y<height; y++)
			{
				int cellValue = map.at(x, y);
				if(cellValue >= 0)
				{
					const int NUM_STRUCTURES = structures.getSize();
					Structure& s = structures[curStructure];
					curStructure++;

					glm::vec3 position(x*2, 0.0f, y*2);

					// render bottom section
					renderer->addElement(s.bottom.model, s.bottom.texture, position);
					position.y += 0.7f;

					// render middle sections
					for(int i=0; i<s.height; i++)
					{
						renderer->addElement(s.middle.model, s.middle.texture, position);
						position.y += 2.0f;
					}

					// render top section
					renderer->addElement(s.top.model, s.top.texture, position);
				}
				else
				{
					int texture = verticalRoadTexture;
					if(cellValue == -2)
					{
						texture = horizontalRoadTexture;
					}
					else if(cellValue == -3)
					{
						texture = grassTexture;
					}

					renderer->addElement(roadModel, texture, glm::vec3(x*2, 0, y*2));
				}
			}
		}
		renderer->end();
	}

	void Elicras::addBuildingSection(int district, const Section& section, int type)
	{
		building.addSection(district, section, type);
	}

	void Elicras::useNoiseGenerator(int generator)
	{
		if(generator == PERLIN_NOISE)
		{
			district.setNoiseGenerator(&perlinNoise);
			block.setNoiseGenerator(&perlinNoise);
			building.setNoiseGenerator(&perlinNoise);
		}
		else
		{
			district.setNoiseGenerator(&randomNoise);
			block.setNoiseGenerator(&randomNoise);
			building.setNoiseGenerator(&randomNoise);
		}
	}

	void Elicras::setRenderer(Renderer* r)
	{
		renderer = r;
	}

	void Elicras::setDimensions(int w, int h)
	{
		width = w;
		height = h;

		// clear map
		map.resize(width, height);
		map.fill(-3);

		// set values in generators
		block.setDimensions(width, height);
		building.setDimensions(width, height);
	}

	float Elicras::getStatistic(const std::string& name)
	{
		return dataManager.getData(name);
	}

	void Elicras::loadAssets(Assets::AssetManager* assets)
	{
		roadModel = assets->loadModel("./assets/models/house_bot_section.model");
		verticalRoadTexture = assets->loadTexture("./assets/textures/road_vertical.dds");
		horizontalRoadTexture = assets->loadTexture("./assets/textures/road_horizontal.dds");
		grassTexture = assets->loadTexture("./assets/textures/grass1.dds");
	}
}