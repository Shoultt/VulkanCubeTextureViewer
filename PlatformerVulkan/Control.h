#pragma once
#include "initWindow.h"

float xPosCursor;
float yPosCursor;
double scroll = 0;

static void cursorPositionCallbacks(GLFWwindow* window, double xPosf, double yPosf)
{
	xPosCursor = xPosf;
	yPosCursor = yPosf;
	//if(yPosCursor > )
};

void mouseButtonCallbacks(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		std::cout << xPosCursor << " : " << yPosCursor << std::endl;
	}
}

void scrollCallbacks(GLFWwindow* window, double xoffset, double yoffset)
{
	if (scroll >= -1.5)
	{
		scroll += (yoffset / 8);
		if (scroll == -1.5)
		{
			scroll += 0.125;
		}
	}
}

void keyCallbacks(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

void control()
{
	int mouseStateRight = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
	if (mouseStateRight == GLFW_PRESS)
	{
		glfwSetCursorPosCallback(window, cursorPositionCallbacks);
	}
	else if (mouseStateRight == GLFW_RELEASE)
	{
		glfwSetCursorPosCallback(window, 0);
	}
	glfwSetKeyCallback(window, keyCallbacks);

	glfwSetMouseButtonCallback(window, mouseButtonCallbacks);
	glfwSetScrollCallback(window, scrollCallbacks);
}