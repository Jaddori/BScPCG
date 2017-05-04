#include "Block.h"
using namespace Utilities;

namespace PCG
{
	Block::Block()
		: noise(nullptr), width(0.0f), height(0.0f)
	{
	}

	Block::~Block()
	{
	}
	
	void Block::generate(Array<Array<int>>& map)
	{
		assert(noise != nullptr);

		const int WIDTH = map.getSize();
		assert(WIDTH > 0);

		// generate main roads
		for(int x=0; x<WIDTH; x++)
		{
			float noiseResult = noise->generate(x, 0.0, width, height);
			if(noiseResult > MAIN_ROAD_THRESHOLD)
			{
				const int HEIGHT = map[x].getSize();
				for(int y=0; y<HEIGHT; y++)
				{
					map[x][y] = -1;
				}
			}
		}

		// generate smaller roads
		for(int x=0; x<WIDTH; x++)
		{
			int startX = x;
			while(x < WIDTH && map[x][0] >= 0)
			{
				x++;
			}

			int endX = x;

			const int HEIGHT = map[startX].getSize();
			for(int y=0; y<HEIGHT; y++)
			{
				float noiseResult = noise->generate(x, y, width, height);
				if(noiseResult > SMALL_ROAD_THRESHOLD)
				{
					for(int i=startX; i<endX; i++)
					{
						map[i][y] = -2;
					}
				}
			}
		}
	}

	void Block::setNoiseGenerator(Noise* n)
	{
		noise = n;
	}

	void Block::setDimensions(float w, float h)
	{
		width = w;
		height = h;
	}

	void Block::getData(DataManager * dataManager)
	{
		dataManager->addData("block", 4.20f);
	}
}
