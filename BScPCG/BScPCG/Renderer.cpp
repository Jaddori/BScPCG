#include "Renderer.h"

namespace Rendering
{
	int CompareElements(const void* a, const void* b)
	{
		int akey = *(int*)a;
		int bkey = *(int*)b;

		return akey - bkey;
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

		worldMatrixLocation = shader.GetUniform("WorldMatrix");
		viewMatrixLocation = shader.GetUniform("ViewMatrix");
		projectionMatrixLocation = shader.GetUniform("ProjectionMatrix");

		camera.SetPosition(glm::vec3(0,0,-10));
		camera.SetLookAt(glm::vec3(0,0,0));
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
		for(size_t i=0; i<elements.size(); i++)
		{
			glm::translate(worldMatrices[i], elements[i].position);
		}

		// update uniforms
		camera.Update(0.0f);
		shader.Bind();
		shader.SetMat4(projectionMatrixLocation, camera.GetProjectionMatrix());
		shader.SetMat4(viewMatrixLocation, camera.GetViewMatrix());

		// render all elements
		for(size_t i=0; i<elements.size(); i++)
		{
			shader.SetMat4(worldMatrixLocation, worldMatrices[i]);
			assets->BindTexture(elements[i].texture);
			assets->RenderModel(elements[i].model, 1);
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