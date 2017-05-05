#include "Elicras.h"
using namespace Rendering;

namespace PCG
{
	Elicras::Elicras()
		: noiseGenerator(PERLIN_NOISE)
	{
	}

	Elicras::~Elicras()
	{
	}

	void Elicras::generate(const CityParameters& parameters)
	{
		// clear the map
		const int WIDTH = map.getSize();
		for(int x=0; x<WIDTH; x++)
		{
			const int HEIGHT = map[x].getSize();
			for(int y=0; y<HEIGHT; y++)
			{
				map[x][y] = -3;
			}
		}

		structures.clear();

		// set settings
		for(int i=0; i<MAX_DISTRICTS; i++)
		{
			// TEMP(Niclas): This is not how we should set height
			building.setHeight(i, parameters.maxHeights[i] - parameters.minHeights[i]);
		}

		// set noise generators
		PerlinNoise perlinNoise(parameters.seed);
		RandomNoise randomNoise(parameters.seed);

		Noise* noise = &perlinNoise;
		if(noiseGenerator == RANDOM_NOISE)
		{
			noise = &randomNoise;
		}

		district.setNoiseGenerator(noise);
		block.setNoiseGenerator(noise);
		building.setNoiseGenerator(noise);

		// generate everything
		district.generate(map, width, height);
		block.generate(map);
		building.generate(map, structures);
	}

	void Elicras::addBuildingSection(int district, const Section& section, int type)
	{
		building.addSection(district, section, type);
	}

	void Elicras::useNoiseGenerator(int generator)
	{
		noiseGenerator = generator;
	}

	void Elicras::render(Renderer* renderer)
	{
		// TODO(Niclas): Remove all the magic numbers
		int curStructure = 0;
		for(int x=0; x<width; x++)
		{
			for(int y=0; y<height; y++)
			{
				if(map[x][y] >= 0)
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
					if(map[x][y] == -2)
					{
						texture = horizontalRoadTexture;
					}
					else if(map[x][y] == -3)
					{
						texture = grassTexture;
					}

					renderer->addElement(roadModel, texture, glm::vec3(x*2, 0, y*2));
				}
			}
		}
	}

	void Elicras::setDimensions(int w, int h)
	{
		width = w;
		height = h;

		// remove old values
		const int WIDTH = map.getSize();
		for(int x=0; x<WIDTH; x++)
		{
			map[x].clear();
		}
		map.clear();

		// add new values
		map.reserve(width);
		for(int x=0; x<width; x++)
		{
			Utilities::Array<int> line;
			for(int y=0; y<height; y++)
			{
				line.add(-3);
			}
			map.add(line);
		}

		// set values in generators
		block.setDimensions(width, height);
		building.setDimensions(width, height);
	}

	void Elicras::loadAssets(Assets::AssetManager* assets)
	{
		roadModel = assets->loadModel("./assets/models/house_bot_section.model");
		verticalRoadTexture = assets->loadTexture("./assets/textures/road_vertical.dds");
		horizontalRoadTexture = assets->loadTexture("./assets/textures/road_horizontal.dds");
		grassTexture = assets->loadTexture("./assets/textures/grass1.dds");
	}
}