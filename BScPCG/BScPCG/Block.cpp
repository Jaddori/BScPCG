#include "Block.h"


namespace PCG
{

	Block::Block()
	{
	}


	Block::~Block()
	{
	}

	void Block::getData(DataManager * dataManager)
	{
		dataManager->addData("block", 4.20f);
	}
}
