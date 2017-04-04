#pragma once

#include "Assets.h"
#include "GL\glew.h"

namespace Assets
{
	class Texture : public Asset
	{
	public:
		Texture();
		~Texture();

		bool Load( const std::string& path, AssetManager* assets ) override;
		void Unload() override;
		void Bind() override;

		GLuint GetID() const;
		int GetWidth() const;
		int GetHeight() const;

	private:
		GLuint id;
		int width, height;
	};
}