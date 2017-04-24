#pragma once
#include "DataHolder.h"
#include"DataManager.h"

class District : public DataHolder
{
public:
	District();
	~District();
	void getData(DataManager* dataManager) override;

private:

};

