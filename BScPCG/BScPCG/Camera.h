#pragma once

#include "glm\glm.hpp"
#include "glm\matrix.hpp"
#include "glm\gtc\matrix_transform.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

namespace Rendering
{
	class Camera
	{
	public:
		Camera();
		~Camera();

		void Update( float deltaTime );

		const glm::mat4& GetViewMatrix() const;
		const glm::mat4& GetProjectionMatrix() const;
		const glm::vec3& GetPosition() const;
		const glm::vec3& GetLookAt() const;

	private:
		glm::vec3 position;
		glm::vec3 lookAt;

		glm::mat4 viewMatrix;
		glm::mat4 projectionMatrix;
	};
}