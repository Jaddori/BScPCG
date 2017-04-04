#pragma once

#include <string>
#include <vector>

namespace Assets
{
	class AssetManager;
	class Asset
	{
	public:
		Asset();
		~Asset();

		virtual bool Load( const std::string& path, AssetManager* assets ) = 0;
		virtual void Unload() = 0;
		virtual void Bind() = 0;
		int GetSize();

	private:
		int size;
	};

	class AssetManager
	{
	public:
		AssetManager();
		~AssetManager();

		template<typename T>
		int Load( const std::string& path )
		{
			return 0;
		}

		void Unload();
		void BindAsset( int index );

	private:
		std::vector<Asset*> assets;
		std::vector<std::string> paths;
	};
}