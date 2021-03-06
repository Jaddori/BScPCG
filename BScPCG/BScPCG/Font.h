#pragma once

#include "BaseIncludes.h"

namespace Assets
{
	class Font
	{
	public:
		static const int FONT_START = 32;
		static const int FONT_END = 127;
		static const int FONT_RANGE = (FONT_END-FONT_START);

		Font();
		~Font();

		bool load(const std::string& path);
		void unload();

		int getHeight() const;
		int getWidth(char letter) const;
		glm::vec2 getOffset(char letter) const;
		int getTextureSize() const;

	private:
		struct FontInfo
		{
			//uint8_t height;
			uint8_t height, shadow_x, shadow_y, padding_x, padding_y;
			uint16_t textureSize;
			uint8_t widths[FONT_RANGE];
			uint16_t xoffsets[FONT_RANGE];
			uint16_t yoffsets[FONT_RANGE];
		};

		FontInfo info;
	};
}