#pragma once
#include <GLFW/glfw3.h>

#include "Textures/textureReader.h"

uint32_t Wwidth;
uint32_t Wheight;
GLFWwindow* window;

void createWindow()
{
	bool rat = 0;

	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);

	if (rat == 1)
	{
		Wwidth = glfwGetVideoMode(glfwGetPrimaryMonitor())->width;
		Wheight = glfwGetVideoMode(glfwGetPrimaryMonitor())->height;

		window = glfwCreateWindow(Wwidth, Wheight, "Window", glfwGetPrimaryMonitor(), nullptr);

		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	}
	else
	{
		Wwidth = 800;
		Wheight = 800;

		window = glfwCreateWindow(Wwidth, Wheight, "Window", nullptr, nullptr);
	}
}

void createCursor()
{
	cursorIcon cursorI;
	cursorI.load("Textures/cursor.png");
	stbi_uc* pixels = cursorI.cursorImage;
	memset(pixels, 0x00, sizeof(pixels));
	GLFWimage cursorImage;
	cursorImage.width = cursorI.cWidth;
	cursorImage.height = cursorI.cHeight;
	cursorImage.pixels = pixels;
	GLFWcursor* cursor = glfwCreateCursor(&cursorImage, 0, 0);
	glfwSetCursor(window, cursor);
}

