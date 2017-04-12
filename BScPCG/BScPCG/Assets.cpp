#include "Assets.h"

namespace Assets
{
	AssetManager::AssetManager()
	{
	}
	
	AssetManager::~AssetManager()
	{
	}

	int AssetManager::LoadModel(const std::string& path)
	{
		int result = -1;

		Model model;
		if(model.Load(path))
		{
			model.Upload();

			result = models.size();

			models.push_back(model);
			modelPaths.push_back(path);
		}

		return result;
	}

	void AssetManager::RenderModel(int index, int instances)
	{
		models[index].Render(instances);
	}

	int AssetManager::LoadTexture(const std::string& path)
	{
		int result = -1;

		Texture texture;
		if(texture.Load(path))
		{
			texture.Upload();

			result = textures.size();

			textures.push_back(texture);
			texturePaths.push_back(path);
		}

		return result;
	}

	void AssetManager::BindTexture(int index)
	{
		textures[index].Bind();
	}

	void AssetManager::Unload()
	{
		for(size_t i=0; i<models.size(); i++)
		{
			models[i].Unload();
		}

		for(size_t i=0; i<textures.size(); i++)
		{
			textures[i].Unload();
		}

		models.clear();
		modelPaths.clear();

		textures.clear();
		texturePaths.clear();
	}
}