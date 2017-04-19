#include "Font.h"

namespace Assets
{
	Font::Font()
		: info{0}
	{
	}

	Font::~Font()
	{
	}

	bool Font::load(const std::string& path)
	{
		bool result = false;

		FILE* file = fopen(path.c_str(), "rb");
		if(file)
		{
			fread(&info, sizeof(info), 1, file);
			fclose(file);

			result = true;
		}

		return result;
	}

	void Font::unload()
	{
		info.height = 0;
	}

	int Font::getHeight() const
	{
		return 0;
	}

	int Font::getWidth(char letter) const
	{
		return 0;
	}

	glm::vec2 Font::getOffset(char letter) const
	{
		return glm::vec2(0.0f);
	}

	glm::vec2 Font::getUV(char letter) const
	{
		return glm::vec2(0.0f);
	}
}