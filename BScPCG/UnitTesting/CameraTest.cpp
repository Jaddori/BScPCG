#include "gtest\gtest.h"
#include "Camera.h"

using namespace Rendering;

TEST(CameraTest, Constructor)
{
	Camera camera;

	glm::vec3 position = camera.GetPosition();
	glm::vec3 lookAt = camera.GetLookAt();

	EXPECT_FLOAT_EQ( position.x, 0.0f );
	EXPECT_FLOAT_EQ( position.y, 0.0f );
	EXPECT_FLOAT_EQ( position.z, 0.0f );

	EXPECT_FLOAT_EQ( lookAt.x, 0.0f );
	EXPECT_FLOAT_EQ( lookAt.y, 0.0f );
	EXPECT_FLOAT_EQ( lookAt.z, 0.0f );
}