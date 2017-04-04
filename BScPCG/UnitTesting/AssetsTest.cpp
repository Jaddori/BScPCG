#include "gtest\gtest.h"
#include "Assets.h"
#include "Model.h"
#include "Texture.h"

using namespace Assets;

TEST(AssetsTest, LoadValidModel)
{
	AssetManager assets;

	EXPECT_GE(assets.Load<Model>("./assets/models/valid_model.model" ), 0);
}

TEST(AssetsTest, LoadInvalidModel)
{
	AssetManager assets;

	EXPECT_EQ(assets.Load<Model>("./assets/models/invalid_model.model"), -1);
}

TEST(AssetsTest, LoadValidTexture)
{
	AssetManager assets;

	EXPECT_GE(assets.Load<Texture>("./assets/textures/valid_texture.dds"), 0);
}

TEST(AssetsTest, LoadInvalidTexture)
{
	AssetManager assets;

	EXPECT_EQ(assets.Load<Texture>("./assets/textures/invalid_texture.dds"), -1);
}