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

		bool load(const std::string& path);
		void unload();
		void upload();
		void render(int instances);

		GLuint getVertexArray() const;
		int getVertexCount() const;
		int getIndexCount() const;

	private:
		Vertex* vertices;
		GLuint* indices;
		GLuint vertexBuffer, indexBuffer;
		GLuint vertexArray;
		int vertexCount, indexCount;
	};
}