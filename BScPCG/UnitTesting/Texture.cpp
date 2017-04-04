#include "gtest\gtest.h"
#include "Texture.h"

using namespace Assets;

TEST(TextureTest, Constructor)
{
	Texture texture;

	EXPECT_EQ( texture.GetID(), 0 );
	EXPECT_EQ( texture.GetWidth(), 0 );
	EXPECT_EQ( texture.GetHeight(), 0 );
}

TEST(TextureTest, ValidLoad)
{
	Texture texture;

	texture.Load( "./assets/textures/valid_texture.dds", nullptr );
	EXPECT_GT( texture.GetID(), 0 );
	EXPECT_EQ( texture.GetWidth(), 32 );
	EXPECT_EQ( texture.GetHeight(), 32 );
}

TEST(TextureTest, InvalidLoad)
{
	Texture texture;

	texture.Load( "./assets/textures/invalid_texture.dds", nullptr );
	EXPECT_EQ( texture.GetID(), 0 );
	EXPECT_EQ( texture.GetWidth(), 0 );
	EXPECT_EQ( texture.GetHeight(), 0 );
}

TEST(TextureTest, DoubleLoad)
{
	Texture texture;

	texture.Load( "./assets/textures/valid_texture.dds", nullptr );
	EXPECT_GT( texture.GetID(), 0 );
	EXPECT_EQ( texture.GetWidth(), 32 );
	EXPECT_EQ( texture.GetHeight(), 32 );

	texture.Load( "./assets/textures/valid_texture.dds", nullptr );
	EXPECT_GT( texture.GetID(), 0 );
	EXPECT_EQ( texture.GetWidth(), 32 );
	EXPECT_EQ( texture.GetHeight(), 32 );
}

TEST(TextureTest, Unload)
{
	Texture texture;

	texture.Load( "./assets/textures/valid_texture.dds", nullptr );
	ASSERT_GT( texture.GetWidth(), 0 );
	ASSERT_GT( texture.GetHeight(), 0 );

	texture.Unload();
	EXPECT_EQ( texture.GetID(), 0 );
	EXPECT_EQ( texture.GetWidth(), 0 );
	EXPECT_EQ( texture.GetHeight(), 0 );
}

TEST(TextureTest, DoubleUnload)
{
	Texture texture;

	texture.Load( "./assets/textures/valid_texture.dds", nullptr );
	ASSERT_GT( texture.GetWidth(), 0 );
	ASSERT_GT( texture.GetHeight(), 0 );

	texture.Unload();
	EXPECT_EQ( texture.GetID(), 0 );
	EXPECT_EQ( texture.GetWidth(), 0 );
	EXPECT_EQ( texture.GetHeight(), 0 );

	texture.Unload();
	EXPECT_EQ( texture.GetID(), 0 );
	EXPECT_EQ( texture.GetWidth(), 0 );
	EXPECT_EQ( texture.GetHeight(), 0 );
}