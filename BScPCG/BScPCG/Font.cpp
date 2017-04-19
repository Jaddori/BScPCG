#include "Font.h"

namespace Assets
{
	Font::Font()
	{
	}

	Font::~Font()
	{
	}

	bool Font::load(const std::string& path)
	{
		return false;
	}

	void Font::unload()
	{
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