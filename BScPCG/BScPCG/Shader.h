#pragma once

#include "BaseIncludes.h"

namespace Rendering
{
	class Shader
	{
	public:
		Shader();
		~Shader();

		bool Load(const char* vertex, const char* geometry, const char* fragment);
		void Unload();
		GLuint GetUniform(const std::string& name);
		void Bind();

		void SetInt(GLuint location, int value);
		void SetFloat(GLuint location, float value);
		void SetVec2(GLuint location, const glm::vec2& value);
		void SetVec3(GLuint location, const glm::vec3& value);
		void SetVec4(GLuint location, const glm::vec4& value);
		void SetMat4(GLuint location, const glm::mat4& value);

	private:
		GLuint ReadFile(const char* path, GLenum shaderType);
		bool CompileShader(GLuint shader);
		bool LinkProgram();

		GLuint shaderProgram;
	};
}