#pragma once

#include "BaseIncludes.h"
#include "Assets.h"
#include "Shader.h"
#include "Camera.h"
#include "Array.h"

namespace Rendering
{
	struct ObjectElement
	{
		int32_t model;
		int32_t texture;
		glm::vec3 position;
	};

#define TEXT_ELEMENT_MAX_LENGTH 128
	struct TextElement
	{
		int font;
		int texture;
		glm::vec2 position;
		char text[TEXT_ELEMENT_MAX_LENGTH];
	};

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void load();

		void addElement(int model, int texture, const glm::vec3& position);
		void addText(int font, int texture, const char* text, const glm::vec2& position);
		void render(Assets::AssetManager* assets);

		Shader* getObjectShader();
		Shader* getTextShader();

		Camera* getPerspectiveCamera();
		Camera* getOrthographicCamera();

	private:
		static const int MAX_INSTANCES_PER_DRAW = 100;

		// Object variables
		Shader objectShader;
		Camera perspectiveCamera;

		Utilities::Array<ObjectElement> objectElements;
		Utilities::Array<glm::mat4> worldMatrices;

		GLuint objectWorldLocation;
		GLuint objectProjectionLocation;
		GLuint objectViewLocation;

		// Text variables
		Shader textShader;
		Camera orthographicCamera;

		Utilities::Array<TextElement> textElements;

		GLuint textWorldLocation;
		GLuint textProjectionLocation;
	};
}
