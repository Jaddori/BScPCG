#pragma once
#include "DataHolder.h"
#include "DataManager.h"
class Building : public DataHolder
{
public:
	Building();
	~Building();
	void getData(DataManager* dataManager) override;
};

