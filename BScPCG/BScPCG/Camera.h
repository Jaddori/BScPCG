#pragma once

#include "glm\glm.hpp"

namespace Rendering
{
	class Camera
	{
	public:
		Camera();
		~Camera();

		void Update( float deltaTime );

		const glm::vec3& GetPosition() const;
		const glm::vec3& GetLookAt() const;

	private:
		glm::vec3 position;
		glm::vec3 lookAt;
	};
}