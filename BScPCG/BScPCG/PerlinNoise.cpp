#include "PerlinNoise.h"


namespace PCG
{
	unsigned int PerlinNoise::counter = 0;

	PerlinNoise::PerlinNoise()
	{
	}


	PerlinNoise::~PerlinNoise()
	{
	}

	void PerlinNoise::getData(DataManager * dataManager)
	{
		dataManager->addData("perlinNoise", 4.0f);
	}
}
