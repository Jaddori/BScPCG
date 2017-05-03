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
	};

}

