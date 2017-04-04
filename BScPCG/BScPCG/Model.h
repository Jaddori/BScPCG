#pragma once

#include "Assets.h"
#include "GL\glew.h"
#include "glm\glm.hpp"

namespace Assets
{
	struct Vertex
	{
		glm::vec3 position;
		glm::vec2 uv;
		glm::vec3 normal;
		glm::vec3 tangent;
		glm::vec3 bitangent;
	};

	class Model : public Asset
	{
	public:
		Model();
		~Model();

		bool Load(const std::string& path) override;
		void Unload() override;
		void Upload() override;
		void Bind() override;

		GLuint GetVertexArray() const;
		int GetVertexCount() const;
		int GetIndexCount() const;

	private:
		Vertex* vertices;
		GLuint* indices;
		GLuint vertexBuffer, indexBuffer;
		GLuint vertexArray;
		int vertexCount, indexCount;
	};
}