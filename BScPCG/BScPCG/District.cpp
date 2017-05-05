#include "District.h"



namespace PCG
{
	District::District()
	{
		this->noise = nullptr;
		for (int i = 0; i < DISTRICT_AMOUNT; i++)
		{
			this->positions.add(glm::vec2());
		}
	}

	District::District(Noise * noise)
	{
		this->noise = noise;
		for (int i = 0; i < DISTRICT_AMOUNT; i++)
		{
			this->positions.add(glm::vec2());
		}
	}


	District::~District()
	{
	}

	void District::getData(DataManager * dataManager)
	{
		dataManager->addData("District", 1.0f);
	}
	DistrictStruct District::getDistrictValue(float x, float y, float width, float height)
	{
		return DistrictStruct();
	}
	void District::setDistrict(float width, float height)
	{
		// gives districts initial position 
		this->width = width;
		this->height = height;

		double noise = 20 * this->noise->generate(1.134, 1.22, 1,1); // Some noise with nice spread
		this->positions[0].x = (noise - floor(noise)) * width;

		noise = 10 * this->noise->generate(1.476, 1.687, 0.88, 1);
		this->positions[0].y = (noise - floor(noise)) * height;

		noise = 20 * this->noise->generate(6.745, 4.9345, 0.77, 1);
		this->positions[1].x = (noise - floor(noise)) * width;

		noise = 10 * this->noise->generate(2.975, 2.626, 0.6, 1);
		this->positions[1].y = (noise - floor(noise)) * height;
													 
		noise = 20 * this->noise->generate(3.153, 3.754, 0.55, 1);
		this->positions[2].x = (noise - floor(noise)) * width;
													
		noise = 10 * this->noise->generate(4.242, 7.965, 0.44, 1);
		this->positions[2].y = (noise - floor(noise)) * height;

		std::cout << floor(positions[0].x) << "," << floor(positions[0].y) << std::endl;
		std::cout << floor(positions[1].x) << "," << floor(positions[1].y) << std::endl;
		std::cout << floor(positions[2].x) << "," << floor(positions[2].y) << std::endl;
						
	}
	void District::setNoiseGenerator(Noise * noise)
	{
		this->noise = noise;
	}
	void District::calculateMap(Utilities::Array<Utilities::Array<int>>& map)
	{
		const int WIDTH = map.getSize();

		for (int x = 0; x < WIDTH; x++) // closest district wins
		{
			const int HEIGHT = map[x].getSize();
			for (int y = 0; y < HEIGHT; y++)
			{
				map[x][y] = this->closestDistrict(x, y);
			}
		}

		//sprinkle some perlin randomness in there
		Utilities::Array<glm::vec2> borderCoordinates;
		this->findBorder(map,borderCoordinates); // get border to change

		const int MIN_EFFECT_AMOUNT = 2; // calculate how many nodes to effect
		int nodeEffectAmount = floor(width * PROCENTUAL_BORDER_EFFECT);
		if (nodeEffectAmount < MIN_EFFECT_AMOUNT)
			nodeEffectAmount = MIN_EFFECT_AMOUNT;

		this->changeBorder(map,borderCoordinates,nodeEffectAmount);

	}

	double District::vec2SquareDistance(glm::vec2 first, glm::vec2 second)
	{
		double xDistance = (first.x - second.x);
		double yDistance = (first.y - second.y);
		return (xDistance * xDistance) + (yDistance * yDistance);
	}
	inline int District::closestDistrict(int x, int y)
	{
		//return closest district to pos
		glm::vec2 pos(x,y);
		int closestDistric = -25;
		double firstDistance = vec2SquareDistance(positions[0],pos);
		double secondDistance = vec2SquareDistance(positions[1],pos);
		double thirdDistance = vec2SquareDistance(positions[2], pos);

		if (firstDistance < secondDistance && firstDistance < thirdDistance)
			closestDistric =  0;
		else if (secondDistance < firstDistance && secondDistance < thirdDistance)
			closestDistric = 1;
		else
			closestDistric = 2;

		return closestDistric;
	}
	void District::findBorder(Utilities::Array<Utilities::Array<int>>& map, Utilities::Array<glm::vec2>& borders)
	{
		const int WIDTH = map.getSize();
		const int HEIGHT = map[0].getSize();
		int previous = map[0][0];
		for (int y = 0; y < HEIGHT; y++)
		{
			previous = map[0][y];
			for (int x = 0; x < WIDTH; x++)
			{
				if (previous != map[x][y]) // we found border
				{
					previous = map[x][y]; // Change previous
					borders.add(glm::vec2(x,y)); // change position
				}
			}
		}
	}
	void District::changeBorder(Utilities::Array<Utilities::Array<int>>& map, Utilities::Array<glm::vec2>& borders, int nodeChangeRange)
	{
		int x, y, firstDistrict, secondDistrict;
		int minRangePos, maxRangePos;
		double noise;
		int halfChangeRange = nodeChangeRange / 2;
		// hitta range som ska ändras
		for (int i = 0; i < borders.getSize(); i++)
		{
			x = borders.at(i).x;
			y = borders.at(i).y;
			firstDistrict = map[x][y];
			secondDistrict = map[x - 1][y]; // this should never go outside array borders

			minRangePos = x - halfChangeRange; // calculate what nodes to change
			maxRangePos = x + halfChangeRange;
			if (minRangePos < 0)
				minRangePos = 0;
			if (maxRangePos >= width)
				maxRangePos = width - 1;
				

	

			for (int x2 = minRangePos; x2 <= maxRangePos; x2++) // loop through nodes to be changed
			{
				noise = 20 * this->noise->generate(1.134 * x2, 1.22 * y, 1, 1);
				noise = (noise - floor(noise));


				if (noise > 0.5)
					map[x2][y] = firstDistrict;
				else
					map[x2][y] = secondDistrict;
			}
		}
	}
}