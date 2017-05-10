#pragma once
#include "DataHolder.h"
namespace PCG
{
	class Noise :
		public DataHolder
	{
	public:
		Noise();
		~Noise();

		virtual double generate(double x, double y, double width, double height) = 0;
		virtual double generate(double x, double y, double z, double width, double height) = 0;
		virtual void seed(unsigned int seed) = 0;
	};

}

