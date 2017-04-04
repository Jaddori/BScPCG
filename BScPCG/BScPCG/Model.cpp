#include "Model.h"

namespace Assets
{
	Model::Model()
	{
	}

	Model::~Model()
	{
	}

	bool Model::Load( const std::string& path, AssetManager* assets )
	{
		return false;
	}

	void Model::Unload()
	{
	}

	void Model::Bind()
	{
	}

	unsigned int Model::GetVertexArray() const
	{
		return 0;
	}

	int Model::GetNumIndices() const
	{
		return 0;
	}
}