#pragma once

#include "RenderQueue.h"
#include "Shader.h"
#include "Camera.h"

namespace Rendering
{
	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void Render( Assets::AssetManager* assets );

		RenderQueue* GetRenderQueue();
		Shader* GetShader();
		Camera* GetCamera();

	private:
		RenderQueue renderQueue;
		Shader shader;
		Camera camera;
	};
}