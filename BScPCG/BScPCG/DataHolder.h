#pragma once
#include "Array.h"

class DataManager;

class DataHolder
{
public:
	DataHolder();
	virtual ~DataHolder();
	virtual void getData(DataManager* dataManager) = 0;
};

