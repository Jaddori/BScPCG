#include "gtest\gtest.h"
#include "Model.h"

using namespace Assets;

TEST(ModelTest, Constructor)
{
	Model model;

	EXPECT_EQ(model.GetVertexArray(), 0);
	EXPECT_EQ(model.GetVertexCount(), 0);
	EXPECT_EQ(model.GetIndexCount(), 0);
}

TEST(ModelTest, ValidLoad)
{
	Model model;

	ASSERT_TRUE(model.Load("./assets/models/valid_model.model"));
	EXPECT_GT(model.GetVertexCount(), 0);
	EXPECT_GT(model.GetIndexCount(), 0);

	EXPECT_EQ(model.GetVertexCount(), 23);
	EXPECT_EQ(model.GetIndexCount(), 36);

	model.Load("./assets/models/plane.model");
}

TEST(ModelTest, InvalidLoad)
{
	Model model;

	ASSERT_FALSE(model.Load("./assets/models/invalid_model.model"));
	EXPECT_EQ(model.GetVertexArray(), 0);
	EXPECT_EQ(model.GetIndexCount(), 0);
}

TEST(ModelTest, DoubleLoad)
{
	Model model;

	ASSERT_TRUE(model.Load("./assets/models/valid_model.model"));
	EXPECT_GT(model.GetVertexCount(), 0);
	EXPECT_GT(model.GetIndexCount(), 0);

	EXPECT_EQ(model.GetVertexCount(), 23);
	EXPECT_EQ(model.GetIndexCount(), 36);

	ASSERT_TRUE(model.Load("./assets/models/valid_model.model"));
	EXPECT_GT(model.GetVertexCount(), 0);
	EXPECT_GT(model.GetIndexCount(), 0);

	EXPECT_EQ(model.GetVertexCount(), 23);
	EXPECT_EQ(model.GetIndexCount(), 36);
}

TEST(ModelTest, Unload)
{
	Model model;

	ASSERT_TRUE(model.Load("./assets/models/valid_model.model"));
	ASSERT_GT(model.GetVertexCount(), 0);
	ASSERT_GT(model.GetIndexCount(), 0);

	model.Unload();
	EXPECT_EQ(model.GetVertexArray(), 0);
	EXPECT_EQ(model.GetIndexCount(), 0);
}

TEST(ModelTest, DoubleUnload)
{
	Model model;

	ASSERT_TRUE(model.Load("./assets/models/valid_model.model"));
	ASSERT_GT(model.GetVertexCount(), 0);
	ASSERT_GT(model.GetIndexCount(), 0);

	model.Unload();
	EXPECT_EQ(model.GetVertexArray(), 0);
	EXPECT_EQ(model.GetIndexCount(), 0);

	model.Unload();
	EXPECT_EQ(model.GetVertexArray(), 0);
	EXPECT_EQ(model.GetIndexCount(), 0);
}