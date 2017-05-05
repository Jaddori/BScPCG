#pragma once
#include "DataHolder.h"
#include "DataManager.h"
#include "Noise.h"
#include "BaseIncludes.h"

#define MAIN_ROAD_THRESHOLD 0.35f
#define SMALL_ROAD_THRESHOLD 0.2f

namespace PCG
{
	class Block : public DataHolder
	{
	public:
		Block();
		~Block();

		//void generate(Utilities::Array<Utilities::Array<int>>& map);
		void generate(Utilities::Array2D<int>& map);

		void setNoiseGenerator(Noise* noise);
		void setDimensions(float width, float height);

		void getData(DataManager* dataManager) override;

	private:
		Noise* noise;
		float width;
		float height;
	};
}


