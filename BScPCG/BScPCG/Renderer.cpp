#include "Renderer.h"

namespace Rendering
{
	int compareElements(const void* a, const void* b)
	{
		uint64_t akey = *(uint64_t*)a;
		uint64_t bkey = *(uint64_t*)b;

		return (int)(akey - bkey);
	}

	Renderer::Renderer()
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::load()
	{
		// Load the object shader
		objectShader.load("./assets/shaders/basic.vs", nullptr, "./assets/shaders/basic.fs");

		objectWorldLocation = objectShader.getUniform("WorldMatrices");
		objectProjectionLocation = objectShader.getUniform("ProjectionMatrix");
		objectViewLocation = objectShader.getUniform("ViewMatrix");

		// Set default values for the camera
		perspectiveCamera.setPosition(glm::vec3(0,0,-10));
		perspectiveCamera.updateDirection(0,0);

		// Load the text shader
		textShader.load("./assets/shaders/text.vs", "./assets/shaders/text.gs", "./assets/shaders/text.fs");

		textProjectionLocation = textShader.getUniform("ProjectionMatrix");
		textHeightLocation = textShader.getUniform("Height");

		// Create VAO and VBO for text rendering
		//glCreateVertexArrays(1, &textVAO);
		glGenVertexArrays(1, &textVAO);
		glBindVertexArray(textVAO);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		const Glyph vdata[TEXT_ELEMENT_MAX_LENGTH] = {};

		glGenBuffers(1, &textVBO);
		glBindBuffer(GL_ARRAY_BUFFER, textVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Glyph)*TEXT_ELEMENT_MAX_LENGTH, vdata, GL_STREAM_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Glyph), 0);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Glyph), (void*)(sizeof(glm::vec2)));
		glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(Glyph), (void*)(sizeof(glm::vec2)+sizeof(glm::vec4)));
		glBindVertexArray(0);
	}

	void Renderer::unload()
	{
		// unload shaders
		objectShader.unload();
		textShader.unload();

		// destroy text VAO and VBO
		glDeleteVertexArrays(1, &textVAO);
		glDeleteBuffers(1, &textVBO);
	}

	void Renderer::addElement(int model, int texture, const glm::vec3& position)
	{
		ObjectElement element = { model, texture, position };

		objectElements.add(element);
		worldMatrices.add(glm::mat4());
	}

	void Renderer::addText(Assets::Font* font, int texture, const char* text, const glm::vec2& position)
	{
		TextElement element = { texture, (int)strlen(text), (float)font->getHeight() };
		if(element.textLength > TEXT_ELEMENT_MAX_LENGTH)
		{
			element.textLength = TEXT_ELEMENT_MAX_LENGTH;
		}

		glm::vec2 currentPosition = position;
		for(int i=0; i<element.textLength; i++)
		{
			char letter = text[i];
			if(letter >= Assets::Font::FONT_START && letter <= Assets::Font::FONT_END)
			{
				// set width of glyph
				float width = font->getWidth(letter);
				float height = font->getHeight();
				element.glyphs[i].width = width;

				// set position of glyph
				element.glyphs[i].position = currentPosition;
				currentPosition.x += width;

				// set texture coordinates for glyph
				float textureSize = font->getTextureSize();
				glm::vec2 offset = font->getOffset(letter);
				element.glyphs[i].uv.x = offset.x / textureSize;
				element.glyphs[i].uv.y = (offset.y - height) / textureSize;
				element.glyphs[i].uv.z = (offset.x + width) / textureSize;
				element.glyphs[i].uv.w = offset.y / textureSize;
			}
			else if(letter == '\n') // look for newlines
			{
				currentPosition.x = position.x;
				currentPosition.y += font->getHeight();
			}
		}

		textElements.add(element);
	}

	void Renderer::render( Assets::AssetManager* assets )
	{
		// sort elements
		std::qsort(objectElements.getData(), objectElements.getSize(), sizeof(ObjectElement), compareElements);

		// create world matrices from positions
		const glm::mat4 IDENT;
		for(int i=0; i<objectElements.getSize(); i++)
		{
			worldMatrices[i] = glm::translate(IDENT, objectElements[i].position);
		}

		// update uniforms
		objectShader.bind();
		objectShader.setMat4(objectProjectionLocation, perspectiveCamera.getProjectionMatrix());
		objectShader.setMat4(objectViewLocation, perspectiveCamera.getViewMatrix());
		
		// render all elements
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glDisable(GL_BLEND);

		int first = 0;
		while(first < objectElements.getSize())
		{
			int last = first;
			int curModel = objectElements[first].model;
			int curTexture = objectElements[first].texture;

			for(int i=first+1; i<objectElements.getSize() && last-first+1 < MAX_INSTANCES_PER_DRAW; i++, last++)
			{
				if(objectElements[i].model != curModel || objectElements[i].texture != curTexture)
				{
					break;
				}
			}

			int instances = last-first+1;
			objectShader.setMat4v(objectWorldLocation, &worldMatrices[first], instances);
			assets->bindTexture(curTexture);
			assets->renderModel(curModel, instances);

			first = last+1;
		}

		// update uniforms
		textShader.bind();
		textShader.setMat4(textProjectionLocation, orthographicCamera.getProjectionMatrix());

		// render all text
		glDisable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glBindVertexArray(textVAO);
		for(int i=0; i<textElements.getSize(); i++)
		{
			TextElement& element = textElements[i];

			assets->bindTexture(element.texture);

			glUniform1f(textHeightLocation, element.height);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Glyph)*element.textLength, element.glyphs);
			glDrawArrays(GL_POINTS, 0, element.textLength);
		}
		glBindVertexArray(0);

		// clear lists
		objectElements.clear();
		worldMatrices.clear();
		textElements.clear();
	}

	Shader* Renderer::getObjectShader()
	{
		return &objectShader;
	}

	Shader* Renderer::getTextShader()
	{
		return &textShader;
	}

	Camera* Renderer::getPerspectiveCamera()
	{
		return &perspectiveCamera;
	}

	Camera* Renderer::getOrthographicCamera()
	{
		return &orthographicCamera;
	}
}
