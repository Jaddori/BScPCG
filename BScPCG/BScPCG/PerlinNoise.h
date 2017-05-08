#pragma once
#include "DataManager.h"
#include "Noise.h"
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
	class PerlinNoise : public Noise
	{
	public:

		std::vector<int> permutations;

		PerlinNoise();
		// Generate a new permutation vector based on the value of seed
		PerlinNoise(unsigned int s);
		double noise(double x, double y, double xMaxValue, double yMaxValue);
		double noise(double x, double y, double z, double xMaxValue, double yMaxValue);
		double noise(double x, double y, double z);

		// overrides
		void getData(DataManager* dataManager) override;
		double generate(double x, double y, double width, double height) override;
		double generate(double x, double y, double z, double width, double height) override;
		void seed(unsigned int s);

	private:
		double fade(double t);
		double lerp(double t, double a, double b);
		double grad(int hash, double x, double y, double z);
		static unsigned int counter;
	};
}

