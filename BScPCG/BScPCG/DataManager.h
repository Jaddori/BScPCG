#pragma once
#include "DataHolder.h"
#include <iostream>
#include <map>
namespace PCG
{
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
		float getData(std::string name);

	private:
		Utilities::Array<DataHolder*>* dataHolder;
		std::map<std::string, float>* data;
	};

}