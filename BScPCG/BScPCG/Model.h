#pragma once

#include "BaseIncludes.h"

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

	class Model
	{
	public:
		Model();
		~Model();

		bool Load(const std::string& path);
		void Unload();
		void Upload();
		void Render(int instances);

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