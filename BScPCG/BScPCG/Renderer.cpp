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

		// Load the text shader
		textShader.load("./assets/shaders/text.vs", nullptr, "./assets/shaders/text.fs");

		textWorldLocation = textShader.getUniform("WorldMatrix");
		textProjectionLocation = textShader.getUniform("ProjectionMatrix");

		// Set default values for the camera
		perspectiveCamera.setPosition(glm::vec3(0,0,-10));
		perspectiveCamera.updateDirection(0,0);
	}

	void Renderer::addElement(int model, int texture, const glm::vec3& position)
	{
		ObjectElement element = { model, texture, position };

		objectElements.add(element);
		worldMatrices.add(glm::mat4());
	}

	void Renderer::addText(int font, int texture, const char* text, const glm::vec2& position)
	{
		TextElement element = { font, texture, position };
		strcpy(element.text, text);

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
		for(int i=0; i<textElements.getSize(); i++)
		{

		}

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
