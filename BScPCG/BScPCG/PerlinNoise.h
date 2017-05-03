#pragma once
#include "DataHolder.h"
#include "DataManager.h"
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <numeric>

/*
		Base Code from: SolarianProgrammer.com
*/


namespace PCG
{
	class PerlinNoise : public DataHolder
	{
	public:

		std::vector<int> permutations;

		PerlinNoise();
		// Generate a new permutation vector based on the value of seed
		PerlinNoise(unsigned int seed);
		double noise(double x, double y, double xMaxValue, double yMaxValue);

		void getData(DataManager* dataManager) override;
	private:
		double fade(double t);
		double lerp(double t, double a, double b);
		double grad(int hash, double x, double y, double z);
		static unsigned int counter;
	};
}

