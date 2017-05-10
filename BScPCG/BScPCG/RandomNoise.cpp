#include "RandomNoise.h"
#include <stdlib.h>
#include <time.h>


namespace PCG
{
	RandomNoise::RandomNoise()
	{
		srand(time(0));
	}

	RandomNoise::RandomNoise(unsigned int seed)
	{
		srand(seed);
	}

	RandomNoise::~RandomNoise()
	{
	}

	void RandomNoise::getData(DataManager * dataManager)
	{
		dataManager->addData("I are just random noise brah", 1337.1337f);
	}

	double RandomNoise::generate(double x, double y, double width, double height)
	{
		// return number between 0-1 just like perlin
		return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	}

	double RandomNoise::generate(double x, double y, double z, double width, double height)
	{
		// return number between 0-1 just like perlin
		return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	}

	void RandomNoise::seed(unsigned int s)
	{
		srand(s);
	}
}