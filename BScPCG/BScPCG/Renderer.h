#pragma once

#include "BaseIncludes.h"
#include "Assets.h"
#include "Shader.h"
#include "Camera.h"

namespace Rendering
{
	struct ObjectElement
	{
		int32_t model;
		int32_t texture;
		glm::vec3 position;
	};

	struct ObjectInstance
	{
		int model;
		int texture;
		int instances;
	};

#define TEXT_ELEMENT_MAX_LENGTH 128
	struct Glyph
	{
		glm::vec2 position;
		glm::vec4 uv;
		float width;
	};

	struct TextElement
	{
		int texture;
		int textLength;
		float height;
		Glyph glyphs[TEXT_ELEMENT_MAX_LENGTH];
	};

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void load();
		void unload();

		void begin();
		void end();

		void addElement(int model, int texture, const glm::vec3& position);
		void addText(Assets::Font* font, int texture, const char* text, const glm::vec2& position);
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
		Utilities::Array<ObjectInstance> objectInstances;
		Utilities::Array<glm::mat4> worldMatrices;

		GLuint objectWorldLocation;
		GLuint objectProjectionLocation;
		GLuint objectViewLocation;

		// Text variables
		Shader textShader;
		Camera orthographicCamera;

		Utilities::Array<TextElement> textElements;

		GLuint textVAO, textVBO;
		GLuint textProjectionLocation;
		GLuint textHeightLocation;
	};
}
