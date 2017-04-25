#include "DataManager.h"

namespace PCG
{

	DataManager::DataManager()
	{
		this->dataHolder = new Utilities::Array<DataHolder*>();
		this->data = new std::map<std::string, float>();
	}


	DataManager::~DataManager()
	{
		delete this->data;
		delete this->dataHolder;
	}

	void DataManager::addDataHolder(DataHolder * dataHolder)
	{
		this->dataHolder->add(dataHolder);
	}

	void DataManager::collectData()
	{
		for (int i = 0; i < this->dataHolder->getSize(); i++)
		{
			dataHolder->at(i)->getData(this);
		}
	}

	void DataManager::showData()
	{
		std::map<std::string, float>::iterator iterator = this->data->begin();

		while (iterator != this->data->end())
		{
			std::cout << iterator->first.c_str() << " :: " << iterator->second << std::endl;
			iterator++;
		}

	}

	void DataManager::addData(std::string name, float value)
	{
		bool completed = this->data->insert(std::make_pair(name, value)).second;
		if (!completed) // if data already exists, replace the value
		{
			this->data->operator[](name) = value;
		}
	}

	void DataManager::incrementData(std::string name, float value)
	{
		bool completed = this->data->insert(std::make_pair(name, value)).second;
		if (!completed) // if data already exists, increment the value
		{
			this->data->operator[](name) += value;
		}
	}
	float DataManager::getData(std::string name)
	{
		using namespace std;
		map<string, float>::iterator found = this->data->find(name);
		float dataValue = 0;

		if (found != this->data->end()) // if found
		{
			dataValue = found->second;
		}
		
		return dataValue;
	}
}