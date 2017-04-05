#pragma once

#include <string>
#include <vector>
#include <stdint.h>
#include <assert.h>
#include "Model.h"
#include "Texture.h"

namespace Assets
{
	class AssetManager
	{
	public:
		AssetManager();
		~AssetManager();

		int LoadModel(const std::string& path);
		void RenderModel(int index, int instances);

		int LoadTexture(const std::string& path);
		void BindTexture(int index);

		void Unload();

	private:
		std::vector<Model> models;
		std::vector<std::string> modelPaths;

		std::vector<Texture> textures;
		std::vector<std::string> texturePaths;
	};
}