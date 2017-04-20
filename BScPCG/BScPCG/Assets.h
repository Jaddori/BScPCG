#pragma once

#include "BaseIncludes.h"
#include "Model.h"
#include "Texture.h"
#include "Font.h"

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

		Font* loadFont(const std::string& path);

		void unload();

	private:
		int find(const Utilities::Array<std::string>& paths, const std::string& path);

		Utilities::Array<Model> models;
		Utilities::Array<std::string> modelPaths;

		Utilities::Array<Texture> textures;
		Utilities::Array<std::string> texturePaths;

		Utilities::Array<Font> fonts;
		Utilities::Array<std::string> fontPaths;
	};
}