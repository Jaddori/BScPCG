#include "Shader.h"

namespace Rendering
{
	Shader::Shader()
	{
	}

	Shader::~Shader()
	{
	}

	bool Shader::Load( const char* vertex, const char* geometry, const char* fragment )
	{
		return false;
	}

	void Shader::Unload()
	{
	}

	GLuint Shader::GetUniform( const std::string& name )
	{
		return 0;
	}

	void Shader::Bind()
	{
	}

	GLuint Shader::ReadFile( const char* path, GLenum shaderType )
	{
		return 0;
	}

	bool Shader::CompileShader( GLuint shader )
	{
		return false;
	}

	bool Shader::LinkProgram()
	{
		return false;
	}
}