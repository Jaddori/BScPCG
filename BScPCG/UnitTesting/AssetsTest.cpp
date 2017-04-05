#include "gtest\gtest.h"
#include "Assets.h"
#include "Model.h"
#include "Texture.h"

using namespace Assets;

TEST(AssetsTest, LoadValidModel)
{
	AssetManager assets;

	EXPECT_GE(assets.LoadModel("./assets/models/valid_model.model" ), 0);
}

TEST(AssetsTest, LoadInvalidModel)
{
	AssetManager assets;

	EXPECT_EQ(assets.LoadModel("./assets/models/invalid_model.model"), -1);
}

TEST(AssetsTest, LoadValidTexture)
{
	AssetManager assets;

	EXPECT_GE(assets.LoadTexture("./assets/textures/valid_texture.dds"), 0);
}

TEST(AssetsTest, LoadInvalidTexture)
{
	AssetManager assets;

	EXPECT_EQ(assets.LoadTexture("./assets/textures/invalid_texture.dds"), -1);
}