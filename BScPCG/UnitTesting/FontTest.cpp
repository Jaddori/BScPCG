#include "gtest\gtest.h"
#include "Font.h"

using namespace Assets;

TEST(FontTest, Constructor)
{
	Font font;

	EXPECT_EQ(font.getHeight(), 0);
}

TEST(FontTest, Load)
{
	Font font;

	ASSERT_TRUE(font.load("./assets/fonts/helvetica_24.bin"));

	EXPECT_EQ(font.getHeight(), 30);
	EXPECT_EQ(font.getWidth('0'), 16);
	EXPECT_FLOAT_EQ(font.getOffset('0').x, 200);
	EXPECT_FLOAT_EQ(font.getOffset('0').y, 0);

	Font font2;

	EXPECT_FALSE(font2.load("./assets/fonts/invalid_font.bin"));

	EXPECT_EQ(font2.getHeight(), 0);
}

TEST(FontTest, Unload)
{
	Font font;

	ASSERT_TRUE(font.load("./assets/fonts/helvetica_24.bin"));

	EXPECT_EQ(font.getHeight(), 30);
	EXPECT_EQ(font.getWidth('0'), 16);
	EXPECT_FLOAT_EQ(font.getOffset('0').x, 200);
	EXPECT_FLOAT_EQ(font.getOffset('0').y, 0);

	font.unload();

	EXPECT_EQ(font.getHeight(), 0);
}

TEST(FontTest, GetHeight)
{
	Font font;

	ASSERT_TRUE(font.load("./assets/fonts/helvetica_24.bin"));
	EXPECT_EQ(font.getHeight(), 30);
}

TEST(FontTest, GetWidth)
{
	Font font;

	ASSERT_TRUE(font.load("./assets/fonts/helvetica_24.bin"));
	EXPECT_EQ(font.getWidth('0'), 16);
}

TEST(FontTest, GetOffset)
{
	Font font;

	ASSERT_TRUE(font.load("./assets/fonts/helvetica_24.bin"));
	EXPECT_FLOAT_EQ(font.getOffset('0').x, 200);
	EXPECT_FLOAT_EQ(font.getOffset('0').y, 0);
}