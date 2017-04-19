#include "gtest\gtest.h"
#include "Texture.h"

using namespace Assets;

TEST(TextureTest, Constructor)
{
	Texture texture;

	EXPECT_EQ(texture.getID(), 0);
	EXPECT_EQ(texture.getWidth(), 0);
	EXPECT_EQ(texture.getHeight(), 0);
}

TEST(TextureTest, ValidLoad)
{
	Texture texture;

	EXPECT_TRUE(texture.load("./assets/textures/valid_texture.dds"));
	EXPECT_EQ(texture.getWidth(), 32);
	EXPECT_EQ(texture.getHeight(), 32);
}

TEST(TextureTest, InvalidLoad)
{
	Texture texture;

	EXPECT_FALSE(texture.load("./assets/textures/invalid_texture.dds"));
	EXPECT_EQ(texture.getID(), 0);
	EXPECT_EQ(texture.getWidth(), 0);
	EXPECT_EQ(texture.getHeight(), 0);
}

TEST(TextureTest, DoubleLoad)
{
	Texture texture;

	EXPECT_TRUE(texture.load("./assets/textures/valid_texture.dds"));
	EXPECT_EQ(texture.getWidth(), 32);
	EXPECT_EQ(texture.getHeight(), 32);

	EXPECT_TRUE(texture.load("./assets/textures/valid_texture.dds"));
	EXPECT_EQ(texture.getWidth(), 32);
	EXPECT_EQ(texture.getHeight(), 32);
}

TEST(TextureTest, Unload)
{
	Texture texture;

	ASSERT_TRUE(texture.load("./assets/textures/valid_texture.dds"));
	ASSERT_GT(texture.getHeight(), 0);

	texture.unload();
	EXPECT_EQ(texture.getID(), 0);
	EXPECT_EQ(texture.getWidth(), 0);
	EXPECT_EQ(texture.getHeight(), 0);
}

TEST(TextureTest, DoubleUnload)
{
	Texture texture;

	ASSERT_TRUE(texture.load("./assets/textures/valid_texture.dds"));
	ASSERT_GT(texture.getWidth(), 0);
	ASSERT_GT(texture.getHeight(), 0);

	texture.unload();
	EXPECT_EQ(texture.getID(), 0);
	EXPECT_EQ(texture.getWidth(), 0);
	EXPECT_EQ(texture.getHeight(), 0);

	texture.unload();
	EXPECT_EQ(texture.getID(), 0);
	EXPECT_EQ(texture.getWidth(), 0);
	EXPECT_EQ(texture.getHeight(), 0);
}