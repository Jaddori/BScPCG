#pragma once

#include "Assets.h"

namespace Assets
{
	class Model : public Asset
	{
	public:
		Model();
		~Model();

		bool Load( const std::string& path, AssetManager* assets ) override;
		void Unload() override;
		void Bind() override;

		unsigned int GetVertexArray() const;
		int GetNumIndices() const;

	private:
		unsigned int vertexBuffer, indexBuffer;
		unsigned int vertexArray;
		int numIndices;
	};
}