#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/noise.hpp>

#define CHUNK_W 32
#define CHUNK_H 32
#define CHUNK_D 32
#define CHUNK_VOLUME (CHUNK_W * CHUNK_H * CHUNK_D) 

struct Voxel {
	unsigned int id;
};

class Generation
{
public:
	Voxel voxel[CHUNK_VOLUME]{};

	size_t index;
	float* vertArr;
	

	Generation();

	void render();
	void drawBlock(int x, int y, int z, float u, float v, float uvsizeX, float uvsizeY, float u2, float v2, float u3, float v3, float u4, float v4, float u5, float v5, float u6, float v6);
};

