#pragma once

#include "glm\glm.hpp"
#include "GL\glew.h"
#include <map>
#include <string>

namespace Rendering
{
	class Shader
	{
	public:
		Shader();
		~Shader();

		bool Load( const char* vertex, const char* geometry, const char* fragment );
		void Unload();
		GLuint GetUniform( const std::string& name );
		void Bind();

	private:
		GLuint ReadFile( const char* path, GLenum shaderType );
		bool CompileShader( GLuint shader );
		bool LinkProgram();

		GLuint shaderProgram;
	};
}