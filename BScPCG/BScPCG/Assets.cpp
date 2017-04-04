#include "Assets.h"

namespace Assets
{
	// ***************************************
	// Asset
	// ***************************************
	Asset::Asset()
	{
	}

	Asset::~Asset()
	{
	}

	int Asset::GetSize()
	{
		return 0;
	}

	// ***************************************
	// Assets
	// ***************************************
	AssetManager::AssetManager()
	{
	}
	
	AssetManager::~AssetManager()
	{
	}

	void AssetManager::Unload()
	{
	}

	void AssetManager::BindAsset( int index )
	{
	}
}