#pragma once

#include "BaseIncludes.h"
#include "Assets.h"
#include "Shader.h"
#include "Camera.h"

namespace Rendering
{
	struct RenderElement
	{
		int32_t model;
		int32_t texture;
		glm::vec3 position;
	};

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void load();

		void addElement(int model, int texture, const glm::vec3& position);
		void render(Assets::AssetManager* assets);

		Shader* getShader();
		Camera* getCamera();

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
