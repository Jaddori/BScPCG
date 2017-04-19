#include "Assets.h"

namespace Assets
{
	AssetManager::AssetManager()
	{
	}
	
	AssetManager::~AssetManager()
	{
	}

	int AssetManager::loadModel(const std::string& path)
	{
		int result = -1;

		Model model;
		if(model.load(path))
		{
			model.upload();

			result = models.size();

			models.push_back(model);
			modelPaths.push_back(path);
		}

		return result;
	}

	void AssetManager::renderModel(int index, int instances)
	{
		models[index].render(instances);
	}

	int AssetManager::loadTexture(const std::string& path)
	{
		int result = -1;

		Texture texture;
		if(texture.load(path))
		{
			texture.upload();

			result = textures.size();

			textures.push_back(texture);
			texturePaths.push_back(path);
		}

		return result;
	}

	void AssetManager::bindTexture(int index)
	{
		textures[index].bind();
	}

	void AssetManager::unload()
	{
		for(size_t i=0; i<models.size(); i++)
		{
			models[i].unload();
		}

		for(size_t i=0; i<textures.size(); i++)
		{
			textures[i].unload();
		}

		models.clear();
		modelPaths.clear();

		textures.clear();
		texturePaths.clear();
	}
}