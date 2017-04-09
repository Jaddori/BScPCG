#pragma once

#include "BaseIncludes.h"
#include "Assets.h"
#include "Shader.h"
#include "Camera.h"

namespace Rendering
{
	struct RenderElement
	{
		uint16_t model;
		uint16_t texture;
		glm::vec3 position;
	};

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void Load();

		void AddElement(int model, int texture, const glm::vec3& position);
		void Render(Assets::AssetManager* assets);

		Shader* GetShader();
		Camera* GetCamera();

	private:
		Shader shader;
		Camera camera;

		std::vector<RenderElement> elements;
		std::vector<glm::mat4> worldMatrices;

		GLuint worldMatrixLocation;
		GLuint viewMatrixLocation;
		GLuint projectionMatrixLocation;
	};
}