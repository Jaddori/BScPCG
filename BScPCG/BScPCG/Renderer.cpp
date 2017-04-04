#include "Renderer.h"

namespace Rendering
{
	Renderer::Renderer()
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::Render( Assets::AssetManager* assets )
	{
	}

	RenderQueue* Renderer::GetRenderQueue()
	{
		return nullptr;
	}

	Shader* Renderer::GetShader()
	{
		return nullptr;
	}

	Camera* Renderer::GetCamera()
	{
		return nullptr;
	}
}