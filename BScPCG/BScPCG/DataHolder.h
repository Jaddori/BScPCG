#pragma once
#include "Array.h"
namespace PCG
{
	class DataManager;

	class DataHolder
	{
	public:
		DataHolder();
		virtual ~DataHolder();
		virtual void getData(DataManager* dataManager) = 0;
	};

}