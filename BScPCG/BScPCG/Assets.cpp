#include "Assets.h"
using namespace Utilities;
using namespace std;

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
		int result = find(modelPaths, path);

		if(result < 0)
		{
			Model model;
			if(model.load(path))
			{
				model.upload();

				result = models.getSize();

				models.add(model);
				modelPaths.add(path);
			}
		}

		return result;
	}

	void AssetManager::renderModel(int index, int instances)
	{
		models[index].render(instances);
	}

	int AssetManager::loadTexture(const std::string& path)
	{
		int result = find(texturePaths, path);

		if(result < 0)
		{
			Texture texture;
			if(texture.load(path))
			{
				texture.upload();

				result = textures.getSize();

				textures.add(texture);
				texturePaths.add(path);
			}
		}

		return result;
	}

	void AssetManager::bindTexture(int index)
	{
		textures[index].bind();
	}

	Font* AssetManager::loadFont(const std::string& path)
	{
		int result = find(fontPaths, path);

		if(result < 0)
		{
			Font font;
			if(font.load(path))
			{
				result = fonts.getSize();

				fonts.add(font);
				fontPaths.add(path);
			}
		}

		return &fonts[result];
	}

	void AssetManager::unload()
	{
		for(size_t i=0; i<models.getSize(); i++)
		{
			models[i].unload();
		}

		for(size_t i=0; i<textures.getSize(); i++)
		{
			textures[i].unload();
		}

		for(int i=0; i<fonts.getSize(); i++)
		{
			fonts[i].unload();
		}

		models.clear();
		modelPaths.clear();

		textures.clear();
		texturePaths.clear();

		fonts.clear();
		fontPaths.clear();
	}

	int AssetManager::find(const Array<string>& paths, const string& path)
	{
		int result = -1;
		for(int i=0; i<paths.getSize() && result < 0; i++)
		{
			if(paths[i] == path)
			{
				result = i;
			}
		}

		return result;
	}
}