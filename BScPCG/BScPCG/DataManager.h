#pragma once
#include "DataHolder.h"
#include <iostream>
#include <map>

class DataManager
{
public:
	DataManager();
	~DataManager();
	void addDataHolder(DataHolder* dataHolder);
	void collectData();
	void showData();
	void addData(std::string name, float value);
	void incrementData(std::string name, float value);
	void test(int t);

private:
	Utilities::Array<DataHolder*>* dataHolder;
	std::map<std::string, float>* data;
};

