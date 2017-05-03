#include "SeedConverter.h"



SeedConverter::SeedConverter()
{
	this->stringSeed = "Swag";
	this->convertSeed();
}

SeedConverter::SeedConverter(std::string seed)
{
	this->stringSeed = seed;
	this->convertSeed();
}


SeedConverter::~SeedConverter()
{
}

unsigned int SeedConverter::getIntegerSeed()
{
	return this->integerSeed;
}

void SeedConverter::setSeed(std::string seed)
{
	this->stringSeed = seed;
	this->convertSeed();
}

void SeedConverter::convertSeed()
{
	
	this->integerSeed = hash(this->stringSeed);
}
