#pragma once
#include "DataHolder.h"
#include "DataManager.h"
namespace PCG
{
	class Block : public DataHolder
	{
	public:
		Block();
		~Block();
		void getData(DataManager* dataManager) override;
	};
}


