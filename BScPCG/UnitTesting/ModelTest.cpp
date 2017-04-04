#include "gtest\gtest.h"
#include "Model.h"

using namespace Assets;

TEST(ModelTest, Constructor)
{
	Model model;

	EXPECT_EQ( model.GetVertexArray(), 0 );
	EXPECT_EQ( model.GetNumIndices(), 0 );
}

TEST(ModelTest, ValidLoad)
{
	Model model;

	model.Load( "./assets/models/valid_model.obj", nullptr );
	EXPECT_GT( model.GetVertexArray(), 0 );
	EXPECT_GT( model.GetNumIndices(), 0 );
}

TEST(ModelTest, InvalidLoad)
{
	Model model;

	model.Load( "./assets/models/invalid_model.obj", nullptr );
	EXPECT_EQ( model.GetVertexArray(), 0 );
	EXPECT_EQ( model.GetNumIndices(), 0 );
}

TEST(ModelTest, DoubleLoad)
{
	Model model;

	model.Load( "./assets/models/valid_model.obj", nullptr );
	EXPECT_GT( model.GetVertexArray(), 0 );
	EXPECT_GT( model.GetNumIndices(), 0 );

	model.Load( "./assets/models/valid_model.obj", nullptr );
	EXPECT_GT( model.GetVertexArray(), 0 );
	EXPECT_GT( model.GetNumIndices(), 0 );
}

TEST(ModelTest, Unload)
{
	Model model;

	model.Load( "./assets/models/valid_model.obj", nullptr );
	ASSERT_GT( model.GetVertexArray(), 0 );
	ASSERT_GT( model.GetNumIndices(), 0 );

	model.Unload();
	EXPECT_EQ( model.GetVertexArray(), 0 );
	EXPECT_EQ( model.GetNumIndices(), 0 );
}

TEST(ModelTest, DoubleUnload)
{
	Model model;

	model.Load( "./assets/models/valid_model.obj", nullptr );
	ASSERT_GT( model.GetVertexArray(), 0 );
	ASSERT_GT( model.GetNumIndices(), 0 );

	model.Unload();
	EXPECT_EQ( model.GetVertexArray(), 0 );
	EXPECT_EQ( model.GetNumIndices(), 0 );

	model.Unload();
	EXPECT_EQ( model.GetVertexArray(), 0 );
	EXPECT_EQ( model.GetNumIndices(), 0 );
}