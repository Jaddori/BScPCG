#pragma once
#include "Noise.h"
#include "DataManager.h"
namespace PCG
{
	class RandomNoise : public Noise
	{
	public:
		RandomNoise();
		~RandomNoise();

		// overrides
		void getData(DataManager* dataManager) override;
		double generate(double x, double y, double width, double height) override;
		double generate(double x, double y, double z, double width, double height) override;
	};

}

