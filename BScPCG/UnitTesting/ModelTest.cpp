#include "gtest\gtest.h"
#include "Model.h"

using namespace Assets;

TEST(ModelTest, Constructor)
{
	Model model;

	EXPECT_EQ( model.GetVertexArray(), 0 );
	EXPECT_EQ( model.GetVertexCount(), 0 );
	EXPECT_EQ( model.GetIndexCount(), 0 );
}

TEST(ModelTest, ValidLoad)
{
	Model model;

	model.Load( "./assets/models/valid_model.model", nullptr );
	EXPECT_GT( model.GetVertexCount(), 0 );
	EXPECT_GT( model.GetIndexCount(), 0 );

	EXPECT_EQ( model.GetVertexCount(), 23 );
	EXPECT_EQ( model.GetIndexCount(), 36 );
}

TEST(ModelTest, InvalidLoad)
{
	Model model;

	model.Load( "./assets/models/invalid_model.model", nullptr );
	EXPECT_EQ( model.GetVertexArray(), 0 );
	EXPECT_EQ( model.GetIndexCount(), 0 );
}

TEST(ModelTest, DoubleLoad)
{
	Model model;

	model.Load( "./assets/models/valid_model.model", nullptr );
	EXPECT_GT( model.GetVertexCount(), 0 );
	EXPECT_GT( model.GetIndexCount(), 0 );

	EXPECT_EQ( model.GetVertexCount(), 23 );
	EXPECT_EQ( model.GetIndexCount(), 36 );

	model.Load( "./assets/models/valid_model.model", nullptr );
	EXPECT_GT( model.GetVertexCount(), 0 );
	EXPECT_GT( model.GetIndexCount(), 0 );

	EXPECT_EQ( model.GetVertexCount(), 23 );
	EXPECT_EQ( model.GetIndexCount(), 36 );
}

TEST(ModelTest, Unload)
{
	Model model;

	model.Load( "./assets/models/valid_model.model", nullptr );
	ASSERT_GT( model.GetVertexCount(), 0 );
	ASSERT_GT( model.GetIndexCount(), 0 );

	model.Unload();
	EXPECT_EQ( model.GetVertexArray(), 0 );
	EXPECT_EQ( model.GetIndexCount(), 0 );
}

TEST(ModelTest, DoubleUnload)
{
	Model model;

	model.Load( "./assets/models/valid_model.model", nullptr );
	ASSERT_GT( model.GetVertexCount(), 0 );
	ASSERT_GT( model.GetIndexCount(), 0 );

	model.Unload();
	EXPECT_EQ( model.GetVertexArray(), 0 );
	EXPECT_EQ( model.GetIndexCount(), 0 );

	model.Unload();
	EXPECT_EQ( model.GetVertexArray(), 0 );
	EXPECT_EQ( model.GetIndexCount(), 0 );
}