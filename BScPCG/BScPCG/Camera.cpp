#include "Camera.h"

namespace Rendering
{
	static const float PI = glm::pi<float>();
	static const float EPSILON = glm::epsilon<float>();
	
	Camera::Camera()
		: position(0.0f), direction(0.0f, 0.0f, 1.0f), viewMatrixNeedsUpdate(true)
	{
	}

	Camera::~Camera()
	{
	}
	
	void Camera::UpdatePosition(const glm::vec3& localMovement)
	{
		// move backwards and forwards
		if(fabs(localMovement.z) > EPSILON)
		{
			glm::vec3 forward = glm::normalize(direction);
			position += forward * localMovement.z;
		}
		
		// move left and right
		if(fabs(localMovement.x) > EPSILON)
		{
			glm::vec3 right(sin(horizontalAngle - PI*0.5f),
							0.0f,
							cos(horizontalAngle - PI*0.5f));
			position += right * localMovement.x;
		}
		
		// move up and down
		if(fabs(localMovement.y) > EPSILON)
		{
			glm::vec3 up(0.0f, 1.0f, 0.0f);
			position += up * localMovement.y;
		}
		
		viewMatrixNeedsUpdate = true;
	}
	
	void Camera::UpdateDirection(int deltaX, int deltaY)
	{
		direction = glm::normalize(direction);
		
		horizontalAngle += (float)deltaX * 0.01f;
		verticalAngle += (float)deltaY * 0.01f;
		
		// clamp angles
		if(horizontalAngle > 2*PI)
		{
			horizontalAngle -= 2*PI;
		}
		else if(horizontalAngle < -2*PI)
		{
			horizontalAngle += 2*PI;
		}
		
		if(fabs(verticalAngle) > PI*0.5f)
		{
			verticalAngle = PI*0.5f;
		}
		
		// calculate new direction
		direction = glm::vec3(
			cos(verticalAngle) * sin(horizontalAngle),
			sin(verticalAngle),
			cos(verticalAngle) * cos(horizontalAngle)
		);
		
		viewMatrixNeedsUpdate = true;
	}
	
	void Camera::UpdateProjection(int width, int height)
	{
		projectionMatrix = glm::perspectiveFov(45.0f, (float)width, (float)height, 0.1f, 100.0f);
	}

	void Camera::SetPosition(const glm::vec3& p)
	{
		position = p;
		viewMatrixNeedsUpdate = true;
	}

	/*void Camera::SetLookAt(const glm::vec3& l)
	{
		lookAt = l;
	}*/
	
	void Camera::SetDirection(const glm::vec3& d)
	{
		direction = d;
		viewMatrixNeedsUpdate = true;
	}

	const glm::mat4& Camera::GetViewMatrix()
	{
		if(viewMatrixNeedsUpdate)
		{
			viewMatrix = glm::lookAt(position, position+direction, glm::vec3(0.0f, 1.0f, 0.0f));
			viewMatrixNeedsUpdate = false;
		}
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

	/*const glm::vec3& Camera::GetLookAt() const
	{
		return lookAt;
	}*/
	
	const glm::vec3& Camera::GetDirection() const
	{
		return direction;
	}
}
