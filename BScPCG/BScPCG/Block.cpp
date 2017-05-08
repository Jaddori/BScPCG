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
	
	void Block::generate(Array2D<int>& map)
	{
		assert(noise != nullptr);

		const int WIDTH = map.getWidth();
		const int HEIGHT = map.getHeight();
		assert(WIDTH > 0);
		assert(HEIGHT > 0 );

		// reset counters
		mainRoads = 0;
		smallRoads = 0;

		// generate main roads
		for(int x=0; x<WIDTH; x++)
		{
			float noiseResult = noise->generate(x*10.0f, 0.0, width, height);
			noiseResult *= noiseResult;
			if(noiseResult > MAIN_ROAD_THRESHOLD)
			{
				const int HEIGHT = map.getHeight();
				for(int y=0; y<HEIGHT; y++)
				{
					map.at(x, y) = -1;
					mainRoads++;
				}
			}
		}

		// TODO(Niclas): This code could use some comments
		for(int x=0; x<WIDTH; x++)
		{
			int startX = x;
			while(x < WIDTH && map.at(x, 0) >= 0)
			{
				x++;
			}

			int endX = x;

			int next = 0;
			if(rand() % 10 < 5)
			{
				next = 2;
			}
			else
			{
				next = 1;
			}

			for(int y=0; y<HEIGHT; y++)
			{
				if(next > 0)
				{
					next--;
				}
				else
				{
					for(int i=startX; i<endX; i++)
					{
						map.at(i, y) = -2;
						smallRoads++;
					}

					if(rand() % 10 < 5)
					{
						next = 2;
					}
					else
					{
						next = 1;
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
		dataManager->addData("mainRoads", mainRoads);
		dataManager->addData("smallRoads", smallRoads);
	}
}
