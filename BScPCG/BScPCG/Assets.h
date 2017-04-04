#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <assert.h>

namespace Assets
{
	class AssetManager;
	class Asset
	{
	public:
		Asset();
		~Asset();

		virtual bool Load(const std::string& path) = 0;
		virtual void Unload() = 0;
		virtual void Upload() = 0;
		virtual void Bind() = 0;
		int GetSize();

	protected:
		int size;
	};

	class AssetManager
	{
	public:
		AssetManager();
		~AssetManager();

		template<typename T>
		int Load(const std::string& path)
		{
			int result = -1;
			for(int i=0; i<paths.size() && result < 0; i++)
			{
				if(paths[i] == path)
				{
					result = i;
				}
			}

			if(result < 0)
			{
				T* asset = new T();
				if(asset->Load(path))
				{
					result = assets.size();

					assets.push_back(asset);
					paths.push_back(path);
				}
				else
					delete asset;
			}

			return result;
		}

		void Unload();
		void BindAsset(int index);

	private:
		std::vector<Asset*> assets;
		std::vector<std::string> paths;
	};
}