#pragma once
#include <string>
#include <functional>
class SeedConverter
{
public:
	SeedConverter();
	SeedConverter(std::string seed);
	~SeedConverter();
	unsigned int getIntegerSeed();
	void setSeed(std::string seed);
private:
	unsigned int integerSeed;
	std::string stringSeed;
	std::hash<std::string> hash;

	void convertSeed();
};

