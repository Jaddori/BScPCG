#include "Renderer.h"

namespace Rendering
{
	int CompareElements(const void* a, const void* b)
	{
		uint64_t akey = *(uint64_t*)a;
		uint16_t bkey = *(uint64_t*)b;

		return (int)(akey - bkey);
	}

	Renderer::Renderer()
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::Load()
	{
		shader.Load("./assets/shaders/basic.vs", nullptr, "./assets/shaders/basic.fs");

		worldMatrixLocation = shader.GetUniform("WorldMatrices");
		projectionMatrixLocation = shader.GetUniform("ProjectionMatrix");
		viewMatrixLocation = shader.GetUniform("ViewMatrix");

		camera.SetPosition(glm::vec3(0,0,-10));
		camera.UpdateDirection(0,0);
	}

	void Renderer::AddElement(int model, int texture, const glm::vec3& position)
	{
		RenderElement element = { model, texture, position };
		elements.push_back(element);
		worldMatrices.push_back(glm::mat4());
	}

	void Renderer::Render( Assets::AssetManager* assets )
	{
		// sort elements
		std::qsort(elements.data(), elements.size(), sizeof(RenderElement), CompareElements);

		// create world matrices from positions
		const glm::mat4 IDENT;
		for(size_t i=0; i<elements.size(); i++)
		{
			worldMatrices[i] = glm::translate(IDENT, elements[i].position);
		}

		// update uniforms
		shader.Bind();
		shader.SetMat4(projectionMatrixLocation, camera.GetProjectionMatrix());
		shader.SetMat4(viewMatrixLocation, camera.GetViewMatrix());
		
		// render all elements
		int first = 0;
		while(first < elements.size())
		{
			int last = first;
			int curModel = elements[first].model;
			int curTexture = elements[first].texture;

			for(size_t i=first+1; i<elements.size() && last-first+1 < 100; i++, last++)
			{
				if(elements[i].model != curModel || elements[i].texture != curTexture)
				{
					break;
				}
			}

			int instances = last-first+1;
			shader.SetMat4v(worldMatrixLocation, &worldMatrices[first], instances);
			assets->BindTexture(curTexture);
			assets->RenderModel(curModel, instances);

			first = last+1;
		}

		// clear lists
		elements.clear();
		worldMatrices.clear();
	}

	Shader* Renderer::GetShader()
	{
		return &shader;
	}

	Camera* Renderer::GetCamera()
	{
		return &camera;
	}
}
