#pragma once

#include "BaseIncludes.h"

namespace Rendering
{
	class Shader
	{
	public:
		Shader();
		~Shader();

		bool load(const char* vertex, const char* geometry, const char* fragment);
		void unload();
		GLuint getUniform(const std::string& name);
		void bind();

		void setInt(GLuint location, int value);
		void setFloat(GLuint location, float value);
		void setVec2(GLuint location, const glm::vec2& value);
		void setVec3(GLuint location, const glm::vec3& value);
		void setVec4(GLuint location, const glm::vec4& value);
		void setMat4(GLuint location, const glm::mat4& value);
		void setMat4v(GLuint location, const glm::mat4* value, int n);

	private:
		GLuint readFile(const char* path, GLenum shaderType);
		bool compileShader(GLuint shader);
		bool linkProgram();

		GLuint shaderProgram;
	};
}
