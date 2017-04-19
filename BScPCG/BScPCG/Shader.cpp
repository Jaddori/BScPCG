#include "Shader.h"

namespace Rendering
{
	Shader::Shader()
		: shaderProgram(0)
	{
	}

	Shader::~Shader()
	{
		unload();
	}

	bool Shader::load(const char* vertex, const char* geometry, const char* fragment)
	{
		assert( vertex || geometry || fragment );

		bool result = false;

		shaderProgram = glCreateProgram();

		GLuint vertexShader = 0;
		GLuint geometryShader = 0;
		GLuint fragmentShader = 0;

		if(vertex)
		{
			vertexShader = readFile(vertex, GL_VERTEX_SHADER);
			assert(vertexShader > 0);
		}
		if(geometry)
		{
			geometryShader = readFile(geometry, GL_GEOMETRY_SHADER);
			assert(geometryShader > 0);
		}
		if(fragment)
		{
			fragmentShader = readFile(fragment, GL_FRAGMENT_SHADER);
			assert(fragmentShader > 0 );
		}

		if(vertexShader > 0)
			glAttachShader(shaderProgram, vertexShader);
		if(geometryShader > 0)
			glAttachShader(shaderProgram, geometryShader);
		if(fragmentShader > 0)
			glAttachShader(shaderProgram, fragmentShader);

		if(!linkProgram())
		{
			glDeleteProgram(shaderProgram);
			shaderProgram = 0;
		}
		else
		{
			result = true;
		}

		if(vertexShader > 0)
			glDeleteShader(vertexShader);
		if(geometryShader > 0)
			glDeleteShader(geometryShader);
		if(fragmentShader > 0)
			glDeleteShader(fragmentShader);

		return result;
	}

	void Shader::unload()
	{
		if(shaderProgram)
		{
			glDeleteProgram(shaderProgram);
		}

		shaderProgram = 0;
	}

	GLuint Shader::getUniform( const std::string& name )
	{
		return glGetUniformLocation(shaderProgram, name.c_str());
	}

	void Shader::bind()
	{
		glUseProgram(shaderProgram);
	}

	GLuint Shader::readFile(const char* path, GLenum shaderType)
	{
		assert(shaderType == GL_VERTEX_SHADER || shaderType == GL_GEOMETRY_SHADER || shaderType == GL_FRAGMENT_SHADER);
		assert(path);

		GLuint result = 0;

		FILE* file = fopen(path, "rb");
		if(file)
		{
			fseek(file, 0, SEEK_END);
			int len = ftell(file);
			fseek(file, 0, SEEK_SET);

			char* text = new char[len+1];
			fread(text, sizeof(char), len, file);
			text[len] = 0;

			fclose(file);

			result = glCreateShader( shaderType );
			glShaderSource(result, 1, &text, NULL);

			delete[] text;
			
			if(!compileShader(result))
			{
				glDeleteShader(result);
				result = 0;
			}
		}

		return result;
	}

	bool Shader::compileShader(GLuint shader)
	{
		bool result = true;

		glCompileShader(shader);
		GLint success = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if(success == GL_FALSE)
		{
			const int MAX_LENGTH = 1024;

			char msg[MAX_LENGTH] = {};
			int len = MAX_LENGTH;
			glGetShaderInfoLog(shader, MAX_LENGTH, &len, msg);

			printf("%s\n", msg);
			result = false;
		}

		return result;
	}

	bool Shader::linkProgram()
	{
		bool result = true;

		glLinkProgram(shaderProgram);
		GLint success = 0;
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if(success == GL_FALSE)
		{
			const int MAX_LENGTH = 1024;

			char msg[MAX_LENGTH] = {};
			int len = MAX_LENGTH;
			glGetProgramInfoLog(shaderProgram, MAX_LENGTH, &len, msg);

			printf("%s\n", msg);
			result = false;
		}

		return result;
	}

	void Shader::setInt(GLuint location, int value)
	{
		glUniform1i(location, value);
	}

	void Shader::setFloat(GLuint location, float value)
	{
		glUniform1f(location, value);
	}

	void Shader::setVec2(GLuint location, const glm::vec2& value)
	{
		glUniform2f(location, value.x, value.y);
	}

	void Shader::setVec3(GLuint location, const glm::vec3& value)
	{
		glUniform3f(location, value.x, value.y, value.z);
	}

	void Shader::setVec4(GLuint location, const glm::vec4& value)
	{
		glUniform4f(location, value.x, value.y, value.z, value.w);
	}

	void Shader::setMat4(GLuint location, const glm::mat4& value)
	{
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}
	
	void Shader::setMat4v(GLuint location, const glm::mat4* value, int n)
	{
		glUniformMatrix4fv(location, n, GL_FALSE, glm::value_ptr(*value));
	}
}
