#pragma once

#include "BaseIncludes.h"
#include "Model.h"
#include "Texture.h"

namespace Assets
{
	class AssetManager
	{
	public:
		AssetManager();
		~AssetManager();

		int loadModel(const std::string& path);
		void renderModel(int index, int instances);

		int loadTexture(const std::string& path);
		void bindTexture(int index);

		void unload();

	private:
		std::vector<Model> models;
		std::vector<std::string> modelPaths;

		std::vector<Texture> textures;
		std::vector<std::string> texturePaths;
	};
}