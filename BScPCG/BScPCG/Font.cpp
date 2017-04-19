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

		info.height = 0;

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
		return info.height;
	}

	int Font::getWidth(char letter) const
	{
		assert(letter >= FONT_START && letter < FONT_END);
		return info.widths[letter];
	}

	glm::vec2 Font::getOffset(char letter) const
	{
		assert(letter >= FONT_START && letter < FONT_END);
		return glm::vec2(info.xoffsets[letter], info.yoffsets[letter]);
	}
}