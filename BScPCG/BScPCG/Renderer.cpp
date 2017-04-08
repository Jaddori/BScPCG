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
		viewMatrixLocation = shader.GetUniform("ViewMatrix");
		projectionMatrixLocation = shader.GetUniform("ProjectionMatrix");

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
		/*for(size_t i=0; i<elements.size(); i++)
		{
			shader.SetMat4(worldMatrixLocation, worldMatrices[i]);
			assets->BindTexture(elements[i].texture);
			assets->RenderModel(elements[i].model, 1);
		}*/
		
		// render all elements
		int curModel = -1, curTexture = -1, curElements = 0;
		for(size_t i=0; i<elements.size(); i++)
		{
			int model = elements[i].model;
			int texture = elements[i].texture;
			
			if(curModel != model || i == elements.size()-1)
			{
				if(curElements > 0)
				{
					shader.SetMat4v(worldMatrixLocation, &worldMatrices[i], curElements);
					assets->BindTexture(curTexture);
					assets->RenderModel(curModel, curElements);
					curElements = 0;
				}
				
				curModel = model;
				curTexture = texture;
			}
			
			curElements++;
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
