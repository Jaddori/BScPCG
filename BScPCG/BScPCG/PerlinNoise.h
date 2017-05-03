#pragma once
#include "DataHolder.h"
#include "DataManager.h"
namespace PCG
{
	class PerlinNoise : public DataHolder
	{
	public:
		PerlinNoise();
		~PerlinNoise();
		void getData(DataManager* dataManager) override;
		static unsigned int counter;
	};
}

