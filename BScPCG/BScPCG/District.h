#pragma once
#include "DataHolder.h"
#include "DataManager.h"
#include "Noise.h"
#include "glm\glm.hpp"
#include "glm\ext.hpp"
#include "glm\gtx\rotate_vector.hpp"
namespace PCG
{
	struct DistrictStruct
	{
		int ID, minHeight, maxHeight;
		float blockSize;

		DistrictStruct()
		{
			ID = 0;
			minHeight = 1;
			maxHeight = 1;
			blockSize = 0.5f;
		}
	};
	class District : public DataHolder
	{
	public:
		District();
		District(Noise* noise);
		~District();
		void getData(DataManager* dataManager) override;
		DistrictStruct getDistrictValue(float x, float y, float width, float height);
		void setDistrict(float width, float height);
		void setNoiseGenerator(Noise* noise);
		void calculateMap(Utilities::Array<Utilities::Array<int>>& map);
		void generate(Utilities::Array<Utilities::Array<int>>& map, float width, float height);

	private:
		Noise* noise;
		const int DISTRICT_AMOUNT = 3;
		Utilities::Array<glm::vec2> positions;
		//DistrictStruct* first, *second, *third;
		const float PROCENTUAL_BORDER_EFFECT = 0.2;
		double width, height;

		double vec2SquareDistance(glm::vec2 first, glm::vec2 second);
		inline int closestDistrict(int x, int y);
		void findBorder(Utilities::Array<Utilities::Array<int>>& map, Utilities::Array<glm::vec2>& borders);
		void changeBorder(Utilities::Array<Utilities::Array<int>>& map, Utilities::Array<glm::vec2>& borders, int nodeChangeRange);
	};
}
