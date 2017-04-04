#pragma once

#include "Assets.h"
#include "GL\glew.h"

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

		GLuint GetVertexArray() const;
		int GetNumIndices() const;

	private:
		GLuint vertexBuffer, indexBuffer;
		GLuint vertexArray;
		int numIndices;
	};
}