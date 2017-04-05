#include "Camera.h"

namespace Rendering
{
	Camera::Camera()
		: position(0.0f), lookAt(0.0f)
	{
		projectionMatrix = glm::perspectiveFov(45.0f, (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT, 0.1f, 100.0f);
	}

	Camera::~Camera()
	{
	}

	void Camera::Update( float deltaTime )
	{
		viewMatrix = glm::lookAt(position, position+lookAt, glm::vec3(0.0f,1.0f,0.0f));
	}

	const glm::mat4& Camera::GetViewMatrix() const
	{
		return viewMatrix;
	}

	const glm::mat4& Camera::GetProjectionMatrix() const
	{
		return projectionMatrix;
	}

	const glm::vec3& Camera::GetPosition() const
	{
		return position;
	}

	const glm::vec3& Camera::GetLookAt() const
	{
		return lookAt;
	}
}