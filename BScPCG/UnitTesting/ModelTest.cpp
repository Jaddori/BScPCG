#include "gtest\gtest.h"
#include "Model.h"

using namespace Assets;

TEST(ModelTest, Constructor)
{
	Model model;

	EXPECT_EQ(model.getVertexArray(), 0);
	EXPECT_EQ(model.getVertexCount(), 0);
	EXPECT_EQ(model.getIndexCount(), 0);
}

TEST(ModelTest, ValidLoad)
{
	Model model;

	ASSERT_TRUE(model.load("./assets/models/valid_model.model"));
	EXPECT_GT(model.getVertexCount(), 0);
	EXPECT_GT(model.getIndexCount(), 0);

	EXPECT_EQ(model.getVertexCount(), 23);
	EXPECT_EQ(model.getIndexCount(), 36);

	model.load("./assets/models/plane.model");
}

TEST(ModelTest, InvalidLoad)
{
	Model model;

	ASSERT_FALSE(model.load("./assets/models/invalid_model.model"));
	EXPECT_EQ(model.getVertexArray(), 0);
	EXPECT_EQ(model.getIndexCount(), 0);
}

TEST(ModelTest, DoubleLoad)
{
	Model model;

	ASSERT_TRUE(model.load("./assets/models/valid_model.model"));
	EXPECT_GT(model.getVertexCount(), 0);
	EXPECT_GT(model.getIndexCount(), 0);

	EXPECT_EQ(model.getVertexCount(), 23);
	EXPECT_EQ(model.getIndexCount(), 36);

	ASSERT_TRUE(model.load("./assets/models/valid_model.model"));
	EXPECT_GT(model.getVertexCount(), 0);
	EXPECT_GT(model.getIndexCount(), 0);

	EXPECT_EQ(model.getVertexCount(), 23);
	EXPECT_EQ(model.getIndexCount(), 36);
}

TEST(ModelTest, Unload)
{
	Model model;

	ASSERT_TRUE(model.load("./assets/models/valid_model.model"));
	ASSERT_GT(model.getVertexCount(), 0);
	ASSERT_GT(model.getIndexCount(), 0);

	model.unload();
	EXPECT_EQ(model.getVertexArray(), 0);
	EXPECT_EQ(model.getIndexCount(), 0);
}

TEST(ModelTest, DoubleUnload)
{
	Model model;

	ASSERT_TRUE(model.load("./assets/models/valid_model.model"));
	ASSERT_GT(model.getVertexCount(), 0);
	ASSERT_GT(model.getIndexCount(), 0);

	model.unload();
	EXPECT_EQ(model.getVertexArray(), 0);
	EXPECT_EQ(model.getIndexCount(), 0);

	model.unload();
	EXPECT_EQ(model.getVertexArray(), 0);
	EXPECT_EQ(model.getIndexCount(), 0);
}