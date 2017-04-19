#include "gtest\gtest.h"
#include "Font.h"

using namespace Assets;

TEST(FontTest, Constructor)
{
	Font font;

	EXPECT_EQ(font.getHeight(), -1);
	EXPECT_EQ(font.getWidth('A'), -1);
	EXPECT_FLOAT_EQ(font.getOffset('A').x, -1.0f);
	EXPECT_FLOAT_EQ(font.getOffset('A').y, -1.0f);
	EXPECT_FLOAT_EQ(font.getUV('A').x, -1.0f);
	EXPECT_FLOAT_EQ(font.getUV('A').y, -1.0f);
}

TEST(FontTest, Load)
{
	Font font;

	ASSERT_TRUE(font.load("./assets/fonts/valid_font"));

	EXPECT_EQ(font.getHeight(), 8);
	EXPECT_EQ(font.getWidth('A'), 12);
	EXPECT_FLOAT_EQ(font.getOffset('A').x, 0.0f);
	EXPECT_FLOAT_EQ(font.getOffset('A').y, 0.0f);
	EXPECT_FLOAT_EQ(font.getUV('A').x, 1.0f);
	EXPECT_FLOAT_EQ(font.getUV('A').y, 1.0f);

	Font font2;

	EXPECT_FALSE(font2.load("./assets/fonts/invalid_font"));

	EXPECT_EQ(font.getHeight(), -1);
	EXPECT_EQ(font.getWidth('A'), -1);
	EXPECT_FLOAT_EQ(font.getOffset('A').x, -1.0f);
	EXPECT_FLOAT_EQ(font.getOffset('A').y, -1.0f);
	EXPECT_FLOAT_EQ(font.getUV('A').x, -1.0f);
	EXPECT_FLOAT_EQ(font.getUV('A').y, -1.0f);
}

TEST(FontTest, Unload)
{
	Font font;

	ASSERT_TRUE(font.load("./assets/fonts/valid_font"));

	EXPECT_EQ(font.getHeight(), 8);
	EXPECT_EQ(font.getWidth('A'), 12);
	EXPECT_FLOAT_EQ(font.getOffset('A').x, 0.0f);
	EXPECT_FLOAT_EQ(font.getOffset('A').y, 0.0f);
	EXPECT_FLOAT_EQ(font.getUV('A').x, 1.0f);
	EXPECT_FLOAT_EQ(font.getUV('A').y, 1.0f);

	font.unload();

	EXPECT_EQ(font.getHeight(), -1);
	EXPECT_EQ(font.getWidth('A'), -1);
	EXPECT_FLOAT_EQ(font.getOffset('A').x, -1.0f);
	EXPECT_FLOAT_EQ(font.getOffset('A').y, -1.0f);
	EXPECT_FLOAT_EQ(font.getUV('A').x, -1.0f);
	EXPECT_FLOAT_EQ(font.getUV('A').y, -1.0f);
}

TEST(FontTest, GetHeight)
{
	Font font;

	ASSERT_TRUE(font.load("./assets/fonts/valid_font"));
	EXPECT_EQ(font.getHeight(), 8);
}

TEST(FontTest, GetWidth)
{
	Font font;

	ASSERT_TRUE(font.load("./assets/fonts/valid_font"));
	EXPECT_EQ(font.getWidth('A'), 8);
}

TEST(FontTest, GetOffset)
{
	Font font;

	ASSERT_TRUE(font.load("./assets/fonts/valid_font"));
	EXPECT_FLOAT_EQ(font.getOffset('A').x, 8);
	EXPECT_FLOAT_EQ(font.getOffset('A').y, 8);
}

TEST(FontTest, GetUV)
{
	Font font;

	ASSERT_TRUE(font.load("./assets/fonts/valid_font"));
	EXPECT_FLOAT_EQ(font.getUV('A').x, 8);
	EXPECT_FLOAT_EQ(font.getUV('A').y, 8);
}