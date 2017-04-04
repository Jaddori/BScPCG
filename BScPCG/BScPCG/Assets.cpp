#include "Assets.h"

namespace Assets
{
	// ***************************************
	// Asset
	// ***************************************
	Asset::Asset()
		: size(0)
	{
	}

	Asset::~Asset()
	{
	}

	int Asset::GetSize()
	{
		return size;
	}

	// ***************************************
	// Assets
	// ***************************************
	AssetManager::AssetManager()
	{
	}
	
	AssetManager::~AssetManager()
	{
		Unload();
	}

	void AssetManager::Unload()
	{
		for(int i=0; i<assets.size(); i++)
		{
			assets[i]->Unload();
			delete assets[i];
		}

		assets.clear();
		paths.clear();
	}

	void AssetManager::BindAsset(int index)
	{
		assert(index >= 0 && index < assets.size());

		assets[index]->Bind();
	}
}