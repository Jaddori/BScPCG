#pragma once

#include "Assets.h"

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

		unsigned int GetID() const;
		int GetWidth() const;
		int GetHeight() const;

	private:
		unsigned int id;
		int width, height;
	};
}