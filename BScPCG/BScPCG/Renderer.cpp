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
		shader.load("./assets/shaders/basic.vs", nullptr, "./assets/shaders/basic.fs");

		worldMatrixLocation = shader.getUniform("WorldMatrices");
		projectionMatrixLocation = shader.getUniform("ProjectionMatrix");
		viewMatrixLocation = shader.getUniform("ViewMatrix");

		camera.setPosition(glm::vec3(0,0,-10));
		camera.updateDirection(0,0);
	}

	void Renderer::addElement(int model, int texture, const glm::vec3& position)
	{
		RenderElement element = { model, texture, position };
		//elements.push_back(element);
		//worldMatrices.push_back(glm::mat4());

		elements.add(element);
		worldMatrices.add(glm::mat4());
	}

	void Renderer::render( Assets::AssetManager* assets )
	{
		// sort elements
		//std::qsort(elements.data(), elements.size(), sizeof(RenderElement), compareElements);
		std::qsort(elements.getData(), elements.getSize(), sizeof(RenderElement), compareElements);

		// create world matrices from positions
		const glm::mat4 IDENT;
		//for(size_t i=0; i<elements.size(); i++)
		for(int i=0; i<elements.getSize(); i++)
		{
			worldMatrices[i] = glm::translate(IDENT, elements[i].position);
		}

		// update uniforms
		shader.bind();
		shader.setMat4(projectionMatrixLocation, camera.getProjectionMatrix());
		shader.setMat4(viewMatrixLocation, camera.getViewMatrix());
		
		// render all elements
		int first = 0;
		//while(first < elements.size())
		while(first < elements.getSize())
		{
			int last = first;
			int curModel = elements[first].model;
			int curTexture = elements[first].texture;

			//for(size_t i=first+1; i<elements.size() && last-first+1 < 100; i++, last++)
			for(int i=first+1; i<elements.getSize() && last-first+1 < MAX_INSTANCES_PER_DRAW; i++, last++)
			{
				if(elements[i].model != curModel || elements[i].texture != curTexture)
				{
					break;
				}
			}

			int instances = last-first+1;
			shader.setMat4v(worldMatrixLocation, &worldMatrices[first], instances);
			assets->bindTexture(curTexture);
			assets->renderModel(curModel, instances);

			first = last+1;
		}

		// clear lists
		elements.clear();
		worldMatrices.clear();
	}

	Shader* Renderer::getShader()
	{
		return &shader;
	}

	Camera* Renderer::getCamera()
	{
		return &camera;
	}
}
