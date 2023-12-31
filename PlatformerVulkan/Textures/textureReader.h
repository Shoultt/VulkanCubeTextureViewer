#pragma once
#define STB_IMAGE_IMPLEMENTATION
#include <STB/stb_image.h>

class textureReader
{
public:
	int tWidth, tHeight, tChannels;
	stbi_uc* texture;
	
	void load(const char* filename)
	{
		texture = stbi_load(filename, &tWidth, &tHeight, &tChannels, STBI_rgb_alpha);
	}

	uint32_t getTextureWidth()
	{
		return tWidth;
	}

	uint32_t getTextureHeight()
	{
		return tHeight;
	}

	void* getPicture()
	{
		return texture;
	}

	uint32_t getTextureSize()
	{
		return getTextureWidth() * getTextureHeight() * 4;
	}

	void destroy()
	{
		stbi_image_free(texture);
	}
};

class cursorIcon
{
public:
	int cWidth, cHeight, cChannels;
	stbi_uc* cursorImage;

	void load(const char* filename)
	{
		cursorImage = stbi_load(filename, &cWidth, &cHeight, &cChannels, STBI_rgb_alpha);
	}

	uint32_t getCursorWidth()
	{
		return cWidth;
	}

	uint32_t getCursorHeight()
	{
		return cHeight;
	}

	void* getPicture()
	{
		return cursorImage;
	}

	uint32_t getTextureSize()
	{
		return getCursorWidth() * getCursorHeight() * 4;
	}

	void destroy()
	{
		stbi_image_free(cursorImage);
	}
};