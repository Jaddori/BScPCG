#include "gtest\gtest.h"
#include "Texture.h"

using namespace Assets;

TEST(TextureTest, Constructor)
{
	Texture texture;

	EXPECT_EQ(texture.GetID(), 0);
	EXPECT_EQ(texture.GetWidth(), 0);
	EXPECT_EQ(texture.GetHeight(), 0);
}

TEST(TextureTest, ValidLoad)
{
	Texture texture;

	EXPECT_TRUE(texture.Load("./assets/textures/valid_texture.dds"));
	EXPECT_EQ(texture.GetWidth(), 32);
	EXPECT_EQ(texture.GetHeight(), 32);
}

TEST(TextureTest, InvalidLoad)
{
	Texture texture;

	EXPECT_FALSE(texture.Load("./assets/textures/invalid_texture.dds"));
	EXPECT_EQ(texture.GetID(), 0);
	EXPECT_EQ(texture.GetWidth(), 0);
	EXPECT_EQ(texture.GetHeight(), 0);
}

TEST(TextureTest, DoubleLoad)
{
	Texture texture;

	EXPECT_TRUE(texture.Load("./assets/textures/valid_texture.dds"));
	EXPECT_EQ(texture.GetWidth(), 32);
	EXPECT_EQ(texture.GetHeight(), 32);

	EXPECT_TRUE(texture.Load("./assets/textures/valid_texture.dds"));
	EXPECT_EQ(texture.GetWidth(), 32);
	EXPECT_EQ(texture.GetHeight(), 32);
}

TEST(TextureTest, Unload)
{
	Texture texture;

	ASSERT_TRUE(texture.Load("./assets/textures/valid_texture.dds"));
	ASSERT_GT(texture.GetHeight(), 0);

	texture.Unload();
	EXPECT_EQ(texture.GetID(), 0);
	EXPECT_EQ(texture.GetWidth(), 0);
	EXPECT_EQ(texture.GetHeight(), 0);
}

TEST(TextureTest, DoubleUnload)
{
	Texture texture;

	ASSERT_TRUE(texture.Load("./assets/textures/valid_texture.dds"));
	ASSERT_GT(texture.GetWidth(), 0);
	ASSERT_GT(texture.GetHeight(), 0);

	texture.Unload();
	EXPECT_EQ(texture.GetID(), 0);
	EXPECT_EQ(texture.GetWidth(), 0);
	EXPECT_EQ(texture.GetHeight(), 0);

	texture.Unload();
	EXPECT_EQ(texture.GetID(), 0);
	EXPECT_EQ(texture.GetWidth(), 0);
	EXPECT_EQ(texture.GetHeight(), 0);
}