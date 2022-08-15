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
};

