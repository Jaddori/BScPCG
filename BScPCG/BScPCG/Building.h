#pragma once
#include "DataHolder.h"
#include "DataManager.h"

namespace PCG
{
	class Building : public DataHolder
	{
	public:
		Building();
		~Building();
		void getData(DataManager* dataManager) override;
	};
}


