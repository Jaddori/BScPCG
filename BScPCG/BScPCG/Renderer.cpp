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

	void Renderer::DEBUG_Load()
	{
		glGenVertexArrays(1, &DEBUG_vao);
		glBindVertexArray(DEBUG_vao);

		glEnableVertexAttribArray(0);

		glGenBuffers(1, &DEBUG_vbo);
		glGenBuffers(1, &DEBUG_ibo);

		glBindBuffer(GL_ARRAY_BUFFER, DEBUG_vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, DEBUG_ibo);

		GLfloat vdata[] = { 0.0f, 1.0f, 1.0f, -1.0f, -1.0f, -1.0f };
		GLuint idata[] = { 0, 1, 2 };

		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*6, vdata, GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*3, idata, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat)*2, NULL);

		glBindVertexArray(0);
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

	void Renderer::DEBUG_Render()
	{
		glBindVertexArray(DEBUG_vao);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);
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