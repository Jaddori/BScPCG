#include "Texture.h"

namespace Assets
{
	Texture::Texture()
	{
	}

	Texture::~Texture()
	{
	}

	bool Texture::Load( const std::string& path, AssetManager* assets )
	{
		return false;
	}

	void Texture::Unload()
	{
	}

	void Texture::Bind()
	{
	}

	GLuint Texture::GetID() const
	{
		return 0;
	}

	int Texture::GetWidth() const
	{
		return 0;
	}

	int Texture::GetHeight() const
	{
		return 0;
	}
}