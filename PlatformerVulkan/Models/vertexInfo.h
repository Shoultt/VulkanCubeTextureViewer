#include <vector>
#include <glm/glm.hpp>
#include <vulkan/vulkan.h>

struct Vertex
{
	glm::vec3 pos;
	glm::vec3 color;
	glm::vec2 texCoord;
};

std::vector<Vertex> vertices = {    
    { { -1.f, -1.f, -1.f}, {1.0f, 0.0f, 0.0f}, {0.f, 0.f} },
    { { -1.f, -1.f,  1.f}, {1.0f, 0.0f, 0.0f}, {1.f, 0.f} },
    { { -1.f,  1.f, -1.f}, {1.0f, 0.0f, 0.0f}, {0.f, 1.f} },
    { { -1.f,  1.f,  1.f}, {1.0f, 0.0f, 0.0f}, {1.f, 1.f} },
    { { 1.f, -1.f,  1.f}, {0.0f, 1.0f, 0.0f}, {0.f, 0.f} },
    { { 1.f, -1.f, -1.f}, {0.0f, 1.0f, 0.0f}, {1.f, 0.f} },
    { { 1.f,  1.f,  1.f}, {0.0f, 1.0f, 0.0f}, {0.f, 1.f} },
    { { 1.f,  1.f, -1.f}, {0.0f, 1.0f, 0.0f}, {1.f, 1.f} },
    { { 1.f, -1.f, -1.f}, {0.0f, 0.0f, 1.0f}, {0.f, 0.f} },
    { {-1.f, -1.f, -1.f}, {0.0f, 0.0f, 1.0f}, {1.f, 0.f} },
    { { 1.f,  1.f, -1.f}, {0.0f, 0.0f, 1.0f}, {0.f, 1.f} },
    { {-1.f,  1.f, -1.f}, {0.0f, 0.0f, 1.0f}, {1.f, 1.f} },
    { {-1.f, -1.f,  1.f}, {1.0f, 1.0f, 0.0f}, {0.f, 0.f} },
    { { 1.f, -1.f,  1.f}, {1.0f, 1.0f, 0.0f}, {1.f, 0.f} },
    { {-1.f,  1.f,  1.f}, {1.0f, 1.0f, 0.0f}, {0.f, 1.f} },
    { { 1.f,  1.f,  1.f}, {1.0f, 1.0f, 0.0f}, {1.f, 1.f} },
    { {-1.f, -1.f, -1.f}, {0.0f, 1.0f, 1.0f}, {0.f, 0.f} },
    { { 1.f, -1.f, -1.f}, {0.0f, 1.0f, 1.0f}, {1.f, 0.f} },
    { {-1.f, -1.f,  1.f}, {0.0f, 1.0f, 1.0f}, {0.f, 1.f} },
    { { 1.f, -1.f,  1.f}, {0.0f, 1.0f, 1.0f}, {1.f, 1.f} },
    { { 1.f,  1.f, -1.f}, {1.0f, 0.0f, 1.0f}, {0.f, 0.f} },
    { {-1.f,  1.f, -1.f}, {1.0f, 0.0f, 1.0f}, {1.f, 0.f} },
    { { 1.f,  1.f,  1.f}, {1.0f, 0.0f, 1.0f}, {0.f, 1.f} },
    { {-1.f,  1.f,  1.f}, {1.0f, 0.0f, 1.0f}, {1.f, 1.f} },
};

std::vector<uint16_t> indices = {
	2, 1, 0,
	2, 3, 1,
	6, 5, 4,
	6, 7, 5,
	10, 9, 8,
	10, 11, 9,
	14, 13, 12,
	14, 15, 13,
	18, 17, 16,
	18, 19, 17,
	22, 21, 20,
	22, 23, 21,	
};

glm::mat4 MVP;

static std::vector<VkVertexInputBindingDescription> getVertexBindingDescrip()
{
	std::vector<VkVertexInputBindingDescription> vertexBindinDescrips(1);
	vertexBindinDescrips[0].binding = 0;
	vertexBindinDescrips[0].stride = sizeof(Vertex);
	vertexBindinDescrips[0].inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
	return vertexBindinDescrips;
}

static std::vector<VkVertexInputAttributeDescription> getVertexAttributeDescrips()
{
	std::vector<VkVertexInputAttributeDescription> vertexAttributeDescrips(3);
	vertexAttributeDescrips[0].location = 0;
	vertexAttributeDescrips[0].binding = 0;
	vertexAttributeDescrips[0].format = VK_FORMAT_R32G32B32_SFLOAT;
	vertexAttributeDescrips[0].offset = offsetof(Vertex, pos);
	vertexAttributeDescrips[1].location = 1;
	vertexAttributeDescrips[1].binding = 0;
	vertexAttributeDescrips[1].format = VK_FORMAT_R32G32B32_SFLOAT;
	vertexAttributeDescrips[1].offset = offsetof(Vertex, color);
	vertexAttributeDescrips[2].location = 2;
	vertexAttributeDescrips[2].binding = 0;
	vertexAttributeDescrips[2].format = VK_FORMAT_R32G32_SFLOAT;
	vertexAttributeDescrips[2].offset = offsetof(Vertex, texCoord);
	return vertexAttributeDescrips;
}
