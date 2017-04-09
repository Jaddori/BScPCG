#include "gtest\gtest.h"
#include "Camera.h"

using namespace Rendering;

TEST(CameraTest, Constructor)
{
	Camera camera;

	glm::vec3 position = camera.GetPosition();

	EXPECT_FLOAT_EQ( position.x, 0.0f );
	EXPECT_FLOAT_EQ( position.y, 0.0f );
	EXPECT_FLOAT_EQ( position.z, 0.0f );
}