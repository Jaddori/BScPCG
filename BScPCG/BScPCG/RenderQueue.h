#pragma once

#include "glm\glm.hpp"
#include <vector>
#include "Assets.h"

namespace Rendering
{
	struct RenderElement
	{
		int key;
		glm::vec3 position;
	};

	class RenderQueue
	{
	public:
		RenderQueue();
		~RenderQueue();

		void AddElement( int model, int texture, glm::vec3 position );
		void Render( Assets::AssetManager* assets );

	private:
		std::vector<RenderElement> elements;
		std::vector<glm::mat4> worldMatrices;
	};
}