#pragma once

#include "BaseIncludes.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

namespace Rendering
{
	class Camera
	{
	public:
		Camera();
		~Camera();

		//void Update( float deltaTime );
		void UpdatePosition(const glm::vec3& localMovement);
		void UpdateDirection(int deltaX, int deltaY);

		void SetPosition(const glm::vec3& position);
		//void SetLookAt(const glm::vec3& lookAt);
		void SetDirection(const glm::vec3& direction);

		const glm::mat4& GetViewMatrix();
		const glm::mat4& GetProjectionMatrix() const;
		const glm::vec3& GetPosition() const;
		//const glm::vec3& GetLookAt() const;
		const glm::vec3& GetDirection() const;

	private:
		glm::vec3 position;
		glm::vec3 direction;
		
		float horizontalAngle;
		float verticalAngle;

		glm::mat4 viewMatrix;
		glm::mat4 projectionMatrix;
		
		bool viewMatrixNeedsUpdate;
	};
}
